/*
** EPITECH PROJECT, 2020
** convert_base.c
** File description:
** converts a number in char * to another number in char *
*/

#include "common_types.h"
#include "macros.h"
#include "lib.h"

static bool_t check_if_negative(char **nb)
{
    if (ISEMPTY(*nb) == TRUE)
        return (false);
    if (*nb[0] == '-') {
        *nb = my_strdup(&(*nb[1]));
        return (TRUE);
    }
    return (FALSE);
}

char *convert_base(char *number, cchar_t base_from, cchar_t base_to)
{
    char *result = (void *)0;
    int base_to_len = my_strlen(base_to);
    bool_t is_negative = check_if_negative(&number);
    int carry = 0;
    int temp = 0;

    if (ISEMPTY(number) == TRUE || ISEMPTY(base_from) == TRUE ||
    ISEMPTY(base_to) == TRUE)
        return ((void *)0);
    for (int i = 0; number[i] != '\0'; i++) {
        temp = is_in_string(base_from, number[i]);
        temp += carry;
        if (temp > base_to_len) {
            carry = temp - base_to_len;
            result = append_char(result, base_to[base_to_len]);
        } else {
            carry = 0;
            result = append_char(result, base_to[temp]);
        }
    }
    result = carry == 0 ? result : append_char(result, base_to[carry]);
    return (is_negative == TRUE ? my_strcat("-", result) : result);
}