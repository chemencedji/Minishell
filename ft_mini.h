
#ifndef FT_MINI_H
# define FT_MINI_H
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# include "libft/includes/libft.h"
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

extern int          g_buffsize;
extern t_env        *g_envlist;
extern char 		**g_env;

void  ft_newenv();
t_env   *ft_envpath(char **str);
t_env	*ft_create(char *str);
char    *lsh_read_line(void);
int     ft_exit_fail(void);
char    **lsh_split_line(char *line);
char    *ft_realloc(char *str);
char    ft_getchar(void);
int     lsh_launch(char **args);
int     lsh_execute(char **args);
int     lsh_num_builtins(void);
char    *ft_cmd(char *str);
int     lsh_cd(char **args);
int     lsh_env();
int     lsh_setenv(char **args);
int 	lsh_unsetenv(char **args);
int 	lsh_echo(char **args);
int     lsh_help();
int     lsh_exit();
void  ft_setpwd();
void  ft_setoldpwd();
void  ft_gohome();
void  ft_goback();
void  ft_gotto(char *str);

#endif
