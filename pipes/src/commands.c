/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:37:32 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/02/22 17:35:40 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipes.h>

static void	make_last_command(t_info *info, t_lst *lst, char **env, char *com)
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
		execve(com, cmd, env);
	}
	else
	{
		close(info->pipe[info->np][1]);
		dup2(info->pipe[info->np][0], STDIN_FILENO);
		close(info->pipe[info->np][0]);
		ft_free_malloc(cmd);
	}
}

static void	make_command(t_info *info, t_lst *lst, char **env, char *com)
{
	pid_t	child;
	char	**cmd;

	cmd = create_cmd(lst, info);
	child = fork();
	if (child < 0 || info->pipe[info->np] < 0)
		exit(0);
	if (child == 0)
	{
		close(info->pipe[info->np][0]);
		dup2(info->pipe[info->np][1], STDOUT_FILENO);
		close(info->pipe[info->np][1]);
		check_redir(info, lst, 1);
		execve(com, cmd, env);
	}
	else
	{
		close(info->pipe[info->np][1]);
		dup2(info->pipe[info->np][0], STDIN_FILENO);
		close(info->pipe[info->np][0]);
		ft_free_malloc(cmd);
	}
}

static void	make_one_command(t_info *info, t_lst *lst, char **env, char *com)
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
		execve(com, cmd, env);
	}
	else
	{
		wait(&child);
		ft_free_malloc(cmd);
	}
}

static void	search_command(t_info *info, t_lst *lst, char **environ, char *com)
{
	if (info->nlst == 1 || (info->pos == info->nlst - 1 && info->nc >= 1))
		make_one_command(info, lst, environ, com);
	else
	{
		info->pipe[info->np] = (int *)ft_calloc(2, sizeof(int));
		if (info->pipe[info->np] == NULL)
			exit(0);
		pipe(info->pipe[info->np]);
		if ((info->pos == 0 || info->pos != 0) && info->pos != info->nlst - 1)
			make_command(info, lst, environ, com);
		else if (info->pos == info->nlst - 1)
			make_last_command(info, lst, environ, com);
		info->np++;
	}
}

void	commands(t_info *info, t_lst *lst, char **environ)
{
	int		i;
	char	*com;

	init_commands(lst, info);
	i = -1;
	while (info->path[++i])
	{
		com = ft_strjoin(info->path[i], lst->argv[info->cmd->pos]);
		if (access(com, X_OK) == 0)
		{
			search_command(info, lst, environ, com);
			free (com);
			info->nc = -200;
			break ;
		}
		free(com);
	}
	info->nc++;
}
