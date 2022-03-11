/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:37:32 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/11 18:06:25 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	no_path(t_lst *lst, t_info *info, t_mirage **env)
{
	char	*com;

	if (ft_strchr(lst->argv[info->cmd->pos], '/') != NULL)
			com = ft_strdup(lst->argv[info->cmd->pos]);
	if (access(com, X_OK) == 0)
	{
		search_command(info, lst, com, env);
		free (com);
	}
	else
		perror(lst->argv[info->cmd->pos]);
}

static void	with_path(t_lst *lst, t_info *info, t_mirage **env)
{
	char	*com;
	int		i;
	int		flag;

	i = -1;
	flag = 0;
	while (info->path[++i])
	{
		if (ft_strchr(lst->argv[info->cmd->pos], '/') != NULL)
			com = ft_strdup(lst->argv[info->cmd->pos]);
		else
			com = ft_strjoin(info->path[i], lst->argv[info->cmd->pos]);
		if (access(com, X_OK) == 0)
		{
			search_command(info, lst, com, env);
			free (com);
			flag = 1;
			return ;
		}
		free(com);
	}
	if (flag == 0 && lst->type[info->cmd->pos] == 1 && ft_strchr(lst->argv[info->cmd->pos], '/') != NULL)
		error_cmd(lst->argv[info->cmd->pos]);
	else if (flag == 0)
		search_command(info, lst, NULL, env);
}

void	commands(t_info *info, t_lst *lst, t_mirage **env)
{
	int		i;
	int		flag;
	char	*com;

	init_commands(lst, info);
	i = -1;
	flag = 0;
	if (info->path == NULL)
		no_path(lst, info, env);
	else
		with_path(lst, info, env);
}
