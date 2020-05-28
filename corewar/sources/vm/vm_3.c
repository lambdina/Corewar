/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "istl/common_types.h"

#include "p_vm.h"

byte_t vm_read(int idx)
{
    vm_t *vm = vm_instance();

    idx %= MEM_SIZE;
    idx = (idx < 0) ? MEM_SIZE - idx : idx;
    idx %= MEM_SIZE;
    return (vm->ram[idx]);
}

void vm_write(int idx, byte_t data)
{
    vm_t *vm = vm_instance();

    idx %= MEM_SIZE;
    idx = (idx < 0) ? MEM_SIZE - idx : idx;
    idx %= MEM_SIZE;
    vm->ram[idx] = data;
}

int vm_nread(int idx, void *buff_p, uint_t size)
{
    vm_t *vm = vm_instance();
    byte_t *buff = buff_p;

    if (buff_p == NULL || size > MEM_SIZE)
        return (-1);
    for (uint_t i = 0; i < size; i++)
        buff[i] = vm_read(idx + i);
    revorder(buff, size);
    return (0);
}

int vm_nwrite(int idx, void *data_p, uint_t size)
{
    vm_t *vm = vm_instance();
    byte_t *buff = data_p;

    if (data_p == NULL || size > MEM_SIZE)
        return (-1);
    for (uint_t i = 0; i < size; i++)
        vm_write(idx + i, buff[i]);
    return (0);
}
