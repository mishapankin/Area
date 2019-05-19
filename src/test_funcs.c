#include "test_funcs.h"

#include <math.h>
#include <stdio.h>

#include "methods.h"

func_t func_arr[5] = {t_f1, t_f2, t_f3, t_f4, t_f5};

char* func_str_arr[5] = {
    "f1(x) = 0",
    "f2(x) = x * x",
    "f3(x) = x + 1",
    "f4(x) = sin(x)",
    "f5(x) = 1 / x"
};

double t_f1(double x) {
	return 0.0;
}

double t_f2(double x) {
	return x * x;
}

double t_f3(double x) {
	return x + 1;
}

double t_f4(double x) {
	return sin(x);
}

double t_f5(double x) {
	return 1.0 / x;
}


void test_root(char **arguments, int human, double EPS) {
    int num1, num2, it;
    double a, b;
    sscanf(arguments[0], "%d", &num1);
    sscanf(arguments[1], "%d", &num2);
    sscanf(arguments[2], "%lf", &a);
    sscanf(arguments[3], "%lf", &b);
    --num1; --num2;
    double x = root(func_arr[num1], func_arr[num2], a, b, EPS, &it);
    if (human) {
        printf("%s\n", func_str_arr[num1]);
        printf("%s\n", func_str_arr[num2]);
        printf("a: %lf\n", a);
        printf("b: %lf\n", b);
        printf("Root: ");
    }
    printf("%lf\n", x);
}


void test_integral(char **arguments, int human, double EPS) {
    int num, it;
    double a, b;
    sscanf(arguments[0], "%d", &num);
    sscanf(arguments[1], "%lf", &a);
    sscanf(arguments[2], "%lf", &b);
    --num;
    double area = integral(func_arr[num], a, b, EPS);
    if (human) {
        printf("%s\n", func_str_arr[num]);
        printf("a: %lf\n", a);
        printf("b: %lf\n", b);
        printf("Integral: ");
    }
    printf("%lf\n", area);
}