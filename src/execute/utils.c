/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:39:33 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/02 14:38:38 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	check_built(t_lst *lst, t_info *info, char *com)
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

char	**create_cmd(t_lst *lst, t_info *info)
{
	int		i;
	int		y;
	char	**str;

	str = (char **)ft_calloc(info->cmd->nc + 1, sizeof(char *));
	if (str == NULL)
		exit(0);
	i = 0;
	y = 0;
	while (lst->argv[i])
	{
		if (lst->type[i] == 1)
		{
			str[y] = ft_strdup(lst->argv[i]);
			y++;
		}
		i++;
	}
	return (str);
}

char	**find_path(char **environ)
{
	int		i;
	char	**paths;
	char	*pos;

	i = 0;
	paths = NULL;
	while (environ[i])
	{
		if (ft_strncmp(environ[i], "PATH", 4) == 0)
		{
			pos = ft_strchr(environ[i], '=');
			paths = ft_split(pos + 1, ':');
			break ;
		}
		i++;
	}
	return (paths);
}

void	valid_path(t_info *info)
{
	int		i;
	char	*aux;

	i = 0;
	while (info->paths[i])
		i++;
	info->path = ft_calloc(i + 1, sizeof(char *));
	if (info->path == NULL)
		exit(0);
	i = 0;
	while (info->paths[i])
	{
		aux = ft_strdup(info->paths[i]);
		info->path[i] = ft_strjoin(aux, "/");
		free(aux);
		i++;
	}
}

/*TEMP*/
void	error(char *file)
{
	perror(file);
	exit(0);
}
