/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "istl/common_types.h"
#include "istl/utility.h"
#include "istl/shared_ptr.h"

#include "p_vm.h"

int vm_write_prg(int *idx, cchar_t name, byte_t *data, uint_t size)
{
    vm_t *vm = vm_instance();
    int spacer;
    prg_t *prg = NULL;
    pair_t p;

    if (idx == NULL || data == NULL)
        return (-1);
    spacer = (MEM_SIZE - vm->total_csize) / vm->c_count;
    vm_nwrite(*idx, data, size);
    prg = prg_create(*idx, vm_unique_id(), size);
    prg_set_name(prg, name);
    list_push_back(vm->pvec, prg);
    p.it = it_back(list_end(vm->pvec));
    p.flag = shared_ptr(MB_BOOL);
    (*p.flag) = TRUE;
    map_insert(vm->fmap, prg_fid(prg), &p);
    spdestroy(p.flag);
    prg_free(&prg);
    (*idx) += spacer + size;
    return (0);
}

int vm_current_alive(void)
{
    vm_t *vm = vm_instance();
    prg_t *prg = NULL;
    static uint_t counter = 0;
    unsigned long long val;

    if (vm->cprocess == NULL)
        return (-1);
    prg = it_data(*vm->cprocess);
    if (prg == NULL)
        return (-1);
    val = prg_fid(prg);
    if (!fid_lives(val))
        vector_push(vm->fds, &val);
    counter += 1;
    if (counter >= NBR_LIVE) {
        vm->ctd -= CYCLE_DELTA;
        counter = 0;
    }
    return (0);
}

int vm_current_tick(void)
{
    vm_t *vm = vm_instance();

    return (vm->ctick);
}

void *pair_copy(void const *pair_p)
{
    pair_t const *pair = pair_p;
    pair_t *cpy = NULL;

    if (pair == NULL || !is_shared(pair->flag))
        return (NULL);
    cpy = malloc(sizeof(pair_t));
    cpy->it = pair->it;
    cpy->flag = spcopy(pair->flag);
    return (cpy);
}

void pair_destroy(void *pair_p)
{
    pair_t *pair = pair_p;

    if (pair == NULL || pair->flag == NULL)
        return;
    if (is_shared(pair->flag))
        spdestroy(pair->flag);
    else
        free(pair->flag);
}
