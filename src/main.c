#include <math.h>
#include <stdio.h>
#include <unistd.h>

#include "func.h"
#include "methods.h"
#include "parse_args.h"
#include "test_funcs.h"

extern const double a;			// Левая граница. Инициализируется в func.nasm
extern const double b;			// Правая граница. Инициализируется в func.nasm

const double EPS = 1e-5;		// Погрешность.

/// Выводит информацию о программе и принимаемые аргументы командной строки.
void help(char *current_dir) {
	puts("Calculates area of a figure bounded by graphs of 3 functions.");
	printf("Plot of graph is on file://%s/html/graph.html\n", current_dir);
	puts("Arguments:");
	puts("\t--help, -h\t\t\tShow this help");
	puts("\t--human\t\t\t\tPrint with explaining text.");
	puts("\t--iter\t\t\t\tPrint count of iterations.");
	puts("\t--ti NUM A B\t\t\tGet value of integral NUM from A to B.");
	puts("\t--tr NUM1 NUM2 A B\t\tFind x of intersection of functions NUM1 and NUM2.");
	puts("\nTest functions are:");
	for (int i = 0; i < 5; ++i) {
		printf("\t%s\n", func_str_arr[i]);
	}
}

/// Точка входу в программу.
/// Разбирает аргументы командной строки и в зависимости от них
/// запускает соответствующий режим работы.
int main(int argc, char** argv) {
	INIT_FPU();
	
	int	human = has_flag(argc, argv, "--human"),
		iter  = has_flag(argc, argv, "--iter");

	char current_dir[100];
	getcwd(current_dir, 100);

	if (has_flag(argc, argv, "--help") || has_flag(argc, argv, "-h")) {
		help(current_dir);
		return 0;
	}

	if (has_flag(argc, argv, "--ti")) {
		char **arguments = get_flag(argc, argv, "--ti", 3);
		if (!arguments) {
			puts(human? "Uncorrect arguments": "Nan");
		} else {
			test_integral(arguments, human, EPS);
		}
		return 0;
	}

	if (has_flag(argc, argv, "--tr")) {
		char **arguments = get_flag(argc, argv, "--tr", 4);
		if (!arguments) {
			puts(human? "Uncorrect arguments": "Nan");
		} else {
			test_root(arguments, human, EPS, iter);
		}
		return 0;
	}

	int it12, it23, it31;
	double	x12 = root(f1, f2, a, b, EPS, &it12),
			x23 = root(f2, f3, a, b, EPS, &it23),
			x31 = root(f3, f1, a, b, EPS, &it31);

	double area = fabs(integral(f1, x31, x12, EPS) + integral(f2, x12, x23, EPS) + integral(f3, x23, x31, EPS));

	if (human) {
		printf("Plot is in file://%s/html/graph.html\n\n", current_dir);
		if (iter) {
			printf("x12 found in %d iterations\n", it12);
			printf("x23 found in %d iterations\n", it23);
			printf("x31 found in %d iterations\n", it31);
			puts("");
		}
		printf("x12: %lf\n", x12);
		printf("x23: %lf\n", x23);
		printf("x31: %lf\n", x31);
		printf("\nArea: ");
	}
	printf("%lf\n", area);
	
	return 0;
}
