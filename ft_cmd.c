
#include "ft_mini.h"

char    *ft_cmd(char *str)
{
    int i;
    char *ex_path;
    
    i = -1;
    ex_path = ft_strjoin("/", str);
    while (g_expath[++i])
    {
        if (access(ft_strjoin(g_expath[i], ex_path), F_OK) == 0)
            return (ft_strjoin(g_expath[i], ex_path));
    }
    return(NULL);
}