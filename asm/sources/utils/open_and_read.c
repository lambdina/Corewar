/*
** EPITECH PROJECT, 2020
** open_and_read
** File description:
** function that open a files and reads it.
*/

#include "asm.h"

char **tabgen_file(int fd)
{
    char **dest = NULL;
    char *line = NULL;
    int count = 0;

    while ((line = get_next_line(fd)) != NULL) {
        if (line[0] == COMMENT_CHAR || line[0] == '\n')
            continue;
        if (count > 1) {
            line = very_clean(line);
            if (line == NULL || line[0] == 0)
                continue;
        }
        dest = append_str(dest, line);
        free(line);
        count++;
    }
    free(line);
    return dest;
}

char **open_and_read(char *filename, bool (*err_gestion)(char *))
{
    char **buf = NULL;
    int fd = 0;
    int len = 0;

    if ((*err_gestion)(filename) == true)
        return NULL;
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return NULL;
    buf = tabgen_file(fd);
    len = my_tablen((char const **)buf);
    for (int i = 0; i < len && i < 2; i++)
        buf[i] = just_clean(buf[i]);
    close(fd);
    return buf;
}
