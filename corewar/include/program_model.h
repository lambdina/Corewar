/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef PROGRAM_MODEL_H_INCLUDED
#define PROGRAM_MODEL_H_INCLUDED

#ifndef OP_NARG
#define OP_NARG (MAX_ARGS_NUMBER * NMAX(DIR_SIZE, IND_SIZE))
#endif

#include "op.h"
#include "mnemonics.h"
#include "istl/common_types.h"

extern const mdata_t MB_PRG;

typedef struct Operation {
    byte_t code;
    byte_t cbyte;
    byte_t args[MAX_ARGS_NUMBER * NMAX(DIR_SIZE, IND_SIZE)];
} (oper_t);

typedef struct BytelessOper {
    byte_t code;
    byte_t args[1 + MAX_ARGS_NUMBER * NMAX(DIR_SIZE, IND_SIZE)];
} (boper_t);

typedef struct ProgramModel {
    unsigned long long fid;
    char *name;
    byte_t *reg;
    short int pc;
    short int org;
    uint_t size;
    bool_t carry;
    int cycle;
} (prg_t);

/* Program public methods */
byte_t *prg_get_reg(prg_t *prg, uint_t idx);

/*!
    \brief Executes current instruction, pointed
    by pc pointer and decides which operation to
    execute, and handles parameter extraction and
    passing to the corresponding implementation.
*/
int prg_step(prg_t *);
bool_t prg_carry(prg_t const *);

/* Constructors and destructors */
prg_t *prg_create(short int, int id, uint_t size);

void prg_free(prg_t **);
int prg_set_name(prg_t *, cchar_t);
void prg_destroy(void *);
void *prg_copy(void const *);
uint_t prg_size(prg_t const *);
int prg_fid(prg_t const *);
byte_t *prg_reg(prg_t *, uint_t idx);
int prg_set_reg(prg_t *, uint_t idx, int val);
void prg_set_carry(prg_t *, bool_t);

int prg_get_oper(prg_t *, oper_t *);
int prg_read_code(int fd, byte_t **buff, char *nbuff);

op_function_t get_mnemonic(oper_t const *);

int oper_arg(oper_t const *, uint_t idx, byte_t *type);
short int operi_arg(oper_t const *, uint_t idx, byte_t *type);
int arg_size(byte_t cbyte);

#endif
