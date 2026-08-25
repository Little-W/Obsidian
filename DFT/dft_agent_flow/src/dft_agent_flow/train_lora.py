from __future__ import annotations

import argparse
from pathlib import Path


def _available_vram_gib(torch) -> float:
    if not torch.cuda.is_available():
        return 0.0
    return torch.cuda.mem_get_info()[0] / (1024**3)


def main() -> None:
    parser = argparse.ArgumentParser(description="QLoRA fine-tuning for reviewed DFT-agent episodes")
    parser.add_argument("--dataset", required=True, type=Path)
    parser.add_argument("--output", default=Path("adapters/qwen3-1.7b-dft"), type=Path)
    parser.add_argument("--model", default="Qwen/Qwen3-1.7B")
    parser.add_argument("--epochs", type=float, default=3.0)
    parser.add_argument("--force", action="store_true", help="Allow training with less than 5 GiB free VRAM")
    args = parser.parse_args()

    if not args.dataset.is_file():
        raise SystemExit(f"Training dataset not found: {args.dataset}")

    try:
        import torch
        from datasets import load_dataset
        from peft import LoraConfig, prepare_model_for_kbit_training
        from transformers import AutoModelForCausalLM, AutoTokenizer, BitsAndBytesConfig, TrainingArguments
        from trl import SFTTrainer
    except ImportError as exc:
        raise SystemExit("Install optional training dependencies: pip install -e '.[train]'") from exc

    free_vram = _available_vram_gib(torch)
    if free_vram < 5.0 and not args.force:
        raise SystemExit(
            f"Only {free_vram:.1f} GiB VRAM is free. Close GPU workloads, then retry; use --force only after review."
        )

    tokenizer = AutoTokenizer.from_pretrained(args.model, trust_remote_code=True)
    tokenizer.pad_token = tokenizer.pad_token or tokenizer.eos_token
    quantization = BitsAndBytesConfig(load_in_4bit=True, bnb_4bit_quant_type="nf4", bnb_4bit_compute_dtype=torch.float16)
    model = AutoModelForCausalLM.from_pretrained(
        args.model,
        quantization_config=quantization,
        device_map="auto",
        trust_remote_code=True,
    )
    model = prepare_model_for_kbit_training(model)
    dataset = load_dataset("json", data_files=str(args.dataset), split="train")
    adapter = LoraConfig(
        r=8,
        lora_alpha=16,
        lora_dropout=0.05,
        target_modules=["q_proj", "k_proj", "v_proj", "o_proj"],
        task_type="CAUSAL_LM",
    )
    train_args = TrainingArguments(
        output_dir=str(args.output),
        num_train_epochs=args.epochs,
        per_device_train_batch_size=1,
        gradient_accumulation_steps=8,
        learning_rate=2e-4,
        logging_steps=1,
        save_strategy="epoch",
        fp16=True,
        report_to="none",
    )

    def format_example(example):
        return tokenizer.apply_chat_template(
            example["messages"],
            tools=example.get("tools"),
            tokenize=False,
            add_generation_prompt=False,
        )

    kwargs = {
        "model": model,
        "args": train_args,
        "train_dataset": dataset,
        "peft_config": adapter,
        "formatting_func": format_example,
    }
    try:
        trainer = SFTTrainer(processing_class=tokenizer, **kwargs)
    except TypeError:  # Compatible with older TRL releases.
        trainer = SFTTrainer(tokenizer=tokenizer, **kwargs)
    trainer.train()
    trainer.save_model(str(args.output))
    tokenizer.save_pretrained(str(args.output))


if __name__ == "__main__":
    main()
