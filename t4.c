#include "header.h"
/**
 *lsh_read_line - Function llama a los loop
 *Load config files, if any.
 *Run command loop.
 * Perform any shutdown cleanup.
 *Return: los loops
*/
char *lsh_read_line(void)
{
char *line = NULL;
ssize_t bufsize = 0;
if (getline(&line, &bufsize, stdin) == -1)
{
if (feof(stdin))
{
exit(EXIT_SUCCESS);
}
else
{
perror("readline");
exit(EXIT_FAILURE);
}
}
return (line);
}
/**
 *lsh_split_line - Function llama a los loop
 *Load config files, if any.
 *Run command loop.
 * Perform any shutdown cleanup.
 *@line: un int
 *Return: los loops
*/
char **lsh_split_line(char *line)
{
int bufsize = LSH_TOK_BUFSIZE, position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;
if (!tokens)
{
fprintf(stderr, "lsh: allocation error\n");
exit(EXIT_FAILURE);
}
token = strtok(line, LSH_TOK_DELIM);
while (token != NULL)
{
tokens[position] = token;
position++;
if (position >= bufsize)
{
bufsize += LSH_TOK_BUFSIZE;
tokens = realloc(tokens, bufsize *sizeof(char *));
if (!tokens)
{
fprintf(stderr, "lsh: allocation error\n");
exit(EXIT_FAILURE);
}
}
token = strtok(NULL, LSH_TOK_DELIM);
}
tokens[position] = NULL;
return (tokens);
}
/**
 *lsh_launch - Function llama a los loop
 *Child process
 *Error forking
 * Parent process
 *@args: puntero
 *Return: los loops
*/
int lsh_launch(char **args)
{
pid_t pid, wpid;
int status;
pid = fork();
if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
perror("lsh");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("lsh");
}
else
{
do {
wpid = waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
return (1);
}
