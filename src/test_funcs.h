#ifndef _TEST_FUNCS_H_
#define _TEST_FUNCS_H_

#include "methods.h"

double t_f1(double);
double t_f2(double);
double t_f3(double);
double t_f4(double);
double t_f5(double);

void test_root(char **arguments, int human, double EPS, int iter);
void test_integral(char **arguments, int human, double EPS);

func_t func_arr[5];
char* func_str_arr[5];

#endif // _TEST_FUNCS_H_