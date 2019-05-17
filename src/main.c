#include <math.h>
#include <stdio.h>

#include "func.h"
#include "methods.h"

extern const double a;
extern const double b;

int main(int argc, char** argv) {
	INIT_FPU();

	double eps = 1e-4;

	printf("%lf \n", f1(5));

	double	x12 = root(f1, f2, a, b, eps),
			x23 = root(f2, f3, a, b, eps),
			x31 = root(f3, f1, a, b, eps);

	double area = fabs(integral(f1, x31, x12, eps) + integral(f2, x12, x23, eps) + integral(f3, x23, x31, eps));

	printf("%lf %lf %lf\n", x12, x23, x31);
	printf("%lf\n", area);
	
	return 0;
}
