##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

.PHONY: all re fclean clean tests_run tests_run_clean

all:
	@make --no-print-directory -C ./asm/
	@make --no-print-directory -C ./corewar/

clean:
	@make --no-print-directory clean -C ./asm/
	@make --no-print-directory clean -C ./corewar/

re:
	@make --no-print-directory re -C ./asm/
	@make --no-print-directory re -C ./corewar/

fclean:
	@make --no-print-directory fclean -C ./asm/
	@make --no-print-directory fclean -C ./corewar/

tests_run:
	@make --no-print-directory tests_run -C ./asm
	@make --no-print-directory tests_run -C ./corewar

tests_run_clean:
	@make --no-print-directory tests_run_clean -C ./asm/
	@make --no-print-directory tests_run_clean -C ./corewar/
