
#include "ft_mini.h"

void	sighandler()
{
	ft_putstr("\n$> ");
	g_sigint = 0;
}

void	sh_loop(void)
{
	char  *line;
	char  **args;
	int   status;
	
	do
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
	while (status);
}