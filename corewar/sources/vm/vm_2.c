/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <sys/stat.h>
#include <fcntl.h>

#include "istl/common_types.h"

#include "p_vm.h"

static void cpu_step(void)
{
    vm_t *vm = vm_instance();
    int res;
    prg_t *prg = NULL;
    itr_t it;

    it = list_begin(vm->pvec);
    for (; !list_final(vm->pvec, it); it = it_next(it)) {
        vm->cprocess = &it;
        prg = it_data(it);
        res = prg_step(prg);
        vm->cprocess = NULL;
        if (res == -1) {
            prg = list_pull(vm->pvec, it);
            prg_free(&prg);
        }
    }
}

int vm_update_cycle(void)
{
    vm_t *vm = vm_instance();

    vm->ctick += 1;
    if (vm->ctick >= vm->ctd) {
        vm->ctick = 0;
        if (vector_len(vm->fds) < 2) {
            vm_erase_absent();
            return (-1);
        }
        else vm_erase_absent();
        if (vm->c_count < 2)
            return (-1);
    }
    return (0);
}

int vm_start(uint_t bp, uint_t offset)
{
    vm_t *vm = vm_instance();
    bool_t stop_at_bp = (bp > 0) ? TRUE : FALSE;
    uint_t count = 0;

    if (vm_load_ram(offset) != 0)
        return (-1);
    while (1) {
        cpu_step();
        if (vm_update_cycle() != 0)
            break;
        count += 1;
        if (stop_at_bp && count == bp) {
            vm_dump();
            break;
        }
    }
    vm_print_winner();
    return (0);
}

int vm_open(cchar_t filename)
{
    vm_t *vm = vm_instance();
    int fd = open(filename, O_RDONLY);
    header_t header;

    if (fd == -1)
        return (fd);
    if (read(fd, &header, sizeof(header)) != sizeof(header))
        return (-1);
    revorder(&header.prog_size, sizeof(header.prog_size));
    revorder(&header.magic, sizeof(header.magic));
    vm->total_csize += header.prog_size;
    vm->c_count += 1;
    lseek(fd, 0, SEEK_SET);
    vector_push(vm->fds, &fd);
    return (0);
}

int vm_load_ram(uint_t offset)
{
    vm_t *vm = vm_instance();
    int *fd;
    byte_t *code = NULL;
    int size;
    char pname[PROG_NAME_LENGTH + 1];

    for (uint_t i = 0; i < vector_len(vm->fds); i++, code = NULL) {
        fd = vector_pull(vm->fds, i);
        if (fd == NULL)
            continue;
        size = prg_read_code(*fd, &code, pname);
        close(*fd);
        free(fd);
        if (size == -1)
            return (-1);
        vm_write_prg(&offset, pname, code, size);
    }
    vector_free(&vm->fds);
    vm->fds = vector_create(MB_PTR);
    return (0);
}
