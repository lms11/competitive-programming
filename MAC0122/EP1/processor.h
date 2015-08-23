/*
  processor.h

  A simple graphics library.
*/

#ifndef __PROCESSOR_H__
#define __PROCESSOR_H__

/*
  Possible results
*/
enum PROCESSOR_RESULT {
  PROCESSOR_SUCCESS = 400,
  PROCESSOR_ERROR_UNKNOWN,
  PROCESSOR_ERROR_ILEGAL_OP,
  PROCESSOR_ERROR_SUM,
  PROCESSOR_ERROR_SUBTRACTION,
  PROCESSOR_ERROR_MULTIPLICATION,
  PROCESSOR_ERROR_DIVISION,
  PROCESSOR_ERROR_PI,
  PROCESSOR_ERROR_SIN,
  PROCESSOR_ERROR_COS,
  PROCESSOR_ERROR_DEG,
  PROCESSOR_ERROR_CM,
  PROCESSOR_ERROR_MM,
  PROCESSOR_ERROR_PT,
  PROCESSOR_ERROR_COPY,
  PROCESSOR_ERROR_TRANSLATE,
  PROCESSOR_ERROR_MTRANSLATE,
  PROCESSOR_ERROR_ROTATE,
  PROCESSOR_ERROR_MROTATE,
  PROCESSOR_ERROR_LINE,
  PROCESSOR_ERROR_CIRCLE,
  PROCESSOR_ERROR_FILL_CIRCLE,
  PROCESSOR_ERROR_SHOW
};

/*
  AVAILABLE OPERATIONS
*/
#define N_OPS_AVAILABLE   20
#define N_OPS_LENGTH    15
static const char OPS_AVAILABLE[N_OPS_AVAILABLE][N_OPS_LENGTH] = {
  "+", "-", "*", "/", "pi", 
  "sin", "cos", "deg", "cm", "mm", 
  "pt", "copy", "translate", "mtranslate", "rotate", 
  "mrotate", "line", "circle", "fillcircle", "show"
}

/*
  Constants
*/
#define CONST_PI      3.14159265358979
#define CONST_PT      0.03527


/*
  Throw an error to user's output and return error code
*/
int throw_error(char error[], PROCESSOR_RESULT result);

/*
  Processors
*/
int process(Draw d);
int process_sum(Draw d);
int process_subtraction(Draw d);
int process_multiplication(Draw d);
int process_division(Draw d);
int process_pi(Draw d);
int process_sin(Draw d);
int process_cos(Draw d);
int process_deg(Draw d);
int process_cm(Draw d);
int process_mm(Draw d);
int process_pt(Draw d);
int process_copy(Draw d);
int process_translate_general(Draw d, int n, PROCESSOR_RESULT possibleError);
int process_translate(Draw d);
int process_mtranslate(Draw d);
int process_rotate_general(Draw d, int n);
int process_rotate(Draw d);
int process_mrotate(Draw d);
int process_line(Draw d);
int process_circle_general(Draw d, int fill, PROCESSOR_RESULT possibleError);
int process_circle(Draw d);
int process_fillcircle(Draw d);
int process_show(Draw d);


#endif