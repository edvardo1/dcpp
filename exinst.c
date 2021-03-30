#include "exinst.h"

#define STACKSIZE 1024
static dc_Value stack[STACKSIZE];
static dc_Value *stackptr = stack - sizeof(dc_Value);

void dc_interpret(dc_Value a) {
	switch(a.type) {
	case INSTRUCTION :
		dc_interpret_inst(a);
		break;
	default :
		dc_push(a);
		break;
	}
}

void dc_interpret_inst(dc_Value a) {
	switch(a.value) {
	case ADD :
		dc_add();
		break;
	case PRT :
		dc_prt();
		break;
	case EXE:
		dc_exe();
	case I1X:
		dc_i1x();
		break;
	case AND :
		dc_and();
		break;
	case NOT :
		dc_not();
	case ORR :
		dc_orr();
		break;
	case XOR :
		dc_xor();
		break;
	default: 
		break;
	}
}

void dc_push(dc_Value a) {
	stackptr += sizeof(dc_Value);
	stackptr->type = a.type;
	stackptr->value = a.value;
	stackptr->arr = a.arr;
}

/* TODO
 * REWRITE ARITHMETIC INSTRUCTION IN ASSEMBLY
 */

void dc_add(void) {
	dc_Value *a = (stackptr - sizeof(dc_Value));
	dc_Value *b = (stackptr);
	if(a->type == FLOAT || b->type == FLOAT) {
		a->type = FLOAT;
		a->value = (double)((double)a->value + (double)b->value);
		stackptr -= sizeof(dc_Value);
	} else if(a->type == INTEGER && b->type == INTEGER) {
		a->value = a->value + b->value;
		stackptr -= sizeof(dc_Value);
	}
}

void dc_prt(void) {
	switch(stackptr->type) {
	case INTEGER :
		printf("%ld\n", stackptr->value);
		break;
	case FLOAT :
		printf("%f\n", (double)stackptr->value);
		break;
	default :
		CRASH("Tried to print invalid value.");
		break;
	}
}

void dc_exe(void) {
	if(stackptr->type != ARRAY) {
		CRASH("tried to execute non-array type.");
	}
	if(stackptr->value < 1 || stackptr->arr == NULL) {
		CRASH("tried to execute empty array");
	}

	dc_Value program;

	int again = 1;
	int i;
	while(again) {

		program.value = stackptr->value;
		program.arr = stackptr->arr;
		program.type = stackptr->type;
		stackptr -= sizeof(dc_Value);

		again = program.arr[program.value - 1].value == EXE;

		for(i = 0; i < (program.value - again); ++i) {
			dc_interpret(program.arr[i]);
		}
		if(again) {
			free(program.arr);
		}
	}
}

void dc_i1x(void) {
	if(stackptr->type == INTEGER && stackptr->value == 1) {
		stackptr -= sizeof(dc_Value);
		dc_exe();
	}
	stackptr -= sizeof(dc_Value);
}

void dc_and(void) {
	(stackptr - sizeof(dc_Value))->value =
		(stackptr - sizeof(dc_Value))->value & stackptr->value;
	stackptr -= sizeof(dc_Value);
}

void dc_not(void) {
	stackptr->value = ~stackptr->value;
}
void dc_orr(void) {
	(stackptr - sizeof(dc_Value))->value =
		(stackptr - sizeof(dc_Value))->value | stackptr->value;
	stackptr -= sizeof(dc_Value);
}
void dc_xor(void) {
	(stackptr - sizeof(dc_Value))->value =
		(stackptr - sizeof(dc_Value))->value ^ stackptr->value;
	stackptr -= sizeof(dc_Value);
}
