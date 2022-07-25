/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:37:32 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/30 17:15:36 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	no_path(t_lst *lst, t_info *info, t_env **env)
{
	char	*com;

	com = NULL;
	if (ft_strchr(lst->argv[info->cmd->pos], '/') != NULL)
		com = ft_strdup(lst->argv[info->cmd->pos]);
	if (access(com, X_OK) == 0)
	{
		search_command(info, lst, com, env);
		free (com);
	}
	else if (check_built(lst, info, env) == 0)
	{
		printf("%s: No such file or directory\n", lst->argv[info->cmd->pos]);
		g_output_code = 1;
	}
}

static int	with_path(t_lst *lst, t_info *info, t_env **env)
{
	char	*com;
	int		i;

	i = -1;
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
			return (1);
		}
		free(com);
	}
	return (0);
}

void	commands(t_info *info, t_lst *lst, t_env **env)
{
	int	flag;

	init_commands(lst, info);
	if (info->path == NULL)
		no_path(lst, info, env);
	else
	{
		flag = with_path(lst, info, env);
		if (flag == 0 && lst->type[info->cmd->pos] == 1 && lst->built != 1)
		{
			error_cmd(lst->argv[info->cmd->pos]);
			info->ex--;
		}
		else if (flag == 0)
			search_command(info, lst, NULL, env);
	}
}
