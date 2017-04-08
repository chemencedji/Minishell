/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 18:44:50 by ichemenc          #+#    #+#             */
/*   Updated: 2017/04/08 17:01:38 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini.h"

int   g_buffsize = 1024;
t_env *g_env;

int     main(int argc, char **argv, char **envp)
{
  char  *line;
  char  **args;
  int   status;
  
  g_env = ft_envpath(envp);
  if(argc > 0 && argv != NULL)
  {
    do
    {
      ft_putstr("$> ");
      line = lsh_read_line();
      args = ft_strsplit(line, ' ');
      status = lsh_execute(args);
      free(line);
      free(args);
    }
    while (status);
  }
  return (0);
}

t_env    *ft_envpath(char **str)
{
	int 	i;
	t_env	*elem;

	i = -1;
	elem = ft_create(str[++i]);
	while (str[++i])
	{
	}
	return (elem);
}

t_env	*ft_create(char *str)
{
	char *name;
	char *value;


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
