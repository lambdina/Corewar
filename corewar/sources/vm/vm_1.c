/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "istl/common_types.h"

#include "p_vm.h"

#include "vm_static_1.c"

const mdata_t MB_PAIR = {
    .copy = pair_copy,
    .destroy = pair_destroy,
    .data_size = sizeof(pair_t)
};

bool_t is_bendian(void)
{
    int val = 0x0001;
    char *b = (char *)&val;

    return (b[0] ? FALSE : TRUE);
}

void revorder(void *data_p, size_t size)
{
    char *data = data_p;

    if (data == NULL || size < 2)
        return;
    size -= 1;
    for (int i = 0; i < (size / 2 + 1); i++) {
        data[i] ^= data[size - i];
        data[size - i] ^= data[i];
        data[i] ^= data[size - i];
    }
}

vm_t *vm_instance(void)
{
    static vm_t vm;
    static bool_t init = FALSE;

    if (init != TRUE) {
        for (int i = 0; i < MEM_SIZE; i++)
            vm.ram[i] = 0x0;
        vm.pvec = list_create(MB_SPTR);
        vm.fds = vector_create(MB_INT);
        vm.fmap = map_create(10, MB_PAIR);
        vm.total_csize = 0;
        vm.c_count = 0;
        vm.ctick = 0;
        vm.ctd = CYCLE_TO_DIE;
        init = TRUE;
    }
    return (&vm);
}

void vm_free(void)
{
    vm_t *vm = vm_instance();

    list_free(&vm->pvec);
    vector_free(&vm->fds);
    map_free(&vm->fmap);
}

int vm_unique_id(void)
{
    static int id = 734;

    return (id++);
}
