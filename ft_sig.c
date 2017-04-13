/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:54:36 by ichemenc          #+#    #+#             */
/*   Updated: 2017/04/13 19:00:52 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini.h"

void		sighandler(void)
{
	ft_putstr("\n$> ");
	g_sigint = 0;
}

void		sh_loop(void)
{
	char	*line;
	char	**args;
	int		status;

	status = 1;
	while (status)
	{
		if (g_sigint && g_semi == 0)
			ft_putstr("$> ");
		g_semi = 0;
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
}
