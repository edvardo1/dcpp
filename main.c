#include <stdio.h>

#include "parse.h"
#include "exinst.h"
#include "def.h"

int main() {

	dc_Value a;
	a.type = ARRAY;
	a.value = 4;
	a.arr = malloc(4 * sizeof(dc_Value));
	if(a.arr == NULL) {
		CRASH("failed to allocate memory for: a.arr.");
		return 1;
	}
	a.arr[0] = (dc_Value){ INTEGER, 1, NULL };
	a.arr[1] = (dc_Value){ INTEGER, 1, NULL };
	a.arr[2] = (dc_Value){ INSTRUCTION, ADD, NULL };
	a.arr[3] = (dc_Value){ INSTRUCTION, PRT, NULL };

	dc_push(a);
	dc_exe();
	return 0;
}
