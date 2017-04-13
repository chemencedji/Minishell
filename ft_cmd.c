/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:54:08 by ichemenc          #+#    #+#             */
/*   Updated: 2017/04/13 17:57:49 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini.h"

char			*ft_cmd(char *str)
{
	int			i;
	char		*ex_path;
	char		**g_expath;
	struct stat	buf;

	i = -1;
	g_expath = ft_expath();
	if (g_expath == NULL)
		return (NULL);
	if (*str == '/')
		str = ft_strrchr(str, '/');
	ex_path = ft_strjoin("/", str);
	while (g_expath[++i])
	{
		if (access(ft_strjoin(g_expath[i], ex_path), F_OK) == 0)
		{
			stat(ft_strjoin(g_expath[i], ex_path), &buf);
			if ((buf.st_mode & S_IXUSR) == 0)
				ft_putstr_fd("Could not execute. Permission denide\n", 2);
			return (ft_strjoin(g_expath[i], ex_path));
		}
	}
	return (NULL);
}

char			**ft_expath(void)
{
	t_env		*ptr;
	char		**g_expath;

	ptr = g_envlist;
	g_expath = NULL;
	while (ptr)
	{
		if (ft_strcmp(ptr->name, "PATH") == 0)
		{
			g_expath = ft_strsplit(ptr->value, ':');
			break ;
		}
		ptr = ptr->next;
	}
	return (g_expath);
}
