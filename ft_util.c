/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 19:02:48 by ichemenc          #+#    #+#             */
/*   Updated: 2017/04/13 19:08:37 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini.h"

void		ft_gotto(char *str)
{
	t_env	*ptr;

	ptr = g_envlist;
	while (ptr)
	{
		if (ft_strcmp(ptr->name, "HOME") == 0)
		{
			str = ft_strchr(str, '/');
			str = ft_strjoin(ptr->value, str);
			if (chdir(str) == 0)
				ft_setpwd();
			break ;
		}
		ptr = ptr->next;
	}
}

int			lsh_help(void)
{
	ft_putendl("Pompieri — 901\nPoliţia — 902");
	ft_putendl("Asistenţa medicală urgentă — 903\nServiciul gaze — 904");
	return (1);
}

int			lsh_unsetenv(char **args)
{
	t_env	*ptr;
	t_env	*del;

	ptr = g_envlist;
	if (ft_firgl(args) == 1)
		return (1);
	while (ptr)
	{
		if (ft_strcmp(ptr->next->name, args[1]) == 0)
		{
			del = ptr->next;
			if (ptr->next->next != NULL)
				ptr->next = ptr->next->next;
			else
				ptr->next = NULL;
			free(del);
			break ;
		}
		if (ptr->next != NULL)
			ptr = ptr->next;
		else
			break ;
	}
	return (1);
}

int			ft_firgl(char **args)
{
	t_env	*ptr;

	ptr = g_envlist;
	if (ft_strcmp(ptr->name, args[1]) == 0)
	{
		g_envlist = g_envlist->next;
		free(ptr);
		return (1);
	}
	return (0);
}

int			lsh_exit(void)
{
	t_env	*ptr;
	t_env	*del;

	ptr = g_envlist;
	while (ptr)
	{
		del = ptr;
		ptr = ptr->next;
		free(del);
	}
	return (0);
}
