#ifndef DCPP_DEF_H
#define DCPP_DEF_H

#define CRASH(error) \
do { \
	fprintf(stderr, "%s\n", error); \
	exit(1); \
} while(0)

enum TYPE { INTEGER, FLOAT, INSTRUCTION, ARRAY };

typedef struct dc_Value_s dc_Value;
struct dc_Value_s {
	enum TYPE type;
	signed long value;
	dc_Value *arr;
};
/* if (type == ARRAY) { value = array-size } */
/* if (type != ARRAY) {  arr = NULL } */


#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4
#define MOD 5
#define PRT 6
#define PRC 7
#define CLN 8
#define CLR 9

#define LST 14 /* less than */
#define LET 15 /* less than or equal to */
#define GTT 16 /* greater than */
#define GET 17 /* greater than or equal to */
#define ETO 18 /* equal to */
#define RTR 19 /* read the register */
#define LTR 20 /* load the register */
#define EXE 21       
#define I1X 22 /* execute if 1, condition, array */
#define AND 23
#define NOT 24
#define ORR 25
#define XOR 26
#define MAR 27 /* make array: size */
#define AAE 28 /* access array element: array, index */
#define PAS 29 /* push array size */  



#endif /* DCPP_DEF_H */
