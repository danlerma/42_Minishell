/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:35:29 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/02/24 15:41:52 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

void	init_commands(t_lst *lst, t_info *info)
{
	int	i;

	i = 0;
	info->cmd->pos = 0;
	info->cmd->nc = 0;
	while (lst->argv[i] != NULL)
	{
		if (lst->type[i] == 1 && info->cmd->nc == 0)
			info->cmd->pos = i;
		if (lst->type[i] == 1)
			info->cmd->nc++;
		i++;
	}
}

void	init_structs(t_lst **lst, t_info *info, char **environ)
{
	info->nlst = lstsize(*lst);
	info->paths = find_path(environ);
	valid_path(info);
	info->cmd = (t_command *)ft_calloc(1, sizeof(t_command));
	info->pipe = (int **)ft_calloc(info->nlst, sizeof(int *));
	if (info->cmd == NULL || info->pipe == NULL)
		exit(0);
	info->pos = 0;
	info->np = 0;
	info->iter = 0;
	// open_pipes(info);
}