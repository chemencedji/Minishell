

#include "ft_mini.h"

char    *ft_cmd(char *str)
{
    int i;
    t_env *ptr;
    char *ex_path;
    char **g_expath;
	struct stat buf;
    
    i = -1;
    ptr = g_envlist;
	g_expath = NULL;
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
	if (g_expath == NULL)
		return (NULL);
    ex_path = ft_strjoin("/", str);
    while (g_expath[++i])
    {
		lstat(ft_strjoin(g_expath[i], ex_path), &buf);
		printf("%d\n", buf.st_mode & S_IXUSR);
        if (access(ft_strjoin(g_expath[i], ex_path), F_OK) == 0)
            return (ft_strjoin(g_expath[i], ex_path));
	}
    return(NULL);
}
