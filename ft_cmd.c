
#include "ft_mini.h"

char    *ft_cmd(char *str)
{
    int i;
    t_env *ptr;
    char *ex_path;
    char **g_expath;
    
    i = -1;
    ptr = g_envlist;
    if (*str == '/')
        str = ft_strrchr(str, '/');
    while (ptr)
    {
        if (ft_strcmp(ptr->name, "PATH") == 0)
        {
            g_expath = ft_strsplit(ptr->value, ':');
            break ;
        }
        ptr = ptr->next;
    }
    ex_path = ft_strjoin("/", str);
    while (g_expath[++i])
    {
        if (access(ft_strjoin(g_expath[i], ex_path), F_OK) == 0)
            return (ft_strjoin(g_expath[i], ex_path));
    }
    return(NULL);
}