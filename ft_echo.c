/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:57:57 by ichemenc          #+#    #+#             */
/*   Updated: 2017/04/13 18:14:54 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini.h"

int			lsh_echo(char **args)
{
	int		i;
	char	*str;

	i = 1;
	if (args[1] == NULL)
		ft_putstr_fd("Expected argument to \"echo\"\n", 2);
	else
	{
		if (args[1][0] == '$')
			ft_printdol(args);
		else
		{
			str = args[1];
			while (args[++i])
				str = ft_strjoin(ft_strjoin(str, " "), args[i]);
			while (*str)
			{
				if (*str != 34 && *str != 39)
					ft_putchar(*str);
				str++;
			}
			ft_putchar('\n');
		}
	}
	return (1);
}

void		ft_printdol(char **args)
{
	t_env	*ptr;
	char	*str;

	ptr = g_envlist;
	str = ft_strchr(args[1], '$');
	str++;
	while (ptr)
	{
		if (ft_strcmp(ptr->name, str) == 0)
		{
			str = ptr->value;
			while (*str)
			{
				if (*str != 34 && *str != 39)
					ft_putchar(*str);
				str++;
			}
			ft_putchar('\n');
		}
		ptr = ptr->next;
	}
}
