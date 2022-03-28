/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:37:32 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/25 18:22:30 by mortiz-d         ###   ########.fr       */
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
		printf("%s: no such file or directory\n", lst->argv[info->cmd->pos]);
		g_general_data->g_output_code = 1;
		printf("a?\n");
	}
		
}

static void	with_path(t_lst *lst, t_info *info, t_env **env)
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
	if (flag == 0 && lst->type[info->cmd->pos] == 1 && lst->built != 1)
		error_cmd(lst->argv[info->cmd->pos]);
	else if (flag == 0)
		search_command(info, lst, NULL, env);
}

void	commands(t_info *info, t_lst *lst, t_env **env)
{
	init_commands(lst, info);
	if (info->path == NULL)
		no_path(lst, info, env);
	else
		with_path(lst, info, env);
}
