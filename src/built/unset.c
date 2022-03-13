#include<minishell.h>

static int	check_chars_un(t_lst *lst, t_mirage *env, int i)
{
	int	y;

	(void) env;
	if (ft_isalpha(lst->argv[i][0]) == 0)
	{
		printf("unset: '%s' : not a valid identifier\n", lst->argv[1]);
		return (1);
	}
	y = 0;
	while (lst->argv[i][y] != 0)
	{
		if ((lst->argv[i][y] >= 33 && lst->argv[i][y] <= 47) ||
			(lst->argv[i][y] >= 58 && lst->argv[i][y] <= 64))
		{
			printf("unset: '%s' : not a valid identifier\n", lst->argv[i]);
			return (1);
		}
		y++;
	}
	return (0);
}

void	make_unset(t_lst *lst, t_info *info, t_mirage **env)
{
	int	i;

	(void) info;
	i = 0;
	if (lst->n_words > 1)
	{
		while (lst->argv[i] != NULL)
		{
			if (check_chars_un(lst, *env, i) == 1)
				break ;
			if (ft_strchr(lst->argv[i], '=') == NULL)
				delete_var(env, lst->argv[i]);
			i++;
		}
	}
}
