/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:41:41 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/30 14:12:25 by mortiz-d         ###   ########.fr       */
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

static void	free_all(t_info *info)
{
	free(info->cmd);
	free_pipes(info->pipe, info->nlst);
	if (info->paths)
		ft_free_malloc(info->paths);
	free(info->env);
	if (info->path)
		ft_free_malloc(info->path);
}

void	exec(t_lst *lst, t_env **env)
{
	t_info		info;

	signal_ing();
	init_structs(&lst, &info, (*env)->env);
	make_process(&info, lst, env);
	dup2(info.fd_in, STDIN_FILENO);
	dup2(info.fd_out, STDOUT_FILENO);
	close(info.fd_in);
	close(info.fd_out);
	free_all(&info);
}
