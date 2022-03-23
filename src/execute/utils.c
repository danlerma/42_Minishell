/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:39:33 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/23 20:25:03 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
	if (ft_strchr(lst->argv[i], '/') != NULL)
	{
		str[i] = ft_strrchr(lst->argv[i], '/') + 1;
		i++;
		y++;
	}
	while (lst->argv[i])
	{
		if (lst->type[i] == 1)
		{
			str[y] = lst->argv[i];
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
	info->path = NULL;
	if (info->paths == NULL)
		return ;
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

void	error_cmd(char *str)
{
	if (ft_strchr(str, '/') == NULL)
	{
		g_general_data->g_output_code = 127;
		printf("%s: command not found\n", str);
	}
	else
	{
		g_general_data->g_output_code = 1;
		printf("%s: no such file or directory\n", str);
	}
}

int	heredoc_signal_check(int i)
{
	int	fd;
	int	check;

	check = 0;
	if (i == 1)
	{
		fd = open("/tmp/sig_clear", O_RDONLY, 0644);
		if (fd == -1)
			check = 1;
		close(fd);
		unlink("/tmp/sig_clear");
	}
	else
	{
		fd = open("/tmp/sig_clear", O_CREAT, 0644);
		write (fd, "0", 1);
		close(fd);
	}
	return (check);
}
