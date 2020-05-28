/*
** EPITECH PROJECT, 2020
** split_in_bytes
** File description:
** function that splits in bytes an nb.
*/

#include "asm.h"
#include "lib.h"

int *split_in_bytes(int value, char nb_octet)
{
    int	byte_offset = 9 * (nb_octet - 1);
    int cur_val = 0;
    int *dest = my_memset(4, 0, sizeof(int));

    for (int i = nb_octet -1; byte_offset >= 0; i--) {
        cur_val = (value >> byte_offset) & 0xFF;
        dest[i] = cur_val;
        byte_offset -= 8;
    }
    return dest;
}
