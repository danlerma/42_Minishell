/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:16:39 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/15 17:17:54 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

static int	check_chars_un(t_lst *lst, int i)
{
	int	y;

	if (ft_isalpha(lst->argv[i][0]) == 0)
	{
		printf("unset: '%s' : not a valid identifier\n", lst->argv[i]);
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

void	make_unset(t_lst *lst, t_info *info, t_env **env)
{
	int	i;

	(void) info;
	i = 1;
	if (lst->n_words > 1)
	{
		while (lst->argv[i] != NULL)
		{
			if (check_chars_un(lst, i) == 1)
				i *= 1;
			else if (get_name_env((*env)->env, lst->argv[i]) != NULL)
			{
				delete_var(&(*env)->env, lst->argv[i]);
				delete_var(&(*env)->ex_env, lst->argv[i]);
			}
			else if (get_name_env((*env)->ex_env, lst->argv[i]) != NULL)
				delete_var(&(*env)->ex_env, lst->argv[i]);
			i++;
		}
	}
}
