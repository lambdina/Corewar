/*
** EPITECH PROJECT, 2020
** main_clean_input
** File description:
** function that call all the cleans input functions.
*/

#include "asm.h"

char *put_spaces(char *str)
{
    int count = 0;
    char *dest = malloc(sizeof(char) * my_strlen(str) + 5);
    int j = 0;

    for (int i = 0; str[i] != 0; i++, j++) {
        if (count > 4)
            break;
        if (str[i] == ' ' && str[i + 1] == SEPARATOR_CHAR)
            i++;
        if (str[i] == SEPARATOR_CHAR && str[i + 1] != ' ') {
            count++;
            dest[j] = ' ';
            j++;
        }
        dest[j] = str[i];
    }
    dest[j] = 0;
    return dest;
}

char *just_clean(char *str)
{
    str = all_sep_must_be_spaces(str);
    str = delete_comments(str);
    str = only_one_sep(str);
    str = del_end_spaces(str);
    str = del_fore_spaces(str);
    return str;
}

char *very_clean(char *str)
{
    str = all_sep_must_be_spaces(str);
    str = put_spaces(str);
    str = delete_comments(str);
    str = only_one_sep(str);
    str = del_end_spaces(str);
    str = del_fore_spaces(str);
    return str;
}
