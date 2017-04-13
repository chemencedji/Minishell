
#include "ft_mini.h"

int lsh_cd(char **args)
{
  if (args[1] == NULL)
  {
    ft_putstr_fd("Expected argument to \"cd\"\n", 2);
  }
  else
  {
    if (ft_strcmp(args[1], "-") != 0)
      ft_setoldpwd();
    if (chdir(args[1]) == 0)
      ft_setpwd();
    else if (ft_strcmp(args[1], "--") == 0)
      ft_gohome();
    else if (ft_strcmp(args[1], "-") == 0)
      ft_goback();
    else if (args[1][0] == '~')
      ft_gotto(args[1]);
    else
      ft_putstr_fd(ft_strjoin(args[1], ": Not valide argument\n"), 2);
  }
  return (1);
}

void  ft_setoldpwd()
{
  t_env *ptr;
  char cwd[g_buffsize];
  
  ptr = g_envlist;
  while (ptr)
  {
    if (ft_strcmp(ptr->name, "OLDPWD") == 0)
    {
      if (getcwd(cwd, sizeof(cwd)) != NULL)
      {
        ft_strdel(&(ptr->value));
        ptr->value = ft_strdup(cwd);
      }
      break ;
    }
    ptr = ptr->next;
  }
}

void  ft_setpwd()
{
  t_env *ptr;
  char cwd[g_buffsize];
  
  ptr = g_envlist;
  while (ptr)
  {
    if (ft_strcmp(ptr->name, "PWD") == 0)
    {
      if (getcwd(cwd, sizeof(cwd)) != NULL)
      {
        ft_strdel(&(ptr->value));
        ptr->value = ft_strdup(cwd);
      }
      break ;
    }
    ptr = ptr->next;
  }
}

void  ft_gohome()
{
  t_env *ptr;
  
  ptr = g_envlist;
  while (ptr)
  {
    if (ft_strcmp(ptr->name, "HOME") == 0)
    {
      if (chdir(ptr->value) == 0)
        ft_setpwd();
      break ;
    }
    ptr = ptr->next;
  }
}

void  ft_goback()
{
  t_env *ptr;
  
  ptr = g_envlist;
  while (ptr)
  {
    if (ft_strcmp(ptr->name, "OLDPWD") == 0)
    {
      if (chdir(ptr->value) == 0)
        ft_setpwd();
      break ;
    }
    ptr = ptr->next;
  }
}