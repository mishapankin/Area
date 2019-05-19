#include "parse_args.h"

#include <string.h>

int has_flag(int argc, char **argv, const char *flag) {
    for (int i = 1; i < argc; ++i) {
        if (!strcmp(argv[i], flag)) {
            return 1;
        }
    }
    return 0;
}

char** get_flag(int argc, char **argv, const char *flag, int count) {
    for (int i = 1; i < argc - count; ++i) {
        if (!strcmp(argv[i], flag)) {
            return argv + i + 1;
        }
    }
    return NULL;
}