/*
** EPITECH PROJECT, 2020
** struct.h
** File description:
** project structs
*/

#include "lib.h"
#include "istl/utility.h"
#include "istl/list.h"
#include "istl/iterator.h"
#include "istl/common_types.h"
#include "istl/hash_table.h"
#include <stdbool.h>

#ifndef STRUCT_H
#define STRUCT_H

typedef long long int ptr_t;

typedef enum COMMENT_TYPE
{
    START, END, RANDOM, NONE, ERROR
} (comment_t);

typedef enum STATUS
{
    NA, ROOMS, TUNNELS, COMMENT, EXPECT_ERROR
} status_t;

typedef struct position_s
{
    int x;
    int y;
} position_t;

typedef struct room_s room_t;

typedef struct room_s
{
    //data
    comment_t comment_type;
    position_t pos;
    bool is_empty;
    char *room_name;
    int index;

    //pointers
    ptr_t *tunnels;
    room_t *previous;
    room_t *next;
} room_t;

room_t *room_pick(room_t *room, int id);

typedef struct debug_s
{
    bool nb_is_done;
    bool start_found;
    bool end_found;
    bool rooms_sequence_done;
    bool tunnel_sequence_done;
    bool error;
} debug_t;

typedef struct bufferization_s
{
    char **tunnels;
    comment_t comment;
} buff_t;

#ifndef READ
#define READ buffer = get_next_line(fd)
#endif

#endif /* STRUCT_H */
