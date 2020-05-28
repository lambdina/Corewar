/*
** EPITECH PROJECT, 2020
** prntf.c
** File description:
** mini_prntf that doesnt bufferize at a newline character - useful for debug
*/

#include "lib.h"
#include <stdlib.h>
#include <stdarg.h>

char *append_char(char *s, char c)
{
    char *result = (void *)0;

    if (s == (void *)0) {
        result = malloc(sizeof(char) * 2);
        result[0] = c;
        result[1] = '\0';
        return (result);
    } else {
        result = malloc(sizeof(char) * (my_strlen(s) + 2));
        result = my_strcpy(result, s);
        result[my_strlen(s)] = c;
        result[my_strlen(s) + 1] = '\0';
    }
    return (result);
}

static char *swtch_cs(char flag, va_list ap)
{
    char *result = (void *)0;

    switch (flag) {
        case 'c' :
            result = append_char(result, va_arg(ap, int));
            break;
        case 'i' :
            result = my_itoa(va_arg(ap, int));
            break;
        case 's' :
            result = my_strdup(va_arg(ap, char *));
            break;
        default :
            result = append_char(result, '%');
    }
    return (result);
}

void prntf(char *s, ...)
{
    va_list ap;
    char *res = (void *)0;

    if (s == (void *)0 || s[0] == '\0')
        return;
    va_start(ap, s);
    for (int i = 0; i < my_strlen(s); i++) {
        if (s[i] == '%') {
            res = my_strcat(res, swtch_cs(s[i + 1], ap));
            i += 2;
        } else res = append_char(res, s[i]);
    }
    va_end(ap);
    my_putstr(res);
    free(res);
}
