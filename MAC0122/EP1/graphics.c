#include <stdio.h>
#include <string.h>
#include <math.h>
#include "graphics.h"
#include "stack.h"
#include "process.h"

/*
	Definitions of structs
*/
typedef struct {
	double x, y;
	double radius, thickness;
	Circle *next, *previous;

} Circle;

typedef struct {
	double x1, y1, x2, y2;
	double thickness;
	LineSegment *next, *previous;

} LineSegment;

typedef struct {
	Stack stack;
	Circle circle;
	LineSegment lineSegment;

} *Drawing;


/*
	Implementation
*/

Drawing create_drawing() {
	Drawing d = malloc(sizeof(Drawing));
	
	// Init & setup stack
	stack_init(d->stack);
	d->stack->push_delegate_func = &process;
	d->stack->push_delegate_obj = d;

	return d;
}

void destroy_drawing(Drawing D) {
	
}

int add_line_segment(Drawing D, double x1, double y1, double x2, double y2, double thickness) {

}

int add_circle(Drawing D, double x, double y, double r, double thickness, int filled) {

}

int save_pgm(Drawing D, int pix_per_unit, int sample_type, int sample_size, FILE *outfile) {

}

int process(Draw d) {
	double a;
	int res;
	StackItem item = stack_pop(d->stack);

	/* 
		If the string is a actually a number, then put it back to the stack as a number. 
		Note that "stack_push_number" won't call delegate. Therefore, we won't get stuck in a loop trying to process it.
	*/
	if (sscanf(item->string, "%lf", &a)) {
		stack_push_number(d->stack, a);
		return PROCESSOR_SUCCESS;
	}

	// Look for which operator it is and then process it
	for (int i = 0; i < N_OPS_AVAILABLE; i++) {
		if (strcmp(item->string, OPS_AVAILABLE[i])) {
			switch (i) {
				case 0:
					res = process_sum(d);
					break;
				case 1:
					res = process_subtraction(d);
					break;
				case 2:
					res = process_multiplication(d);
					break;
				case 3:
					res = process_division(d);
					break;
				case 4:
					res = process_pi(d);
					break;
				case 5:
					res = process_sin(d);
					break;
				case 6:
					res = process_cos(d);
					break;
				case 7:
					res = process_deg(d);
					break;
				case 8:
					res = process_cm(d);
					break;
				case 9:
					res = process_mm(d);
					break;
				case 10:
					res = process_pt(d);
					break;
				case 11:
					res = process_copy(d);
					break;
				case 12:
					res = process_translate(d);
					break;
				case 13:
					res = process_mtranslate(d);
					break;
				case 14:
					res = process_rotate(d);
					break;
				case 15:
					res = process_mrotate(d);
					break;
				case 16:
					res = process_line(d);
					break;
				case 17:
					res = process_circle(d);
					break;
				case 18:
					res = process_fillcircle(d);
					break;
				case 19:
					res = process_show(d);
					break;
				default:
					res = throw_error("Operação ilegal.\n", PROCESSOR_ERROR_ILEGAL_OP);
					break;
			}

			break;
		}
	}

	free(item->string);
	free(item);
	return res;
}

