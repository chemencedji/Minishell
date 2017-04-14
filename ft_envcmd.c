/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:17:33 by ichemenc          #+#    #+#             */
/*   Updated: 2017/04/13 18:34:17 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini.h"

int			lsh_env(void)
{
	t_env	*ptr;
	char	*str;

	ptr = g_envlist;
	while (ptr)
	{
		ft_putstr(ptr->name);
		ft_putchar('=');
		if (ptr->value != NULL)
		{
			str = ptr->value;
			while (*str)
			{
				if (*str != 34 && *str != 39)
					ft_putchar(*str);
				str++;
			}
		}
		ft_putchar('\n');
		ptr = ptr->next;
	}
	return (1);
}

int			lsh_setenv(char **args)
{
	t_env	*ptr;
	int		flag;

	flag = 0;
	ptr = g_envlist;
	if (args[1] == NULL)
		ft_putstr_fd("Expected argument to \"setenv\"\n", 2);
	else
	{
		while (ptr)
		{
			if (ft_strcmp(ptr->name, args[1]) == 0)
			{
				flag = ft_changenv(ptr, args);
				break ;
			}
			if (ptr->next != NULL)
				ptr = ptr->next;
			else
				break ;
		}
		if (ptr->next == NULL && flag == 0)
			ft_addenv(ptr, args);
	}
	return (1);
}

int			ft_changenv(t_env *ptr, char **args)
{
	if (args[2] == NULL)
		ft_strdel(&(ptr->value));
	else
	{
		ft_strdel(&(ptr->value));
		ptr->value = ft_strnew(ft_strlen(args[2]));
		ptr->value = ft_strcpy(ptr->value, args[2]);
	}
	return (1);
}

void		ft_addenv(t_env *ptr, char **args)
{
	ptr->next = (t_env*)malloc(sizeof(t_env));
	ptr->next->name = ft_strnew(ft_strlen(args[1]));
	ptr->next->name = ft_strcpy(ptr->next->name, args[1]);
	if (args[2] != NULL)
	{
		ptr->next->value = ft_strnew(ft_strlen(args[2]));
		ptr->next->value = ft_strcpy(ptr->next->value, args[2]);
		ptr->next->next = NULL;
	}
}
