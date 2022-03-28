/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:12:34 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/26 23:45:43 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

void	norm_cmd_child(t_lst *lst, t_info *info, char *com)
{
	if (com == NULL)
	{
		check_redir(info, lst, 0);
		exit(EXIT_SUCCESS);
	}
}

void	norm_cmd_father(t_info *info, char **cmd)
{
	close(info->pipe[info->np][1]);
	dup2(info->pipe[info->np][0], STDIN_FILENO);
	close(info->pipe[info->np][0]);
	free(cmd);
}
