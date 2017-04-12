/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 18:44:50 by ichemenc          #+#    #+#             */
/*   Updated: 2017/04/12 18:46:21 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini.h"

int   g_buffsize = 1024;
int g_sigint;
char  **g_env;
t_env *g_envlist;

void	sighandler()
{
	ft_putstr("\n$> ");
	g_sigint = 0;
}

int     main(int argc, char **argv, char **envp)
{
  g_envlist = ft_envpath(envp);
  g_env = envp;
  g_sigint = 1;
  signal(SIGINT, sighandler);
  if(argc > 0 && argv != NULL)
  	sh_loop();
  return (0);
}

void	sh_loop(void)
{
	char  *line;
	char  **args;
	int   status;

	do
	{
		if (g_sigint)
			ft_putstr("$> ");
		line = lsh_read_line();
		g_sigint = 1;
		if (g_sigint)
		{
		args = ft_strsplit(line, ' ');
		status = lsh_execute(args);
		free(args);
		}
		free(line);
	}
	while (status);
}

t_env    *ft_envpath(char **str)
{
	int 	i;
	t_env	*elem;
	t_env *ptr;

	i = 0;
	elem = ft_create(str[i++]);
	ptr = elem;
	while (str[i])
	{
	  ptr->next = ft_create(str[i]);
	  ptr = ptr->next;
	  i++;
	}
	return (elem);
}

t_env	*ft_create(char *str)
{
  size_t i;
  t_env *elem;
	
	i = 0;
	elem = (t_env*)malloc(sizeof(t_env));
	while (str[i] != '\0' && str[i] != '=')
	  i++;
	elem->name = ft_strnew(i);
	elem->name = ft_strncpy(elem->name, str, i);
	if (str[++i] != '\0')
	{
	  str += i;
	  i = 0;
	  while (str[i] != '\0')
	    i++;
	 elem->value = ft_strnew(i);
	 elem->value = ft_strncpy(elem->value, str, i);
	}
	else
	  elem->value = NULL;
	elem->next = NULL;
	return (elem);
}



char    *lsh_read_line(void)
{
  int   position;
  char  *buffer;
  int   c;

  buffer = ft_strnew(g_buffsize);
  position = 0;
  if (!buffer)
    exit(ft_exit_fail());
  while (1)
  {
    c = ft_getchar();
    if (c == '\t' || c == '\a' || c == '\r')
      c = ' ';
    if (c == '\n')
    {
      buffer[position] = '\0';
      return (buffer);
    }
    else
      buffer[position] = c;
    position++;
    if (position >= g_buffsize)
      buffer = ft_realloc(buffer);
  }
}

char  ft_getchar()
{
    char data[1];
 
    if (read(0, data, 1) < 0)
     write(2, &data, 1);
 
  return(data[0]);
}

char  *ft_realloc(char *str)
{
  char  *buffer;
  
  g_buffsize += g_buffsize;
  buffer = ft_strnew(g_buffsize);
  if (!buffer)
    exit(ft_exit_fail());
  buffer = ft_strcpy(buffer, str);
  return (buffer);
}

int   ft_exit_fail(void)
{
  ft_putstr_fd("Allocation error\n", 2);
  return (1);
}
