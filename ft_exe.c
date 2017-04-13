/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:34:32 by ichemenc          #+#    #+#             */
/*   Updated: 2017/04/13 18:48:41 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini.h"

int		(*g_builtin_func[])(char **) = {&lsh_cd, &lsh_env, &lsh_setenv,
	&lsh_unsetenv, &lsh_echo, &lsh_help, &lsh_exit};

char	*g_builtin_str[] = {"cd", "env", "setenv", "unsetenv", "echo", "help",
	"exit"};

int			lsh_execute(char **args)
{
	int		i;
	char	*str;

	i = -1;
	if (args[0] == NULL)
		return (1);
	str = args[0];
	if (*str == '/')
	{
		str = ft_strrchr(str, '/');
		str++;
	}
	while (++i < lsh_num_builtins())
	{
		if (ft_strcmp(str, g_builtin_str[i]) == 0)
			return ((*g_builtin_func[i])(args));
	}
	return (lsh_launch(args));
}

int			lsh_launch(char **args)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		ft_exec(args);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		ft_putstr_fd("Command error\n", 2);
	else
	{
		wpid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}

void		ft_exec(char **args)
{
	char	*path;

	if (args[0][0] == '/')
		execve(args[0], args, g_env);
	else if ((path = ft_cmd(args[0])) != NULL)
		execve(path, args, g_env);
	else
		ft_putstr_fd(ft_strjoin(args[0], ": command not found\n"), 2);
}

int			lsh_num_builtins(void)
{
	return (sizeof(g_builtin_str) / sizeof(char *));
}
