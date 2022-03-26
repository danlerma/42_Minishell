/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:40:23 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/26 23:45:03 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

static void	wait_child(t_info *info)
{
	int	i;
	int	k;

	i = 0;
	while (i < info->nlst)
	{
		waitpid(-1, &k, 0);
		// if (g_general_data->g_output_code != 0 && WIFSIGNALED(k))
		// 	g_general_data->g_output_code += WTERMSIG(k) + 1;
		i++;
	}
}

void	make_process(t_info *info, t_lst *lst, t_env **env)
{
	int	i;

	i = 0;
	check_here(info, lst);
	if (g_general_data->signal_heredoc == 0)
	{
		while (lst)
		{
			info->pos = i;
			commands(info, lst, env);
			lst = lst->next;
			i++;
		}
		wait_child(info);
	}
}
