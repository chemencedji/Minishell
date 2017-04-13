
#include "ft_mini.h"

t_env    *ft_envpath(char **str)
{
	int 	i;
	t_env	*elem;
	t_env *ptr;

	i = 0;
	elem = ft_create(str[i++]);
	ptr = elem;
	while (str[i])
	{
	  ptr->next = ft_create(str[i]);
	  ptr = ptr->next;
	  i++;
	}
	return (elem);
}

t_env	*ft_create(char *str)
{
  size_t i;
  t_env *elem;
	
	i = 0;
	elem = (t_env*)malloc(sizeof(t_env));
	while (str[i] != '\0' && str[i] != '=')
	  i++;
	elem->name = ft_strnew(i);
	elem->name = ft_strncpy(elem->name, str, i);
	if (str[++i] != '\0')
	{
	  str += i;
	  i = 0;
	  while (str[i] != '\0')
	    i++;
	 elem->value = ft_strnew(i);
	 elem->value = ft_strncpy(elem->value, str, i);
	}
	else
	  elem->value = NULL;
	elem->next = NULL;
	return (elem);
}