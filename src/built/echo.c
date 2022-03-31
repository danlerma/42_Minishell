/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:29:18 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/31 15:02:19 by dlerma-c         ###   ########.fr       */
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

static void	norm_echo(t_lst *lst, int num)
{
	int	i;

	i = 1;
	while (++i < num - 1)
	{
		if (lst->argv[i] != NULL && lst->type[i] == 1)
		{
			write(1, lst->argv[i], ft_strlen(lst->argv[i]));
			write(1, " ", 1);
		}
	}
	if (lst->argv[i] != NULL && lst->type[i] == 1)
		write(1, lst->argv[i], ft_strlen(lst->argv[i]));
}

static void	cod_echo(t_lst *lst, int num)
{
	int	i;

	i = 1;
	if (ft_strncmp(lst->argv[1], "-n", ft_strlen(lst->argv[1])) == 0
		&& ft_strlen("-n") == ft_strlen(lst->argv[1]))
	{
		norm_echo(lst, num);
	}
	else
	{
		while (i < num - 1)
		{
			if (lst->type[i] == 1)
				printf("%s ", lst->argv[i]);
			i++;
		}
		if (lst->type[i] == 1)
			printf("%s\n", lst->argv[i]);
	}
}

void	make_echo(t_lst *lst)
{
	int	num;

	num = num_argv(lst);
	if (num == 1)
		printf("\n");
	else if (lst->argv[1] != NULL)
		cod_echo(lst, num);
	g_output_code = 0;
}
