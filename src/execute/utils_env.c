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
		make_export(lst, info, com);
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
