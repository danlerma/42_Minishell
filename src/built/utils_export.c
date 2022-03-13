/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:40:02 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/08 17:08:29 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

void	show_export(t_mirage *env)
{
	while (env != NULL)
	{
		if (ft_strchr(env->var, '=') == NULL)
			printf("declare -x %s\n", env->name);
		else
			printf("declare -x %s=\"%s\"\n", env->name, env->value);
		env = env->next;
	}
}

static void	norm_export(t_mirage **head, t_mirage **env)
{
	t_mirage	*aux;

	if (ft_strncmp((*head)->name, (*head)->next->name, ft_strlen((*head)->name)
			+ ft_strlen((*head)->next->name)) > 0)
	{
		aux = (*head);
		(*head) = aux->next;
		aux->next = aux->next->next;
		(*head)->next = aux;
		(*env) = (*head);
	}
}

int	cond_export(t_mirage **head, t_mirage **env, int i)
{
	t_mirage	*aux;

	if (i == 0)
		norm_export(head, env);
	else if (i != 0 && (*env)->next->next != NULL)
	{
		if (ft_strncmp((*env)->next->name, (*env)->next->next->name,
				ft_strlen((*env)->next->name)
				+ ft_strlen((*env)->next->next->name)) > 0)
		{
			aux = (*env)->next;
			(*env)->next = aux->next;
			aux->next = (*env)->next->next;
			(*env)->next->next = aux;
		}
		(*env) = (*env)->next;
	}
	return (1);
}
