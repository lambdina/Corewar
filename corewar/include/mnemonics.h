/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef MNEMONICS_H_INCLUDED
#define MNEMONICS_H_INCLUDED

#include "istl/common_types.h"

typedef struct Operation (oper_t);
typedef struct ProgramModel (prg_t);

typedef int (*op_function_t)(prg_t *, oper_t const *);

extern const op_function_t MNEMONICS[];

extern const int OFFSET_LIVE;
extern const int OFFSET_FORK;
extern const int OFFSET_LFORK;
extern const int OFFSET_ZJMP;
extern const int OFFSET_AFF;

int mn_live(prg_t *, oper_t const *);
int mn_ld(prg_t *, oper_t const *);
int mn_st(prg_t *, oper_t const *);
int mn_add(prg_t *, oper_t const *);
int mn_sub(prg_t *, oper_t const *);
int mn_and(prg_t *, oper_t const *);
int mn_or(prg_t *, oper_t const *);
int mn_xor(prg_t *, oper_t const *);
int mn_zjmp(prg_t *, oper_t const *);
int mn_ldi(prg_t *, oper_t const *);
int mn_sti(prg_t *, oper_t const *);
int mn_fork(prg_t *, oper_t const *);
int mn_lld(prg_t *, oper_t const *);
int mn_lldi(prg_t *, oper_t const *);
int mn_lfork(prg_t *, oper_t const *);
int mn_aff(prg_t *, oper_t const *);

int ins_offset(oper_t const *);
int iins_offset(oper_t const *);
int ins_args(oper_t const *);
bool_t check_if_direct(byte_t byte);

int extract_ldi_args(prg_t *prg, oper_t const *, int vals[3]);

#endif
