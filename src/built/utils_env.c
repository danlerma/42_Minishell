/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:45:04 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/08 17:44:39 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

int	check_built(t_lst *lst, t_info *info, char *com, t_mirage **env)
{
	if (ft_strncmp(lst->argv[0], "cd", ft_strlen(lst->argv[0])) == 0)
	{
		make_cd(lst, info, com);
		info->built = 1;
	}
	if (ft_strncmp(lst->argv[0], "exit", ft_strlen(lst->argv[0])) == 0)
	{
		make_exit(lst, info, com);
		info->built = 1;
	}
	if (ft_strncmp(lst->argv[0], "export", ft_strlen(lst->argv[0])) == 0)
	{
		make_export(lst, info, env);
		info->built = 1;
	}
	if (ft_strncmp(lst->argv[0], "unset", ft_strlen(lst->argv[0])) == 0)
	{
		make_unset(lst, info, env);
		info->built = 1;
	}
	return (info->built);
}

void	split_variables(char *variable, t_mirage **env)
{
	char	**var;

	var = ft_split(variable, '=');
	(*env)->name = var[0];
	(*env)->value = var[1];
	free(var);

}
//TODO liberar
char	**lst2array(t_mirage *env)
{
	char	**arr;
	int		i;

	arr = (char **)ft_calloc(lstsize_env(env) + 1, sizeof(char*));
	if (arr == NULL)
		exit(0);
	i = 0;
	while (env != NULL)
	{
		arr[i] = env->var;
		env = env->next;
		i++;
	}
	return (arr);
}

int	is_sorted(t_mirage **stack, int num)
{
	t_mirage	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (i < num - 1 && temp->next != NULL)
	{
		if (ft_strncmp(temp->name, temp->next->name, ft_strlen(temp->name) + ft_strlen(temp->next->name)) > 0)
			return (1);
		temp = temp->next;
		i++;
	}
	return (0);
}