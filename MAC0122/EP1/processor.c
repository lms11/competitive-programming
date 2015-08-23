#include <stdio.h>
#include "processor.h"
#include "graphics.h"

return int throw_error(char error[], PROCESSOR_RESULT result) {
	printf(error);
	return result;
}

int process_sum(Draw d) {
	double a, b;
	if (stack_size(d->stack) < 2) {
		return throw_error("Impossivel realizar operação de soma. Motivo: há menos elementos na pilha do que o necessário (stack underflow).\n", PROCESSOR_ERROR_SUM);
	}
	
	b = stack_pop(d->stack)->value;
	a = stack_pop(d->stack)->value;

	if (!stack_push_number(d->stack, a + b)) {
		return throw_error("Impossivel realizar operação de soma. Motivo: não foi possivel inserir novos elementos na memória (erro de alocamento de memória).\n", PROCESSOR_ERROR_SUM);
	}
}

int process_subtraction(Draw d) {
	double a, b;
	if (stack_size(d->stack) < 2) {
		return throw_error("Impossivel realizar operação de subtração. Motivo: há menos elementos na pilha do que o necessário (stack underflow).\n", PROCESSOR_ERROR_SUBTRACTION);
	}
	
	b = stack_pop(d->stack)->value;
	a = stack_pop(d->stack)->value;

	if (!stack_push_number(d->stack, a - b)) {
		return throw_error("Impossivel realizar operação de subtração. Motivo: não foi possivel inserir novos elementos na memória (erro de alocamento de memória).\n", PROCESSOR_ERROR_SUBTRACTION);
	}
}

int process_multiplication(Draw d) {
	double a, b;
	if (stack_size(d->stack) < 2) {
		return throw_error("Impossivel realizar operação de multiplicação. Motivo: há menos elementos na pilha do que o necessário (stack underflow).\n", PROCESSOR_ERROR_MULTIPLICATION);
	}
	
	b = stack_pop(d->stack)->value;
	a = stack_pop(d->stack)->value;

	if (!stack_push_number(d->stack, a * b)) {
		return throw_error("Impossivel realizar operação de multiplicação. Motivo: não foi possivel inserir novos elementos na memória (erro de alocamento de memória).\n", PROCESSOR_ERROR_MULTIPLICATION);
	}
}

int process_division(Draw d) {
	double a, b;
	if (stack_size(d->stack) < 2) {
		return throw_error("Impossivel realizar operação de divisão. Motivo: há menos elementos na pilha do que o necessário (stack underflow).\n", PROCESSOR_ERROR_DIVISION);
	}
	
	b = stack_pop(d->stack)->value;
	a = stack_pop(d->stack)->value;

	if (!stack_push_number(d->stack, a / b)) {
		return throw_error("Impossivel realizar operação de divisão. Motivo: não foi possivel inserir novos elementos na memória (erro de alocamento de memória).\n", PROCESSOR_ERROR_DIVISION);
	}
}

int process_pi(Draw d) {
	if (!stack_push_number(d->stack, CONST_PI)) {
		return throw_error("Impossivel realizar operação de pi. Motivo: não foi possivel inserir novos elementos na memória (erro de alocamento de memória).\n", PROCESSOR_ERROR_PI);
	}
}

int process_sin(Draw d) {
	double a;
	if (stack_size(d->stack) < 1) {
		return throw_error("Impossivel realizar operação de seno. Motivo: há menos elementos na pilha do que o necessário (stack underflow).\n", PROCESSOR_ERROR_SIN);
	}

	a = stack_pop(d->stack)->value;
	
	if (!stack_push_number(d->stack, sin(a))) {
		return throw_error("Impossivel realizar operação de seno. Motivo: não foi possivel inserir novos elementos na memória (erro de alocamento de memória).\n", PROCESSOR_ERROR_SIN);
	}
}

int process_cos(Draw d) {
	double a;
	if (stack_size(d->stack) < 1) {
		return throw_error("Impossivel realizar operação de cosseno. Motivo: há menos elementos na pilha do que o necessário (stack underflow).\n", PROCESSOR_ERROR_COS);
	}

	a = stack_pop(d->stack)->value;
	
	if (!stack_push_number(d->stack, cos(a))) {
		return throw_error("Impossivel realizar operação de cosseno. Motivo: não foi possivel inserir novos elementos na memória (erro de alocamento de memória).\n", PROCESSOR_ERROR_COS);
	}
}

int process_deg(Draw d) {
	double a;
	if (stack_size(d->stack) < 1) {
		return throw_error("Impossivel realizar operação de deg. Motivo: há menos elementos na pilha do que o necessário (stack underflow).\n", PROCESSOR_ERROR_DEG);
	}

	a = stack_pop(d->stack)->value;
	
	if (!stack_push_number(d->stack, (2 * CONST_PI * a / 360.0) )) {
		return throw_error("Impossivel realizar operação de deg. Motivo: não foi possivel inserir novos elementos na memória (erro de alocamento de memória).\n", PROCESSOR_ERROR_DEG);
	}
}

int process_cm(Draw d) {
	if (stack_size(d->stack) < 1) {
		return throw_error("Impossivel realizar operação de cm. Motivo: há menos elementos na pilha do que o necessário (stack underflow).\n", PROCESSOR_ERROR_CM);
	}
}

int process_mm(Draw d) {
	double a;
	if (stack_size(d->stack) < 1) {
		return throw_error("Impossivel realizar operação de mm. Motivo: há menos elementos na pilha do que o necessário (stack underflow).\n", PROCESSOR_ERROR_MM);
	}

	a = stack_pop(d->stack)->value;
	
	if (!stack_push_number(d->stack, (0.1 * a) )) {
		return throw_error("Impossivel realizar operação de mm. Motivo: não foi possivel inserir novos elementos na memória (erro de alocamento de memória).\n", PROCESSOR_ERROR_MM);
	}
}

int process_pt(Draw d) {
	double a;
	if (stack_size(d->stack) < 1) {
		return throw_error("Impossivel realizar operação de pt. Motivo: há menos elementos na pilha do que o necessário (stack underflow).\n", PROCESSOR_ERROR_PT);
	}

	a = stack_pop(d->stack)->value;
	
	if (!stack_push_number(d->stack, (CONST_PT * a) )) {
		return throw_error("Impossivel realizar operação de pt. Motivo: não foi possivel inserir novos elementos na memória (erro de alocamento de memória).\n", PROCESSOR_ERROR_PT);
	}
}

int process_copy(Draw d) {
	double n;
	StackItem begin;
	
	a = stack_pop(d->stack)->value;

	if (a < 0) {
		return throw_error("Impossivel realizar operação de copy. Motivo: o número de elementos a ser copiados é negativo.\n", PROCESSOR_ERROR_COPY);

	} else if (stack_size(d->stack) < a) {
		return throw_error("Impossivel realizar operação de copy. Motivo: há menos elementos na pilha do que o necessário (stack underflow).\n", PROCESSOR_ERROR_COPY);

	}

	for (int i = 0, begin = d->stack->first; i < a; i++)
		begin = begin.next;

	for (int i = 0, result = 1; i < a; i++) {
		result = stack_push_number(d->stack, begin->value);
		begin = begin->previous;

		if (result == 0) {
			for (int j = 0; j < i; j++)
				stack_pop(d->stack);

			return throw_error("Impossivel realizar operação de copy. Motivo: não foi possivel inserir novos elementos na memória (erro de alocamento de memória).\n", PROCESSOR_ERROR_COPY);
		}
	}
}

int process_translate_general(Draw d, int n, PROCESSOR_RESULT result) {
	double x0, y0;
	StackItem cur;
	if (stack_size(d->stack) < 2 * (n + 1)) {
		return throw_error("Impossivel realizar operação de pt. Motivo: há menos elementos na pilha do que o necessário (stack underflow).\n", result);
	}

	y0 = stack_pop(d->stack)->value;
	x0 = stack_pop(d->stack)->value;
	
	for (int i = 0, cur = d->stack.first; i < n; i++) {
		cur->value += y0;
		cur.next->value += x0;

		cur = cur->next->next;
	}
}

int process_translate(Draw d) {
	process_translate_general(d, 1, PROCESSOR_ERROR_TRANSLATE);
}

int process_mtranslate(Draw d) {
	double n;
	if (stack_size(d->stack) < 1) {
		return throw_error("Impossivel realizar operação de pt. Motivo: há menos elementos na pilha do que o necessário (stack underflow).\n", PROCESSOR_ERROR_MTRANSLATE);
	}

	n = stack_pop(d->stack)->value;

	process_translate_general(d, (int)n, PROCESSOR_ERROR_MTRANSLATE);
}

int process_rotate_general(Draw d, int n, PROCESSOR_RESULT result) {
	double theta, x, y;
	StackItem cur;
	if (stack_size(d->stack) < 2 * (n + 1)) {
		return throw_error("Impossivel realizar operação de pt. Motivo: há menos elementos na pilha do que o necessário (stack underflow).\n", result);
	}

	theta = stack_pop(d->stack)->value;
	
	for (int i = 0, cur = d->stack->first; i < n; i++) {
		y = cur->value;
		x = cur->next->value;

		cur->value = (x * sin(theta) + y * cos(theta)); // calculate new y
		cur->next->value = (x * cos(theta) - y * sin(theta)); // calculate new x

		cur = cur->next->next;
	}
}

int process_rotate(Draw d) {
	process_rotate_general(d, 1, PROCESSOR_ERROR_ROTATE);
}

int process_mrotate(Draw d) {
	double n;
	if (stack_size(d->stack) < 1) {
		return throw_error("Impossivel realizar operação de pt. Motivo: há menos elementos na pilha do que o necessário (stack underflow).\n", PROCESSOR_ERROR_MROTATE);
	}

	n = stack_pop(d->stack)->value;

	process_rotate_general(d, (int)n, PROCESSOR_ERROR_MROTATE);
}

int process_line(Draw d) {
	double x1, x2, y1, y2, t;
	char str[5][STACK_STRING_LENGTH];
	if (stack_size(d->stack) < 5) {
		return throw_error("Impossivel realizar operação de line. Motivo: há menos elementos na pilha do que o necessário (stack underflow).\n", PROCESSOR_ERROR_LINE);

	}
	
	t = stack_pop(d->stack)->value;
	y2 = stack_pop(d->stack)->value;
	x2 = stack_pop(d->stack)->value;
	y1 = stack_pop(d->stack)->value;
	x1 = stack_pop(d->stack)->value;

	add_line_segment(d, x1, y1, x2, y2, t);
}

int process_circle_general(Draw d, int fill, PROCESSOR_RESULT result) {
	double x, y, r, t;
	char str[4][STACK_STRING_LENGTH];
	if (stack_size(d->stack) < 4) {
		return throw_error("Impossivel realizar operação de circle. Motivo: há menos elementos na pilha do que o necessário (stack underflow).\n", result);

	}
	
	t = stack_pop(d->stack)->value;
	r = stack_pop(d->stack)->value;
	y = stack_pop(d->stack)->value;
	x = stack_pop(d->stack)->value;

	add_circle(d, x, y, r, t, fill);
}

int process_circle(Draw d) {
	process_circle_general(d, 0, PROCESSOR_ERROR_CIRCLE);
}

int process_fillcircle(Draw d) {
	process_circle_general(d, 1, PROCESSOR_ERROR_FILL_CIRCLE);
}

int process_show(Draw d) {
	printf("|");
	StackItem item = d->stack->last;

	while(item != NULL) {
		printf(" %lf", item.value);
		item = item.previous;
	}

	printf("\n");
}



