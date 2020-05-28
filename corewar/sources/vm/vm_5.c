/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "istl/common_types.h"
#include "istl/utility.h"
#include "istl/shared_ptr.h"
#include "lib.h"

#include "p_vm.h"

void vm_erase_all(unsigned long long fid)
{
    vm_t *vm = vm_instance();
    list_t *its;
    itr_t *prg;
    itr_t it;

    its = map_get_all(vm->fmap, fid);
    it = list_begin(its);
    for (; !list_final(its, it); it = it_next(it)) {
        prg = it_data(it);
        if (prg == NULL)
            continue;
        spdestroy(list_pull(vm->pvec, *prg));
    }
    list_free(&its);
}

int vm_add_prg(prg_t *prg)
{
    vm_t *vm = vm_instance();

    if (prg == NULL)
        return (-1);
    list_push_back(vm->pvec, prg);
}

void vm_dump(void)
{
    vm_t *vm = vm_instance();
    char *n = NULL;

    for (uint_t i = 0; i < MEM_SIZE; i++) {
        n = my_getnbr_base((int)vm_read(i), "0123456789ABCDEF");
        if (my_strlen(n) < 2) {
            write(1, "0", 1);
            write(1, n, 1);
        } else write(1, n, 2);
        if ((i + 1) % 32 == 0)
            write(1, "\n", 1);
        free(n);
    }
}

bool_t fid_lives(unsigned long long id)
{
    vm_t *vm = vm_instance();
    void const *ptr = NULL;
    unsigned long long val;

    for (int i = 0; i < vector_len(vm->fds); i++) {
        ptr = vector_cget(vm->fds, i);
        if (ptr == NULL)
            continue;
        val = *(unsigned long long *)ptr;
        if (id == val)
            return (TRUE);
    }
    return (FALSE);
}

void vm_erase_absent(void)
{
    vm_t *vm = vm_instance();
    prg_t *prg = NULL;
    itr_t it;

    it = list_begin(vm->pvec);
    for (; !list_final(vm->pvec, it); it = it_next(it)) {
        prg = it_data(it);
        if (fid_lives(prg_fid(prg)) == FALSE) {
            prg = list_pull(vm->pvec, it);
            prg_free(&prg);
            continue;
        }
    }
    spdestroy(vm->fds);
    vm->fds = vector_create(MB_PTR);
}
