/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:52:14 by ichemenc          #+#    #+#             */
/*   Updated: 2017/04/13 19:02:23 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <signal.h>
# include <sys/stat.h>

typedef	struct		s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

extern int			g_sigint;
extern int			g_semi;
extern int			g_buffsize;
extern t_env		*g_envlist;
extern char			**g_env;

void				ft_newenv(void);
void				sighandler();
void				sh_loop(void);
t_env				*ft_envpath(char **str);
t_env				*ft_create(char *str);
char				*lsh_read_line(void);
int					ft_exit_fail(void);
char				**lsh_split_line(char *line);
char				*ft_realloc(char *str);
char				ft_getchar(void);
int					lsh_launch(char **args);
int					lsh_execute(char **args);
void				ft_exec(char **args);
int					lsh_num_builtins(void);
char				*ft_cmd(char *str);
char				**ft_expath(void);
int					lsh_cd(char **args);
int					lsh_env();
int					lsh_setenv(char **args);
int					ft_changenv(t_env *ptr, char **args);
void				ft_addenv(t_env *ptr, char **args);
int					lsh_unsetenv(char **args);
int					ft_firgl(char **args);
int					lsh_echo(char **args);
void				ft_printdol(char **args);
int					lsh_help();
int					lsh_exit();
void				ft_setpwd(void);
void				ft_setoldpwd(void);
void				ft_gohome(void);
void				ft_goback(void);
void				ft_gotto(char *str);
char				*ft_line(char *str);

#endif
