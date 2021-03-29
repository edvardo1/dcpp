#ifndef EXINST_H
#define EXINST_H

#include <stdio.h>
#include <stdlib.h>

#include "def.h"

#define STACKSIZE 1024


void dc_interpret(dc_Value a);
void dc_interpret_inst(dc_Value a);

void dc_push(dc_Value a);
void dc_add();
void dc_prt();
void dc_exe();

#endif /* EXINST_H */
