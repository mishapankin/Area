#ifndef _PARSE_ARGS_H_
#define _PARSE_ARGS_H_

/// Проверяет наличие флага flag среди аргументов командной строки.
int has_flag(int argc, char **argv, const char *flag);

/// Находит первый аргумент командной строки, совпадающий с flag.
/// Если после него хотя бы count аргументов, то возвращает указатель
/// на следующий за ним аргумент (первый аргумент флага). Иначе NULL.
char** get_flag(int argc, char **argv, const char *flag, int count);

#endif // _PARSE_ARGS_H_