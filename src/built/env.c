/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:21:10 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/02 18:33:48 by dlerma-c         ###   ########.fr       */
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
