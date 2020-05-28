/*
** EPITECH PROJECT, 2020
** lib.h
** File description:
** bguillem's C lib
*/

#ifndef LIB_H
#define LIB_H

#ifndef READ_SIZE
#define READ_SIZE (60)
#endif /* READ_SIZE */

typedef int(*ptr)(int, int);

#include <stdbool.h>

// write_toolbox.c
void my_putchar(char);
void my_putstr(char const *);
void my_puterror(char const *);
void display_tab(char const **);

// get_len_toolbox.c
int my_nblen(int);
int my_strlen(char const *);
int my_tablen(char const **);
int my_strlen_until(char *str, int sep);

// malloc_toolbox.c
char *my_strdup(char const *);
char *my_strcat(char const *, char const *);
char *my_itoa(int);

// conversions_toolbox.c
char *my_getnbr_base(int, char const *);
int my_getnbr(const char *);

// get_next_line.c
char *copy_until(char *, char, int);
char *get_next_line(int);

// tabgen.c
char **tabgen(char const *, char);

// copy_toolbox.c
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);

// misc.c
void test_if_free(void *);
void free_tab(void **);
void swap(int *, int *);
void swap_array(void **, void **);
void swapc(char *, char *);

// check_string_toolbox.c
bool is_num(const char *);
int is_in_string(char const *, char);
char *get_last_occurence_of(char *, char);
bool is_a_letter(char, bool);
bool is_alphabetic(char *s);

// number_toolbox.c
void my_putnbr(int);
void my_putnbr_base(int, char const *);

// modify_strings.c
char *set_to_lowercase(char *);
char *set_to_uppercase(char *);
char *my_revstr(char *s);

// compare_string.c
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);

// do_op.c
int do_op(int, int, char);

// prntf.c
void prntf(char *, ...);
char *append_char(char *, char);

#endif /* LIB_H */
