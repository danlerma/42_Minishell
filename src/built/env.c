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

char	**get_var_env(t_mirage *env, char *var)
{
	while (env != NULL)
	{
		if (ft_strncmp(env->name, var, ft_strlen(var)) == 0)
		{
			printf("SI es \n");
		}
		env = env->next;
	}
	return (NULL);
}
