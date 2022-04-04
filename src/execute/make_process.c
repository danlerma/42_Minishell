/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:40:23 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/30 17:30:22 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

static void	wait_child(t_info *info)
{
	int	i;
	int	*k;
	int	signaled;

	i = 0;
	signaled = 0;
	k = ft_calloc(sizeof(int), 1);
	while (i < info->nlst)
	{
		waitpid(-1, k, 0);
		if ((*k == 2 || *k == 3) && signaled == 0)
		{
			printf("\n");
			signaled = 1;
		}
		i++;
	}
	free(k);
}

void	make_process(t_info *info, t_lst *lst, t_env **env)
{
	int	i;

	i = 0;
	check_here(info, lst);
	if (g_output_code == 0)
	{
		while (lst)
		{
			g_output_code = 0;
			info->pos = i;
			commands(info, lst, env);
			lst = lst->next;
			i++;
		}
		wait_child(info);
	}
	else
	{
		printf("\n");
	}
}
