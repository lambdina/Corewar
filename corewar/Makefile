##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

include sources/Makefile.istl_sources

vpath %.c sources/$(ISTL_DIR)
vpath %.c sources/
vpath %.c sources/input_handling
vpath %.c sources/mnemonics
vpath %.c sources/vm

########################
#### VARIABLES #########
########################

NAME	= corewar

LIBPATH = ./lib/my/.

CC		= gcc

RM		= rm -rf

LINK_FLAG = -L. -lguillem

CFLAGS 	= -I./include/ \
		  -I./include/$(ISTL_DIR)/ \
		  -I./include/$(ISTL_DIR)/private/ \
		  -g3

########################
### FILES PATH #########
########################

SRC		 =	main.c

VM_MODULE	=	program_1.c \
			program_2.c \
			program_3.c \
			program_4.c \
			mnemonics_1.c \
			mnemonics_2.c \
			mnemonics_3.c \
			mnemonics_4.c \
			mnemonics_5.c \
			op.c \
			vm_1.c \
			vm_2.c \
			vm_3.c \
			vm_4.c \
			vm_5.c \
			vm_6.c

SRC_INPUT	=	my_getopt.c \
			functions_arg_handling.c \
			convert_base.c

COMBINED	=	$(SRC) \
			$(SRC_INPUT) \
			$(VM_MODULE) \
			$(ISTL_MODULE)

TEST_SRC 	= ./tests/tests_gnl.c \
		   	  ./tests/tests_lib2.c \
		   	  ./tests/tests_lib.c \
			  ./tests/tests_my_getopt.c

LIB  		= libguillem.a

OBJECT_DIR 	= ./objects

OBJ 	 	= $(patsubst %.c, $(OBJECT_DIR)/%.o, $(COMBINED))

########################
#### COMPILATION #######
########################

all: directories $(LIB) $(NAME)

$(OBJECT_DIR):
	@mkdir -p $@

directories: | $(OBJECT_DIR)

$(OBJECT_DIR)/%.o : %.c
	@gcc -o $@ -c $< $(CFLAGS)
	@echo -e "\e[35mCompiling $@\e[39m"


$(LIB):
	@make --no-print-directory -C $(LIBPATH)

$(NAME): $(OBJ)
	@gcc -o $(NAME) $^ $(LINK_FLAG)
	@echo -e "\e[34m[*** COMPILATION SUCCESSFUL ***]\e[39m"

clean:
	@make clean --no-print-directory -C $(LIBPATH)
	@$(RM) objects

fclean: clean
	@make fclean --no-print-directory -C $(LIBPATH)
	@$(RM) $(NAME)
	@echo -e "\e[34m[*** CLEAN ***]\e[39m"

re: fclean all

########################
#### UNIT TESTS ########
########################

tests_run:
	@make --no-print-directory -C $(LIBPATH)
	@$(CC) -c $(TEST_SRC) $(SRC_INPUT) --coverage -g3 $(CFLAGS)
	@$(CC) -o unit_tests *.o -lcriterion --coverage $(CFLAGS)
	@mkdir -p objects
	@mv *.o objects
	@./unit_tests > /dev/null
	@echo -e "\e[34m[*** TESTS OVER ***]\e[39m"

tests_run_clean: tests_run
	@gcovr --exclude tests/
	@make fclean --no-print-directory -C $(LIBPATH)
	@$(RM) unit_tests
	@$(RM) *.gc* unit_tests
	@$(RM) $(NAME)
	@$(RM) objects
	@echo -e "\e[34m[*** CLEAN SUCCESSFUL ***]\e[39m"


########################
#### .PHONY ############
########################

.PHONY: all clean fclean re tests_run tests_run_clean
