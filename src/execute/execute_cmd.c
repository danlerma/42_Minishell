/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:03:39 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/11 14:04:33 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

static void	make_last_command(t_info *info, t_lst *lst, char *com, t_mirage **e)
{
	pid_t	child;
	char	**cmd;

	cmd = create_cmd(lst, info);
	info->np--;
	child = fork();
	if (child < 0 || info->pipe[info->np] < 0)
		exit(0);
	if (child == 0)
	{
		check_redir(info, lst, 1);
		close(info->pipe[info->np][0]);
		close(info->pipe[info->np][1]);
		if (execve(com, cmd, info->env) == -1)
			perror("EXCV LAST");
	}
	else
	{
		close(info->pipe[info->np][1]);
		dup2(info->pipe[info->np][0], STDIN_FILENO);
		close(info->pipe[info->np][0]);
		free(cmd);
	}
}

static void	make_command(t_info *info, t_lst *lst, char *com, t_mirage **env)
{
	pid_t	child;
	char	**cmd;

	cmd = create_cmd(lst, info);
	child = fork();
	if (child < 0 || info->pipe[info->np] < 0)
		exit(0);
	if (child == 0)
	{
		if (com == NULL)
		{
			check_redir(info, lst, 0);
			exit(0);
		}
		close(info->pipe[info->np][0]);
		dup2(info->pipe[info->np][1], STDOUT_FILENO);
		close(info->pipe[info->np][1]);
		check_redir(info, lst, 1);
		if (execve(com, cmd, info->env) == -1)
			perror("EXCV");
	}
	else
	{
		close(info->pipe[info->np][1]);
		dup2(info->pipe[info->np][0], STDIN_FILENO);
		close(info->pipe[info->np][0]);
		free(cmd);
	}
}
//TODO LIBERAR
static void	make_one_command(t_info *info, t_lst *lst, char *com)
{
	pid_t	child;
	char	**cmd;

	cmd = create_cmd(lst, info);
	child = fork();
	if (child < 0)
		exit(0);
	if (child == 0)
	{
		check_redir(info, lst, 1);
		if (execve(com, cmd, info->env) == -1)
			perror("EXECV");
	}
	else
	{
		wait(&child);
		free(cmd);
	}
}

void	search_command(t_info *info, t_lst *lst, char *com, t_mirage **env)
{
	if (info->nlst == 1)
	{
		if (check_built(lst, info, com, env) == 0)
			make_one_command(info, lst, com);
	}
	else
	{
		info->pipe[info->np] = (int *)ft_calloc(2, sizeof(int));
		if (info->pipe[info->np] == NULL)
			exit(0);
		pipe(info->pipe[info->np]);
		if ((info->pos == 0 || info->pos != 0) && info->pos != info->nlst - 1)
			make_command(info, lst, com, env);
		else if (info->pos == info->nlst - 1)
			make_last_command(info, lst, com, env);
		info->np++;
	}
}
