EXERCISES := 00 01 02 03 04 05 06 07 08 09 10 11 12 13 14

all: $(EXERCISES)

$(EXERCISES):
	@make -C ex$@

clean:
	@for dir in $(EXERCISES); do \
		make -C ex$$dir clean; \
	done

fclean:
	@for dir in $(EXERCISES); do \
		make -C ex$$dir fclean; \
	done

re: fclean all

test: all
	@echo "=== Running unit tests ==="
	@fail=0; \
	for dir in $(EXERCISES); do \
		echo "Testing ex$$dir..."; \
		if [ -x ex$$dir/main ]; then \
			output=$$(./ex$$dir/main); \
		elif [ -x ex$$dir/ex$$dir ]; then \
			output=$$(./ex$$dir/ex$$dir); \
		else \
			echo "  ❌ No executable found in ex$$dir"; \
			fail=1; \
			continue; \
		fi; \
		echo "$$output" | grep -q "✅ All unit tests passed!" && \
			echo "  ✅ ex$$dir: OK" || \
			{ echo "  ❌ ex$$dir: Tests failed"; fail=1; }; \
	done; \
	if [ $$fail -eq 0 ]; then \
		echo "=== ALL TESTS PASSED ==="; \
	else \
		echo "=== SOME TESTS FAILED ==="; \
		exit 1; \
	fi

.PHONY: all $(EXERCISES) clean fclean re test
