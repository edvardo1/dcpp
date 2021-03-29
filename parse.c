#include "parse.h"

unsigned int parse(dc_Value arr, char *in) {
	arr.type = ARRAY;
	arr.arr[0] = (dc_Value){INTEGER, 1, NULL};
	arr.arr[1] = (dc_Value){INTEGER, 1, NULL};
	arr.arr[2] = (dc_Value){INSTRUCTION, 1, NULL};
	return 3;
}
