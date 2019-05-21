#ifndef _TEST_FUNCS_H_
#define _TEST_FUNCS_H_

#include "methods.h"

/// Тестовые функции.
double t_f1(double);
double t_f2(double);
double t_f3(double);
double t_f4(double);
double t_f5(double);

/// Выводит на консоль результаты тестирования метода нахождения
/// точек пересечения.
/// Если human, то выводит в человеко-читаемом формате.
/// Если iter, то выводит количесто итераций до нахождения ответа.
void test_root(char **arguments, int human, double EPS, int iter);

/// Выводит на консоль результаты тестирования метода интегрирования.
/// Если human, то выводит в человеко-читаемом формате.
void test_integral(char **arguments, int human, double EPS);

func_t func_arr[5];         // Массив указателей на тестовые функции.
char* func_str_arr[5];      // Массив формул тестовый функций.

#endif // _TEST_FUNCS_H_