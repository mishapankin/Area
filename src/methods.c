#include "methods.h"

#include <math.h>
#include <stdio.h>

#define SUBSTRACT_F(x) (f((x)) - g((x)))

double root(func_t f, func_t g, double a, double b, double eps) {
	double	v_a = SUBSTRACT_F(a),
			v_b = SUBSTRACT_F(b);
	if (fabs(v_a) < eps) { return v_a; }
	if (fabs(v_b) < eps) { return v_b; }
	if (v_a * v_b > 0) { return NAN; }
	while (1) {
		double	x = (v_a * a - v_b * b) / (v_a - v_b),
				v_x = SUBSTRACT_F(x);

		if (fabs(v_x) < eps) {
			return x;
		}
		if (v_x * v_a > 0) {
			a = x;
			v_a = v_x;
		} else {
			b = x;
			v_b = v_x;
		}
	}
	return NAN;
}

double integral(func_t f, func_t g, double a, double b, double eps) {
	if (fabs(a - b) < eps) { return NAN; }
	if (b < a) {
		double t = a;
		a = b;
		b = t;
	}

	int n = (b - a) / eps + 1;
	eps = (b - a) / n;

	double result = 0.0;
	for (int i = 0; i < n; ++i) {
		result += eps * SUBSTRACT_F(a + i * eps + 0.5 * eps);
	}

	return result;
}
