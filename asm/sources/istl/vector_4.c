/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "istl/private/p_vector.h"

vector_t *vector_from_list(list_t *list)
{
    vector_t *vec = NULL;
    itr_t it;

    if (list == NULL)
        return (NULL);
    vec = vector_create(list->type_meta);
    it = list_begin(list);
    for (; !list_final(list, it); it = it_next(it))
        vector_push(vec, it_data(it));
    return (vec);
}
