##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for lib compilation
##

NAME 	= 	libguillem.a

SRC 	=	./check_string_toolbox.c \
			./compare_string.c \
			./conversions_toolbox.c \
			./copy_toolbox.c \
			./get_len_toolbox.c \
			./copy_toolbox.c \
			./get_len_toolbox.c \
			./get_next_line.c \
			./malloc_toolbox.c \
			./misc.c \
			./modify_string.c \
			./number_toolbox.c \
			./number_toolbox.c \
			./do_op.c \
			./prntf.c \
			./tabgen.c \
			./write_toolbox.c

HEADER 	=	./lib.h

LIBPATH = 	./../../include/

all:
	@gcc -c -g3 $(SRC)
	@mkdir -p ./objects
	@mv *.o objects
	@ar rc $(NAME) ./objects/*.o
	@cp $(HEADER) $(LIBPATH)
	@cp $(NAME) ./../../.
	@echo "[*** LIB CREATED ***]"

clean:
	@rm -rf objects
	@rm -f $(NAME)

fclean: clean
	@rm -f $(LIBPATH)$(HEADER)
	@rm -f ../../$(NAME)
	@echo "[*** LIB CLEANED ***]"

re: fclean all

.PHONY: all clean fclean re
