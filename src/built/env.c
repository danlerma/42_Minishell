/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:21:10 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/18 12:57:27 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

char	*get_val_env(t_mirage *env, char *var)
{
	while (env != NULL)
	{
		if (ft_strncmp(env->name, var, ft_strlen(env->name)) == 0
			&& ft_strlen(var) == ft_strlen(env->name))
			return(env->value);
		env = env->next;
	}
	return (NULL);
}

char	*get_name_env(t_mirage *env, char *var)
{
	while (env != NULL)
	{
		if (ft_strncmp(env->name, var, ft_strlen(env->name)) == 0
			&& ft_strlen(var) == ft_strlen(env->name))
			return(env->name);
		env = env->next;
	}
	return (NULL);
}

void	delete_var(t_mirage **env, char *var)
{
	t_mirage	*aux;
	t_mirage	*temp;

	aux = *env;
	while (aux != NULL)
	{
		if (ft_strncmp(aux->name, var, ft_strlen(aux->name)) == 0
			&& ft_strlen(var) == ft_strlen(aux->name))
		{
			if (aux->next == NULL)
				temp->next = NULL;
			else
				temp->next = aux->next;
			if (aux->mem == -1)
				free(aux->var);
			lstdelone_env(aux, free);
			free(aux);
			break;
		}
		temp = aux;
		aux = aux->next;
	}
}

void	change_val_env(t_mirage **env, char *var, char *value, char *all)
{
	t_mirage	*aux;

	aux = *env;
	while (aux != NULL)
	{
		if (ft_strncmp(aux->name, var, ft_strlen(aux->name)) == 0
			&& ft_strlen(var) == ft_strlen(aux->name))
		{
			if (aux->value)
				free(aux->value);
			free(aux->var);
			if (value != NULL)
				aux->value = ft_strdup(value);
			else
				aux->value = ft_strdup("");
			aux->var = ft_strdup(all);
			break ;
		}
		aux = aux->next;
	}
}


/*static void	change_dir(t_env **env, char *dir, char *msg, char *m)
{
	char	*old;

	printf("CAMBIO %s\n", dir);
	if (get_name_env((*env)->env, msg) != NULL)
	{
		delete_var(&(*env)->env, msg);
		delete_var(&(*env)->ex_env, msg);
	}
	else
	{
		old = ft_strjoin(m, dir);
		add_back_env(&(*env)->env, new_node_env(old));
		add_back_env(&(*env)->ex_env, new_node_env(old));
		free(old);
	}
}

static void	move_dir(t_lst *lst, t_info *info, t_env **env)
{
	char	**cmd;
	char	dir[4096];

	getcwd(dir, sizeof(dir));
	change_dir(env, dir, "OLDPWD", "OLDPWD=");
	cmd = create_cmd(lst, info);
	chdir(cmd[1]);
	free(cmd);
	getcwd(dir, sizeof(dir));
	change_dir(env, dir, "PWD", "PWD=");
}*/
