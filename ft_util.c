
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

void  ft_gotto(char *str)
{
  t_env *ptr;
  
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

int lsh_help()
{
  ft_putendl("Pompieri — 901\nPoliţia — 902");
  ft_putendl("Asistenţa medicală urgentă — 903\nServiciul gaze — 904");
  ft_putendl("Igor Chemencedji - 079826919");
  return (1);
}

int lsh_echo(char **args)
{
  int i;
  t_env *ptr;
  char *str;
  
  i = 1;
  ptr = g_envlist;
  if (args[1] == NULL)
  {
    ft_putstr_fd("Expected argument to \"echo\"\n", 2);
  }
  else
  {
    if (args[1][0] == '$')
    {
      str = ft_strchr(args[1], '$');
      str++;
      while (ptr)
      {
        if (ft_strcmp(ptr->name, str) == 0)
        {
          str = ptr->value;
          while(*str)
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
    else
    {
      str = args[1];
      while (args[++i])
        str = ft_strjoin(ft_strjoin(str, " "), args[i]);
      while(*str)
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

int lsh_env()
{
  t_env *ptr;
  char *str;
  
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
      ft_putchar('\n');
    }
    ptr = ptr->next;
  }
  return (1);
}

/*int	ft_isup(char *str)
{
  while (*str)
  {
    if(ft_isalnum(*str) == 0)
      return (0);
    str++;
  }
  return (1);
}*/

int lsh_setenv(char **args)
{
  t_env *ptr;
  int flag;
  
  flag = 0;
  ptr = g_envlist;
  if (args[1] == NULL)
  {
    ft_putstr_fd("Expected argument to \"setenv\"\n", 2);
  }
  else
  {
    while (ptr)
    {
      if (ft_strcmp(ptr->name, args[1]) == 0)
      {
        flag = 1;
        if (args[2] == NULL)
          ft_strdel(&(ptr->value));
        else
        {
          ft_strdel(&(ptr->value));
          ptr->value = ft_strnew(ft_strlen(args[2]));
          ptr->value = ft_strcpy(ptr->value, args[2]);
        }
        break ;
      }
      if (ptr->next != NULL)
        ptr = ptr->next;
      else
        break ;
    }
    if (ptr->next == NULL && flag == 0)
    {
      ptr->next = (t_env*)malloc(sizeof(t_env));
      ptr->next->name = ft_strnew(ft_strlen(args[1]));
      ptr->next->name = ft_strcpy(ptr->next->name, args[1]);
      if (args[2] != NULL)
      {
          ptr->next->value = ft_strnew(ft_strlen(args[2]));
          ptr->next->value = ft_strcpy(ptr->next->value, args[2]);
      }
    }
    //ft_newenv();
  }
  return (1);
}

/*void  ft_newenv()
{
  t_env *ptr;
  int i;
  char **newenv;
  
  i = 0;
  ptr = g_envlist;
  while(ptr)
  {
    ptr = ptr->next;
    i++;
  }
  newenv = (char **)malloc(sizeof(char*) * i);
  i = 0;
  ptr = g_envlist;
  while (ptr)
  {
    newenv[i] = ft_strjoin(ptr->name, "=");
    if (ptr->value != NULL)
      newenv[i] = ft_strjoin(newenv[i], ptr->value);
    i++;
    ptr = ptr->next;
  }
  g_env = newenv;
  g_envlist = ft_envpath(g_env);
}*/

int lsh_unsetenv(char **args)
{
  t_env *ptr;
  t_env *del;
  
  ptr = g_envlist;
  if (ft_strcmp(ptr->name, args[1]) == 0)
  {
    g_envlist = g_envlist->next;
    free(ptr);
    return (1);
  }
  while (ptr)
  {
    if (ft_strcmp(ptr->next->name, args[1]) == 0)
    {
      del = ptr->next;
      if (ptr->next->next != NULL)
        ptr->next = ptr->next->next;
      else
        ptr->next = NULL;
      free (del);
      break ;
    }
    if(ptr->next != NULL)
    ptr = ptr->next;
    else
    break ; 
  }
  return (1);
}

int lsh_exit()
{
  t_env *ptr;
  t_env *del;
  
  ptr = g_envlist;
  while(ptr)
  {
    del = ptr;
    ptr = ptr->next;
    free(del);
  }
  return (0);
}
