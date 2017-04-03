
#include "ft_mini.h"
#include "libft/includes/libft.h"

int     main(void)
{
  // Load config files, if any.

  // Run command loop.
  lsh_loop();

  // Perform any shutdown/cleanup.

  return EXIT_SUCCESS;
}

void    lsh_loop(void)
{
  char  *line;
  char  **args;
  int   status = 0;

  do
  {
    ft_putstr("$> ");
    line = lsh_read_line();
    args = ft_strsplit(line, ' ');
    //args = lsh_split_line(line);
    status = lsh_execute(args);

    free(line);
    free(args);
  }
  while (status);
}

char    *lsh_read_line(void)
{
  int   bufsize;
  int   position;
  char  *buffer;
  int   c;

  bufsize = LSH_RL_BUFSIZE;
  buffer = ft_strnew(bufsize);
  position = 0;
  if (!buffer)
  {
    ft_putstr_fd("Allocation error\n", 2);
    exit(EXIT_FAILURE);
  }
  while (1)
  {
    c = getchar();
    if (c == EOF || c == '\n')
    {
      buffer[position] = '\0';
      return buffer;
    }
    else
      buffer[position] = c;
    position++;
    if (position >= bufsize)
    {
      bufsize += LSH_RL_BUFSIZE;
      buffer = realloc(buffer, bufsize);
      if (!buffer)
      {
        ft_putstr_fd("Allocation error\n", 2);
        exit(EXIT_FAILURE);
      }
    }
  }
}