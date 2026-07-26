MODELS := rnn gru lstm cnn transformer

.PHONY: all test model compile check test-gcc test-clang \
	test-sanitize regress clean $(MODELS)

all: test

test: $(MODELS)

$(MODELS):
	$(MAKE) -C $@ test

model:
	@for model in $(MODELS); do \
		$(MAKE) -C $$model model || exit $$?; \
	done

compile:
	@for model in $(MODELS); do \
		$(MAKE) -C $$model compile || exit $$?; \
	done

check:
	@for model in $(MODELS); do \
		$(MAKE) -C $$model check || exit $$?; \
	done

test-gcc:
	@for model in $(MODELS); do \
		$(MAKE) -C $$model test-gcc || exit $$?; \
	done

test-clang:
	@for model in $(MODELS); do \
		$(MAKE) -C $$model test-clang || exit $$?; \
	done

test-sanitize:
	@for model in $(MODELS); do \
		$(MAKE) -C $$model test-sanitize || exit $$?; \
	done

regress:
	@for model in $(MODELS); do \
		$(MAKE) -C $$model regress || exit $$?; \
	done

clean:
	@for model in $(MODELS); do \
		$(MAKE) -C $$model clean || exit $$?; \
	done
