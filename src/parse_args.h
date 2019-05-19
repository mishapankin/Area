#ifndef _PARSE_ARGS_H_
#define _PARSE_ARGS_H_

int has_flag(int argc, char **argv, const char *flag);
char** get_flag(int argc, char **argv, const char *flag, int count);

#endif // _PARSE_ARGS_H_