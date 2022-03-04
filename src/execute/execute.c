/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:41:41 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/02 14:39:08 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	free_pipes(int **pipe, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		free(pipe[i]);
		i++;
	}
	free(pipe);
}

static void	free_all(t_info *info, t_lst **lst)
{
	(void)lst;
	// lstclear(lst, free);
	free(info->cmd);
	free_pipes(info->pipe, info->nlst);
	ft_free_malloc(info->paths);
	ft_free_malloc(info->path);
}

void	exec(t_lst *lst, t_mirage **env)
{
	extern char	**environ;
	t_info		info;

	// s_list(lst);
	(void)env;
	init_structs(&lst, &info, environ);
	make_process(&info, lst);
	dup2(info.fd_in, STDIN_FILENO);
	dup2(info.fd_out, STDOUT_FILENO);
	free_all(&info, &lst);
}
