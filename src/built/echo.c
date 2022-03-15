/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:29:18 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/15 19:07:48 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

static int	num_argv(t_lst *lst)
{
	int	i;

	i = 0;
	if (lst->argv)
	{
		while (lst->argv[i] != NULL)
		{
			if (lst->type[i] != 1)
				break ;
			++i;
		}
	}
	return (i);
}

void	make_echo(t_lst *lst)
{
	int	i;
	int	num;

	i = 1;
	num = num_argv(lst);
	show_nodes(lst);
	if (lst->argv[1] != NULL)
	{
		if (ft_strncmp(lst->argv[1], "-n", ft_strlen(lst->argv[1])) == 0
			&& ft_strlen("-n") == ft_strlen(lst->argv[1]))
		{
			while (++i < num - 1)
				printf("%s ", lst->argv[i]);
			printf("%s", lst->argv[i]);
		}
		else
		{
			while (i < num - 1)
			{
				printf("%s ", lst->argv[i]);
				i++;
			}
			printf("%s\n", lst->argv[i]);
		}
	}
}
