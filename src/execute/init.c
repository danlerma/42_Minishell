/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:35:29 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/30 15:45:27 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

t_env	*init_env(void)
{
	extern char		**environ;
	t_mirage		*temp;
	t_env			*env_ret;
	int				i;

	i = 0;
	env_ret = (t_env *)ft_calloc(1, sizeof(t_env));
	if (env_ret == NULL)
		exit(EXIT_FAILURE);
	while (environ[i])
	{
		temp = (t_mirage *)ft_calloc(1, sizeof(t_mirage));
		if (temp == NULL)
			exit(EXIT_FAILURE);
		temp->var = environ[i];
		split_variables(environ[i], &temp);
		temp->next = NULL;
		add_back_env(&env_ret->env, temp);
		i++;
	}
	env_ret->ex_env = lstnew_env(&env_ret->env);
	return (env_ret);
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
	info->built = 0;
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
		exit(EXIT_FAILURE);
	info->pos = 0;
	info->np = 0;
	info->ex = 0;
	info->iter = 0;
	info->built = 0;
}
