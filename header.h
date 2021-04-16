#ifndef HEADER
#define HEADER
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
#define LSH_RL_BUFSIZE 1024
int lsh_execute(char **args);
int lsh_exit(char **args);
int lsh_help(char **args);
int lsh_cd(char **args);
int lsh_num_builtins(void);
int lsh_launch(char **args);
char **lsh_split_line(char *line);
char *lsh_read_line(void);
char *lsh_read_line(void);
void lsh_loop(void);
int main(void);
#endif
