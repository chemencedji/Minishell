
#include "ft_mini.h"
#include "libft/includes/libft.h"

int g_buffsize = 1024;

int     main(void)
{
  char  *line;
  char  **args;
  int   status;

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
  return (0);
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
    c = getchar();
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