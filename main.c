/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 18:44:50 by ichemenc          #+#    #+#             */
/*   Updated: 2017/04/13 19:26:32 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini.h"

int			g_buffsize;
int			g_semi;
int			g_sigint;
char		**g_env;
t_env		*g_envlist;

int			main(int argc, char **argv, char **envp)
{
	g_buffsize = 1024;
	g_envlist = ft_envpath(envp);
	g_env = envp;
	g_sigint = 1;
	g_semi = 0;
	signal(SIGINT, sighandler);
	if (argc > 0 && argv != NULL)
		sh_loop();
	return (0);
}

char		*lsh_read_line(void)
{
	int		position;
	char	*buffer;
	int		c;

	position = 0;
	buffer = ft_strnew(g_buffsize);
	if (!buffer)
		exit(ft_exit_fail());
	while (1)
	{
		c = ft_getchar();
		if (c == '\t' || c == '\a' || c == '\r')
			c = ' ';
		if (c == ';')
			g_semi = 1;
		if (c == '\n' || c == ';')
			return (buffer);
		else
			buffer[position] = c;
		position++;
		if (position >= g_buffsize)
			buffer = ft_realloc(buffer);
	}
}

/*char  *ft_find(char *str)
{
  int i;
  char *ex_path;
  char **all_expath;
  DIR *dir;
  struct dirent	*sd;
  
  all_expath = ft_expath();
  i = -1;
  if (g_expath == NULL)
		return ;
	while (all_expath[++i])
  {
    if (dir = opendir(all_expath[i]) == NULL);
      i++;
    else
    {
      while ((sd = readdir(dir)) != NULL)
      {
        if(ft_strstr(sd->d_name, str) != NULL)
          ft_printsub(sd->name, str);
      }
      i++;
    }
  }
}*/

char		ft_getchar(void)
{
	char	data[1];

	if (read(0, data, 1) < 0)
		write(2, &data, 1);
	return (data[0]);
}

char		*ft_realloc(char *str)
{
	char	*buffer;

	g_buffsize += g_buffsize;
	buffer = ft_strnew(g_buffsize);
	if (!buffer)
		exit(ft_exit_fail());
	buffer = ft_strcpy(buffer, str);
	return (buffer);
}

int			ft_exit_fail(void)
{
	ft_putstr_fd("Allocation error\n", 2);
	return (1);
}
