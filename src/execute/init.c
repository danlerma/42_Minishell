/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:35:29 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/02 17:54:46 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

t_mirage	*init_env(void)
{
	extern char		**environ;
	t_mirage		*temp;
	t_mirage		*env;
	int				i;

	i = 0;
	env = NULL;
	while (environ[i])
	{
		temp = (t_mirage *)ft_calloc(1, sizeof(t_mirage));
		if (temp == NULL)
			exit(0);
		temp->var = environ[i];
		split_variables(environ[i], &temp);
		temp->next = NULL;
		add_back_env(&env, temp);
		i++;
	}
	return (env);
}

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

void	init_structs(t_lst **lst, t_info *info, t_mirage *env)
{
	info->fd_in = dup(STDIN_FILENO);
	info->fd_out = dup(STDOUT_FILENO);
	info->env = lst2array(env);
	info->nlst = lstsize(*lst);
	info->paths = find_path(info->env);
	valid_path(info);
	info->cmd = (t_command *)ft_calloc(1, sizeof(t_command));
	info->pipe = (int **)ft_calloc(info->nlst, sizeof(int *));
	if (info->cmd == NULL || info->pipe == NULL)
		exit(0);
	info->pos = 0;
	info->np = 0;
	info->iter = 0;
}
