#ifndef _METHODS_H_
#define _METHODS_H_

typedef double (*func_t)(double);

double root(func_t f, func_t g,  double a, double b, double eps);
double integral(func_t f, func_t g, double a, double b, double eps);

#endif //  _METHODS_H_
