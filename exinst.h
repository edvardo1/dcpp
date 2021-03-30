#ifndef EXINST_H
#define EXINST_H

#include <stdio.h>
#include <stdlib.h>

#include "def.h"

void dc_interpret(dc_Value a);
void dc_interpret_inst(dc_Value a);

void dc_push(dc_Value a);

void dc_add(void);
void dc_sub(void);
void dc_mul(void);
void dc_div(void);
void dc_mod(void);
void dc_prt(void);
void dc_prc(void);
void dc_cln(void);
void dc_clr(void);
void dc_lst(void);
void dc_let(void);
void dc_gtt(void);
void dc_get(void);
void dc_eto(void);
void dc_rtr(void);
void dc_ltr(void);
void dc_exe(void);
void dc_i1x(void);
void dc_and(void);
void dc_not(void);
void dc_orr(void);
void dc_xor(void);
void dc_mar(void);
void dc_aae(void);
void dc_pas(void);

#endif /* EXINST_H */
