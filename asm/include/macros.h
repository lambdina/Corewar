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

#endif /* MACROS_H */
