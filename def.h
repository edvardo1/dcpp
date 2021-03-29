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
#define CLN 7
#define CLR 8
#define RUT 9
//#define OBS 10 /* change output base */
//#define IBS 11 /* change input base */
#define LEN 12 /* length */
#define LST 13 /* less than */
#define LET 14 /* less than or equal to */
#define GTT 15 /* greater than */
#define GET 16 /* greater than or equal to */
#define ETO 17 /* equal to */
#define RTR 18 /* read the register */
#define LTR 19 /* load the register */
#define EXE 20
#define I1X 21 /* execute if 1, condition, array */

#define AND 22
#define NOT 23
#define ORR 24
#define XOR 25

#define MAR 26 /* make array: size */
#define AAE 27 /* access array element: array, index */
#define PAS 28 /* push array size */


#endif /* DCPP_DEF_H */
