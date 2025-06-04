EXERCISES := 00 01 02 03 04 05 06 07
# EXERCISES += 01 02 03 04 05 06 07 08 09 10 11 12 13


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


.PHONY: all $(EXERCISES) clean