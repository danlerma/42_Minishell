/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:09:10 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/18 12:24:28 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

static void	exec_exit(int exit_code, t_lst *lst, t_info *info, char *com)
{
	(void)com;
	(void)lst;
	(void)info;
	exit(exit_code);
}

int	check_numeric_arg(t_lst *lst)
{
	char	*str;
	int		exit_nbr;
	int		check;

	check = 1;
	exit_nbr = ft_atoi(lst->argv[1]);
	str = ft_itoa(exit_nbr);
	if (ft_strncmp(lst->argv[1], str, sizeof(lst->argv[1])) != 0)
	{
		printf("bash: exit: %s: numeric argument required\n", lst->argv[1]);
		free(str);
		check = 0;
	}
	else
		free(str);
	return (check);
}

void	make_exit(t_lst *lst, t_info *info, char *com)
{
	printf("exit\n");
	if (lst->n_words <= 2)
	{
		if (lst->n_words == 2)
		{
			if (check_numeric_arg(lst))
				exec_exit(ft_atoi(lst->argv[1]), lst, info, com);
		}
		else
			exec_exit(0, lst, info, com);
	}
	else
		printf("bash: exit: too many arguments\n");
}
