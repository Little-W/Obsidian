from __future__ import annotations

import json
from datetime import datetime, timezone
from pathlib import Path

from .config import AGENT_RUNTIME_POLICY_FILE, EPISODES_ROOT, FEEDBACK_LOG


VALID_VERDICTS = {"approved", "corrected", "rejected"}


def record_feedback(
    episode_id: str,
    verdict: str,
    note: str = "",
    corrected_response: str = "",
) -> dict[str, str]:
    if verdict not in VALID_VERDICTS:
        raise ValueError(f"verdict must be one of: {', '.join(sorted(VALID_VERDICTS))}")
    if verdict == "corrected" and not corrected_response.strip():
        raise ValueError("corrected feedback requires --corrected-response")
    episode_path = EPISODES_ROOT / f"{episode_id}.json"
    if not episode_path.is_file():
        raise FileNotFoundError(f"Episode not found: {episode_path}")
    episode = json.loads(episode_path.read_text(encoding="utf-8"))
    record = {
        "timestamp": datetime.now(timezone.utc).isoformat(timespec="seconds"),
        "episode_id": episode_id,
        "verdict": verdict,
        "note": note,
        "corrected_response": corrected_response,
        "episode": episode,
    }
    FEEDBACK_LOG.parent.mkdir(parents=True, exist_ok=True)
    with FEEDBACK_LOG.open("a", encoding="utf-8") as handle:
        handle.write(json.dumps(record, ensure_ascii=False) + "\n")
    return {"feedback_file": str(FEEDBACK_LOG), "episode_id": episode_id, "verdict": verdict}


def export_sft_dataset(output_file: Path) -> dict[str, int | str]:
    if not FEEDBACK_LOG.is_file():
        raise FileNotFoundError("No feedback recorded yet; evaluate agent episodes before exporting training data")
    system = AGENT_RUNTIME_POLICY_FILE.read_text(encoding="utf-8")
    accepted = 0
    skipped = 0
    output_file.parent.mkdir(parents=True, exist_ok=True)
    with FEEDBACK_LOG.open(encoding="utf-8") as source, output_file.open("w", encoding="utf-8") as destination:
        for line in source:
            record = json.loads(line)
            if record["verdict"] == "rejected":
                skipped += 1
                continue
            episode = record["episode"]
            answer = record["corrected_response"].strip() or episode["answer"].strip()
            if not answer:
                skipped += 1
                continue
            item = {
                "messages": [
                    {"role": "system", "content": system},
                    {"role": "user", "content": episode["goal"]},
                    {"role": "assistant", "content": answer},
                ],
                "metadata": {
                    "episode_id": record["episode_id"],
                    "verdict": record["verdict"],
                    "review_note": record["note"],
                },
            }
            destination.write(json.dumps(item, ensure_ascii=False) + "\n")
            accepted += 1
    return {"output_file": str(output_file), "accepted": accepted, "skipped": skipped}
