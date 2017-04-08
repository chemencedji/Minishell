
#include "ft_mini.h"

int lsh_cd(char **args)
{
  if (args[1] == NULL)
  {
    ft_putstr_fd("Expected argument to \"cd\"\n", 2);
  }
  else
  {
    if (chdir(args[1]) != 0)
      ft_putstr_fd(ft_strjoin(args[1], ": Not valide argument\n"), 2);
    else
      chdir(args[1]);
  }
  return (1);
}

int lsh_help()
{
  ft_putendl("Pompieri — 901\nPoliţia — 902");
  ft_putendl("Asistenţa medicală urgentă — 903\nServiciul gaze — 904");
  ft_putendl("Igor Chemencedji - 079826919");
  return (1);
}

int lsh_env()
{
  int i;
  
  i = -1;
  while (g_env[++i])
    ft_putendl(g_env[i]);
  return (1);
}

int	ft_isup(char *str)
{
  while (*str)
  {
    if(ft_isalnum(*str) == 0)
      return (0);
    str++;
  }
  return (1);
}

int lsh_setenv(char **args)
{
  if (args[1] == NULL)
  {
    ft_putstr_fd("Expected argument to \"setenv\"\n", 2);
  }
  else
  {
    if (ft_isup(args[1]) == 1)
    {ft_putstr_fd("Env need to be uppercase", 2);
    }
    else
      ft_putstr_fd("Env need to be uppercase", 2);
  }
  return (1);
}

int lsh_exit()
{
  return (0);
}