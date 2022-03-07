/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:45:04 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/02 17:53:18 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

int	check_built(t_lst *lst, t_info *info, char *com, t_mirage **env)
{
	int	check;

	check = 0;
	if (ft_strncmp(lst->argv[0], "cd", ft_strlen(lst->argv[0])) == 0)
	{
		check = 1;
		printf("CD\n");
		make_cd(lst, info, com);
	}
	if (ft_strncmp(lst->argv[0], "exit", ft_strlen(lst->argv[0])) == 0)
	{
		check = 1;
		printf("EXIT\n");
		make_exit(lst, info, com);
	}
	if (ft_strncmp(lst->argv[0], "export", ft_strlen(lst->argv[0])) == 0)
	{
		check = 1;
		printf("EXPORT\n");
		make_export(lst, info, env);
	}
	if (ft_strncmp(lst->argv[0], "unset", ft_strlen(lst->argv[0])) == 0)
	{
		check = 1;
		make_unset(lst, info, env);
	}
	return (check);
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
		printf(RED"IS SORT?  %s next %s"RESET"\n", temp->name, temp->next->name);
		if (ft_strncmp(temp->name, temp->next->name, ft_strlen(temp->name)) > 0)
		{
			printf("SORT I(%d) %s %s %s\n", i, temp->name, temp->name, temp->next->name);
			return (1);
		}
		temp = temp->next;
		i++;
	}
	return (0);
}
