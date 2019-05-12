#include <math.h>
#include <stdio.h>

#include "func.h"
#include "methods.h"

extern const double a;
extern const double b;

typedef struct {
	func_t f, g;
	double x;
} Fig;

void sort_fig(Fig *fig1, Fig *fig2) {
	if (fig2->x < fig1->x) {
		Fig t = *fig1;
		*fig1 = *fig2;
		*fig2 = t;
	}
}

int main(int argc, char** argv) {
	INIT_FPU();

	double eps = 1e-4;

	Fig	fig1 = {f1, f2, root(f1, f2, a, b, eps)},
		fig2 = {f2, f3, root(f2, f3, a, b, eps)},
		fig3 = {f1, f3, root(f1, f3, a, b, eps)};

	sort_fig(&fig1, &fig2);
	sort_fig(&fig1, &fig3);
	sort_fig(&fig2, &fig3);

	double area = fabs(integral(fig1.f, fig1.g, fig1.x, fig2.x, eps)) + fabs(integral(fig3.f, fig3.g, fig2.x, fig3.x, eps));

	printf("%lf %lf %lf\n", fig1.x, fig2.x, fig3.x);
	printf("%lf\n", area);
	
	return 0;
}
