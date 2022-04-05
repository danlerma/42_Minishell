/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:21:10 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/04/05 18:50:50 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

char	*get_val_env(t_mirage *env, char *var)
{
	while (env != NULL)
	{
		if (ft_strncmp(env->name, var, ft_strlen(env->name)) == 0
			&& ft_strlen(var) == ft_strlen(env->name))
			return (env->value);
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
			return (env->name);
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
			break ;
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
			if (aux->mem != 0)
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
	if (aux->mem == 0)
		aux->mem = -1;
}
