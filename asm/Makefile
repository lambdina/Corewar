##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

vpath %.c sources/$(ISTL_DIR)
vpath %.c sources/

########################
#####VARIABLES##########
########################

NAME	= asm

LIBPATH = ./lib/my/.
CC		= gcc
RM		= rm -rf
CFLAGS 	= -L. -lguillem \
		  -I./include/ \
		  -I./include/$(ISTL_DIR)/ \
		  -I./include/$(ISTL_DIR)/private/ \
		  -g3 \

OBJ 	= $(wildcard *.o)

########################
####FILES PATH##########
########################

SRC		 = ./sources/main.c \
		   ./sources/check_arg.c

SRC_UTL  = ./sources/utils/open_and_read.c \
		   ./sources/utils/append_str.c \
		   ./sources/utils/clean_input.c \
		   ./sources/utils/main_clean_input.c \
		   ./sources/utils/string_functions.c \
		   ./sources/utils/my_memset.c \
		   ./sources/utils/my_atoi.c \
		   ./sources/utils/split_in_bytes.c \
		   ./sources/utils/tabint_functions.c \
		   ./sources/utils/convert_nbase.c \
		   ./sources/utils/multiples_def_lbl.c \
		   ./sources/utils/get_labels.c

SRC_WRT  = ./sources/write/write_error.c \
		   ./sources/write/write_magic_nb.c \
		   ./sources/write/write_bytes.c \
		   ./sources/write/create_filecor.c \
		   ./sources/write/write_str.c \
		   ./sources/write/write_cor.c

SRC_HDR  = ./sources/header/prog_size.c \
		   ./sources/header/init_header.c \
		   ./sources/header/attribute_str.c \
		   ./sources/header/magic_number.c

SRC_INST = ./sources/instructions/get_params.c \
		   ./sources/instructions/get_tab_line.c \
		   ./sources/instructions/label_pttrn.c \
		   ./sources/instructions/load_prog.c \
		   ./sources/instructions/op.c \
		   ./sources/instructions/get_bsize_params.c \
		   ./sources/instructions/get_primary_args.c \
		   ./sources/instructions/get_type.c \
		   ./sources/instructions/determine_type.c \
		   ./sources/instructions/set_negative.c \
		   ./sources/instructions/get_label_pos.c \
		   ./sources/instructions/get_label_pos2.c

ISTL 		= ./sources/istl/list_1.c \
				./sources/istl/list_2.c \
				./sources/istl/list_3.c \
				./sources/istl/list_4.c \
				./sources/istl/list_5.c \
				./sources/istl/hash_table_1.c \
				./sources/istl/hash_table_2.c \
				./sources/istl/hash_table_3.c \
				./sources/istl/hash_table_4.c \
				./sources/istl/utility_1.c \
				./sources/istl/utility_2.c \
				./sources/istl/utility_3.c \
				./sources/istl/utility_4.c \
				./sources/istl/cubic_bezier.c \
				./sources/istl/iterator_1.c \
				./sources/istl/iterator_2.c \
				./sources/istl/iterator_3.c \
				./sources/istl/iterator_4.c \
				./sources/istl/common_types_1.c \
				./sources/istl/common_types_2.c \
				./sources/istl/shared_ptr.c \
				./sources/istl/weak_ptr.c \
				./sources/istl/string_1.c \
				./sources/istl/string_2.c \
				./sources/istl/string_3.c \
				./sources/istl/string_4.c \
				./sources/istl/string_5.c \
				./sources/istl/observable_1.c \
				./sources/istl/astar_1.c \
				./sources/istl/astar_2.c \
				./sources/istl/astar_3.c

TEST_SRC 	= ./tests/tests_gnl.c \
		   	  ./tests/tests_lib2.c \
		   	  ./tests/tests_lib.c

TEST_SORT 	= ./tests/tests_ \
			  ./tests/test_lib3.c \
			  ./tests/test_lib4.c \
			  ./tests/test_lib5.c \
			  ./tests/test_lib6.c \
			  ./tests/test_lib7.c \


TEST_UTL 	= ./tests/tests_utils.c

TEST_INST 	= ./tests/tests_inst.c \
			  ./tests/test_utils2.c \
			  ./tests/test_utils3.c

TEST_WRT 	= ./tests/tests_write.c \
			  ./tests/test_inst2.c

########################
#####COMPILATION########
########################

all: $(NAME)

$(NAME):
	@make --no-print-directory -C $(LIBPATH)
	@$(CC) -c $(SRC) $(SRC_UTL) $(SRC_HDR) $(SRC_INST) $(SRC_WRT)$^ $(CFLAGS)
	@mkdir -p objects
	@mv *.o objects
	@$(CC) ./objects/*.o -o $(NAME) $(CFLAGS)
	@echo "[*** COMPILATION SUCCESSFUL ***]"

clean:
	@make clean --no-print-directory -C $(LIBPATH)
	@$(RM) objects

fclean: clean
	@make fclean --no-print-directory -C $(LIBPATH)
	@$(RM) $(NAME)
	@echo "[*** CLEAN ***]"

re: fclean all


########################
#####UNIT TESTS#########
########################

tests_run:
	@make --no-print-directory -C $(LIBPATH)
	@$(CC) -c $(TEST_SRC) $(SRC_INPUT) $(TEST_UTL) $(TEST_WRT) $(TEST_INST) $(SRC_UTL) $(SRC_HDR) $(SRC_WRT) $(SRC_INST) $(SRC_INPUT)--coverage -g3 $(CFLAGS)
	@$(CC) -o unit_tests *.o -lcriterion --coverage $(CFLAGS)
	@mkdir -p objects
	@mv *.o objects
	@./unit_tests > /dev/null
	@echo "[*** TESTS OVER ***]"

tests_run_clean: tests_run
	@gcovr --exclude tests/
	@make fclean --no-print-directory -C $(LIBPATH)
	@$(RM) unit_tests
	@$(RM) *.gc* unit_tests
	@$(RM) $(NAME)
	@$(RM) objects
	@echo "[*** CLEAN SUCCESSFUL ***]"


########################
#####.PHONY#############
########################

.PHONY: all clean fclean re tests_run tests_run_clean
