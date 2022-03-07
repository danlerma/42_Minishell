#include<minishell.h>

void	make_unset(t_lst *lst, t_info *info, t_mirage **env)
{
	int	i;

	i = 0;
	if (lst->n_words > 1)
	{
		while (lst->argv[i] != NULL)
		{
			if (ft_strchr(lst->argv[i], '=') == NULL)
				delete_var(env, lst->argv[i]);
			else
				printf("unset: '%s' : not a valid identifier\n", lst->argv[i]);
			i++;
		}
	}
}
