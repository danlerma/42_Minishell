/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:40:23 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/02 14:38:24 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

static void	wait_child(t_info *info)
{
	int	i;
	int	*k;

	i = 0;
	k = NULL;
	while (i < info->nlst)
	{
		waitpid(-1, k, 0);
		i++;
	}
}

void	make_process(t_info *info, t_lst *lst)
{
	int	i;

	i = 0;
	check_here(info, lst);
	while (lst)
	{
		info->pos = i;
		commands(info, lst);
		lst = lst->next;
		i++;
	}
	wait_child(info);
}
