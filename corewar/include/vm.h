/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#ifndef VM_H_INCLUDED
#define VM_H_INCLUDED

#include <stdlib.h>
#include <unistd.h>
#include "istl/common_types.h"
#include "istl/iterator.h"
#include "program_model.h"

extern const mdata_t MB_PAIR;

typedef struct Pair {
    itr_t it;
    bool_t *flag;
} (pair_t);

typedef struct VirtualMachine (vm_t);

bool_t is_bendian(void);
void revorder(void *data, size_t size);

int vm_start(uint_t bp, uint_t offset);
int vm_open(cchar_t filename);
void vm_free(void);
int vm_unique_id(void);
byte_t vm_read(int idx);
void vm_write(int idx, byte_t data);
int vm_nread(int idx, void *buff, uint_t size);
int vm_nwrite(int idx, void *data, uint_t size);
int vm_write_prg(int *idx, cchar_t name, byte_t *data, uint_t size);
int vm_current_alive(void);
int vm_current_tick(void);
void *vm_alloc(void);
int vm_update_cycle(void);
int vm_prg_cleanup(void);
int vm_add_prg(prg_t *);
void vm_dump(void);
void vm_print_winner(void);

void *pair_copy(void const *);
void pair_destroy(void *);

#endif
