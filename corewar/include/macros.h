/*
** EPITECH PROJECT, 2020
** macros.h
** File description:
** macros used throughout the project
*/

#ifndef MACROS_H
#define MACROS_H

#ifndef UNUSED
#define UNUSED __attribute__((unused))
#endif /* UNUSED */

#ifndef FREE
#define FREE(value) \
    if ((value) != (void *)0) \
        free(value);
#endif /* FREE */

#ifndef ABS
#define ABS(value) \
    ((value) < 0) ? (value) * (-1) : (value);
#endif

#ifndef TRUE
#define TRUE (1)
#endif /* TRUE */

#ifndef FALSE
#define FALSE (!TRUE)
#endif /* FALSE */

#ifndef ISEMPTY
#define ISEMPTY(str) ((str) == (void *)0 || (str)[0] == '\0') ? TRUE : FALSE
#endif /* ISEMPTY */

#endif /* MACROS_H */
