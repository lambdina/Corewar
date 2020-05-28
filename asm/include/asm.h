/*
** EPITECH PROJECT, 2020
** asm
** File description:
** header needed by asm project.
*/

#ifndef ASM_H
#define ASM_H

#include "op.h"
#include "lib.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef long long int ptr_t;

#define UNSET -37

typedef struct params
{
    int *size_per_param;
    int *type;
    int *args;
} params_t;

typedef struct func func;
struct func
{
    int cur_bsize;
    int instruction_id;
    params_t *parameters;
};

typedef enum err_type {
    SUCCESS, FAILURE, INSTRUCTION_NOT_FOUND, TOO_MUCH_PARAMS, TOO_FEW_PARAMS,
    PARAM_TYPE, LABEL_NEVER_DEFINE, LABEL_CONFLICT_DEFINE, BAD_REG_SIZE,
    WRONG_LBL_CHAR, HEADER_SIZE
} err_type_t;

typedef struct msg {
    char *err_msg;
} msg_t;

static msg_t ERR_MSG[] = {
    {NULL},
    {NULL},
    {": This line calls an unknown instruction."},
    {": Too much parameters for this instruction."},
    {": Too less parameters for this instruction."},
    {"At least one parameter has an unexpected type."},
    {": This label is called but never define."},
    {"Conflicting label definitions."},
    {": At least one parameter has a bad register size."},
    {": This line contains a wrong label char."},
    {": This header line contains a size problem."},
    {NULL}
};

// UTILS____________________________________________________________________
// open_and_read.c
char **tabgen_file(int fd);
char **open_and_read(char *filename, bool (*err_gestion)(char *));

// append_str.c
char **append_str(char **, char *);

// string_functions.c
char *my_strtrunc(char *str, int n);
char *concat(char *, char *);

// clean_input.c
char *all_sep_must_be_spaces(char *);
char *del_fore_spaces(char *str);
char *del_end_spaces(char *str);
char *delete_comments(char *str);
char *only_one_sep(char *str);

// main_clean_input.c
char *put_spaces(char *str);
char *very_clean(char *str);
char *just_clean(char *str);

// get_lbl_order.c
char **get_lbl_order(char *);

// multiples_def_lbl.c
char **get_label_def(char **);
bool tab_cmp(char **);
void multiples_def_lbl(char **);

// my_memset.c
void *my_memset(int value, int nb_cols, int size_bytes);
int my_intlen(int *);

// tabint_functions.c
int *cut_tail(int *);
int *append_int(int *, int);
int *intconcat(int *, int *);
int total(int *);
char *int_2_str(int);

// my_atoi.c
int my_atoi(char *str);

// convert_nbase.c
int atoi_base(char *, int);
int my_pow(int, int);

// split_in_bytes.c
int *split_in_bytes(int src, char nb_octets);
// _________________________________________________________________________

// WRITE____________________________________________________________________

// create_filecor.c
int create_filecor(char *filename);

// write_bytes.c
void write_single_byte(int, int);
void write_bytes(int *, int);

// write_error.c
void write_error(int, char *);

// write_magic_nb.c
void write_magic_number(int fd);

// write_str.c
void write_str(int, char *, int);

// write_core
void write_core(char *, header_t, func *, int);
int set_size(func *instruction);
int *get_prog_size(int value);

//__________________________________________________________________________


// HEADER___________________________________________________________________
// attribute_str.c
char *attribute_str(char *str, int size);

// init_header.c
bool init_name_and_comment(header_t *, char **);
bool init_header(header_t *, char **);

// prog_size.c
int char_count(char *str, char c);
int prog_size(func *, int, params_t);

// magic_number.c
int *extract_magic_nb(void);
// _________________________________________________________________________


// INSTRUCTIONS_____________________________________________________________
// label_pttrn.c
bool is_label_pttrn(char *str);

// load_prog.c
func *init_struct(char **buf);
bool load_prog(char **buf, func *instruct);

// get_params.c
params_t *get_params(char *, int);
bool no_type_func(char *);
bool is_ind_func(char *);

// label_pttrn.c
bool is_label_pttrn(char *str);

// get_tab_line.c
bool valid_label(char *);
int get_tab_line(char *);

// get_bsize_params.c
int *multi_params_func(char *line, int param_start, int *dest, int len);
int *get_bsize(char *line);

// get_primary_args.c
int *get_primary_args(char *line, int size, bool);
int *set_dir(int, int);
int *set_indirect(int, int);
int *set_reg(int);
int *set_offset_label(int, char *);

// set_negative.c
int *set_negative(int, int);

// determine_type.c
bool is_param_ind(int op_tab_line, int size_params, int i);
bool is_param_dir(int op_tab_line, int size_params, int i);
bool is_param_reg(int op_tab_line, int size_params, int i);
bool check_type(int *size_params, int op_tab_line);

// get_type.c
bool check_type(int *, int);
char *determine_type(int);
int *get_type(int *, int, int);

// get_label_pos.c
char **get_lbl_def_idx(char **);
int find_line_def(char *, char **);
func *get_label_pos(char **, func *);

// get_label_pos2.c
int get_nb_bytes_def(func *, int);
int get_nb_bytes_args(func *, int);
int *compute_byte_shift(func *, int, int);

// _________________________________________________________________________
bool check_filename_pttrn(char *filename);
int *get_progsize(int value);
#endif
