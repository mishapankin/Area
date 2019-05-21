#include "methods.h"

#include <math.h>
#include <stdio.h>

double root(func_t f, func_t g, double a, double b, double eps, int *it_count) {
	double	v_a = f(a) - g(a),
			v_b = f(b) - g(b);
	if (fabs(v_a) < eps) { return v_a; }
	if (fabs(v_b) < eps) { return v_b; }
	if (v_a * v_b > 0) { return NAN; }
	*it_count = 0;
	while (1) {
		++(*it_count);
		double	x = (v_a * a - v_b * b) / (v_a - v_b),
				v_x = f(x) - g(x);

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

double integral(func_t f, double a, double b, double eps) {
	if (fabs(a - b) < eps) { return 0.0; }
	if (b < a) {
		double t = a;
		a = b;
		b = t;
	}

	double prev = 0.0, result = 0.0;
	int n = 100;
	
	do {
		double dx = (b - a) / n;
		
		prev = result;
		result = 0.0;
		for (int i = 0; i < n; ++i) {
			result += dx * f(a + i * dx + 0.5 * dx);
		}
		n *= 2;
	} while(fabs(prev - result) > eps);

	return result;
}
