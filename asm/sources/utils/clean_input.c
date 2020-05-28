/*
** EPITECH PROJECT, 2020
** clean_input
** File description:
** function that cleans the input.
*/

#include "asm.h"
#include "lib.h"

char *all_sep_must_be_spaces(char *str)
{
    for (int i = 0; str[i] != 0; i++)
        if (str[i] == '\t' || str[i] == '\n')
            str[i] = ' ';
    return str;
}

char *del_fore_spaces(char *str)
{
    int i = 0;

    if (str == NULL)
        return NULL;
    for (; str[i] != 0 && str[i] == ' '; i++);
    return my_strdup(&str[i]);
}

char *del_end_spaces(char *str)
{
    int len = my_strlen(str);
    int j = len - 1;

    for (; j >= 0 && str[j] == ' '; j--);
    return my_strtrunc(str, j + 1);
}

char *delete_comments(char *str)
{
    int n = my_strlen_until(str, COMMENT_CHAR);

    if (n != my_strlen(str))
        return my_strtrunc(str, n);
    return str;
}

char *only_one_sep(char *str)
{
    int len = my_strlen(str);
    int nb_cols = 0;
    char *dest = NULL;
    char quote_cast = 0;

    for (int i = 0; i < len; i++) {
        for (; i < len && str[i] == ' ' && str[i + 1] == ' '; i++);
        if (i >= len)
            break;
        dest = append_char(dest, str[i]);
    }
    return dest;
}
