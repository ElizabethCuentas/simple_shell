#include "header.h"
/**
 *main - Function llama a los loop
 *Load config files, if any.
 *Run command loop.
 * Perform any shutdown cleanup.
 *@argc: un int
 *@argv: puntero
 *Return: los loops
*/
int main(int argc, char **argv)
{
lsh_loop();
return (EXIT_SUCCESS);
}
/**
 *lsh_loop - Function crea los diferentes loops
 *Load config files, if any.
 *Run command loop.
 * Perform any shutdown cleanup.
 *Return: los loops
*/
void lsh_loop(void)
{
char *line;
char **args;
int status;
do {
printf("> ");
line = lsh_read_line();
args = lsh_split_line(line);
status = lsh_execute(args);
free(line);
free(args);
}
}
while (status)
/**
 *lsh_read_line - Function lee las lineas
 *Load config files, if any.
 *Run command loop.
 * Perform any shutdown cleanup.
 *Return: los loops
*/
char *lsh_read_line(void)
{
int bufsize = LSH_RL_BUFSIZE;
int position = 0;
char *buffer = malloc(sizeof(char) * bufsize);
int c;
if (!buffer)
{
fprintf(stderr, "lsh: allocation error\n");
exit(EXIT_FAILURE);
}

while (1)
{
c = getchar();
if (c == EOF || c == '\n')
{
buffer[position] = '\0';
return (buffer);
}
else
{
buffer[position] = c;
}
position++;
if (position >= bufsize)
{
bufsize += LSH_RL_BUFSIZE;
buffer = realloc(buffer, bufsize);
if (!buffer)
{
fprintf(stderr, "lsh: allocation error\n");
exit(EXIT_FAILURE);
}
}
}
}
/**
 *lsh_execute - Function ejecuta
 *Load config files, if any.
 *Run command loop.
 * Perform any shutdown cleanup.
  *@args: puntero
 *Return: los loops
*/
int lsh_execute(char **args)
{
int i;
if (args[0] == NULL)
{
return (1);
}
for (i = 0; i < lsh_num_builtins(); i++)
{
if (strcmp(args[0], builtin_str[i]) == 0)
{
return ((*builtin_func[i])(args));
}
}
return (lsh_launch(args));
}
