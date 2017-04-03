
#ifndef FT_MINI_H
# define FT_MINI_H
# define EXIT_SUCCESS 0
# define LSH_RL_BUFSIZE 1024
# define EXIT_FAILURE 1
# define LSH_TOK_BUFSIZE 64
# define LSH_TOK_DELIM " \t\r\n\a"

# include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void    lsh_loop(void);
char    *lsh_read_line(void);
char    **lsh_split_line(char *line);
int     lsh_launch(char **args);
int     lsh_execute(char **args);
int     lsh_num_builtins(void);
int     lsh_cd(char **args);
int     lsh_help();
int     lsh_exit();


#endif