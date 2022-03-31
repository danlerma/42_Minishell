/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:13:58 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/31 16:38:37 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

t_mirage	*new_node_env(char *cont)
{
	t_mirage	*node;

	node = (t_mirage *)ft_calloc(1, sizeof(t_mirage));
	if (node == NULL)
		exit(EXIT_FAILURE);
	node->var = ft_strdup(cont);
	split_variables(cont, &node);
	node->mem = -1;
	node->next = NULL;
	return (node);
}

static void	change_dir(t_env **env, char *dir, char *msg, char *m)
{
	char	*old;

	if (get_name_env((*env)->env, msg) != NULL)
	{
		delete_var(&(*env)->env, msg);
		delete_var(&(*env)->ex_env, msg);
	}
	old = ft_strjoin(m, dir);
	add_back_env(&(*env)->env, new_node_env(old));
	add_back_env(&(*env)->ex_env, new_node_env(old));
	free(old);
}

static void	move_dir(t_lst *lst, t_info *info, t_env **env)
{
	char	**cmd;
	char	dir[4096];

	getcwd(dir, sizeof(dir));
	change_dir(env, dir, "OLDPWD", "OLDPWD=");
	cmd = create_cmd(lst, info);
	if (chdir(cmd[1]) == -1)
	{
		g_output_code = 1;
		printf("cd: %s: No such file or directory\n", cmd[1]);
	}
	free(cmd);
	getcwd(dir, sizeof(dir));
	change_dir(env, dir, "PWD", "PWD=");
}

static void	move_home(t_env **env)
{
	char	*home;
	char	dir[4096];

	home = get_val_env((*env)->env, "HOME");
	if (home != NULL)
	{
		getcwd(dir, sizeof(dir));
		change_dir(env, dir, "OLDPWD", "OLDPWD=");
		chdir(home);
		getcwd(dir, sizeof(dir));
		change_dir(env, dir, "PWD", "PWD=");
	}
	else
		printf("cd: HOME not set\n");
}

void	make_cd(t_lst *lst, t_info *info, t_env **env)
{
	if (lst->argv[1] == NULL)
		move_home(env);
	else if (ft_strncmp(lst->argv[1], "-", 1) == 0
		&& ft_strlen(lst->argv[1]) == 1)
	{
		if (get_name_env((*env)->env, "OLDPWD") == NULL)
			printf("cd: OLDPWD not set\n");
		else
			printf("%s\n", get_val_env((*env)->env, "OLDPWD"));
	}
	else if (ft_strncmp(lst->argv[1], "-", 1) != 0)
		move_dir(lst, info, env);
}
