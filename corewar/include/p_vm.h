/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#ifndef PRIVATE_VM_H_INCLUDED
#define PRIVATE_VM_H_INCLUDED

#include "istl/common_types.h"
#include "istl/vector.h"
#include "istl/list.h"
#include "istl/iterator.h"
#include "istl/hash_table.h"
#include "op.h"
#include "vm.h"
#include "program_model.h"

extern const mdata_t MB_PAIR;

typedef struct VirtualMachine {
    char ram[MEM_SIZE];
    list_t *pvec;
    vector_t *fds;
    map_t *fmap;
    uint_t total_csize;
    uint_t c_count;
    uint_t ctick;
    iterator_t *cprocess;
    int ctd;
} (vm_t);

vm_t *vm_instance(void);
int vm_load_ram(uint_t offset);
void vm_erase_all(unsigned long long fid);
void vm_erase_absent(void);

bool_t fid_lives(unsigned long long);

#endif
