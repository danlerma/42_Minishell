/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:33:19 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/28 15:10:07 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	loop_heredoc(t_lst *lst, int pos, char *file)
{
	char	*line;
	int		f;

	line = readline("> ");
	if (line == NULL)
		return (1);
	if (ft_strncmp(line, lst->argv[pos], ft_strlen(lst->argv[pos])) == 0
		&& (ft_strlen(line)) == ft_strlen(lst->argv[pos]))
	{
		free(line);
		return (1);
	}
	f = open(file, O_RDWR | O_APPEND, line);
	if (f < 0)
		exit(0);
	write(f, line, ft_strlen(line));
	write(f, "\n", 1);
	close(f);
	free(line);
	return (0);
}

static void	make_heredoc(t_lst *lst, char *file, int pos)
{
	int		f1;
	pid_t	child;

	f1 = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0)
	{
		perror(file);
		exit(0);
	}
	child = fork();
	if (child < 0)
		exit(0);
	if (child == 0)
	{
		signal_heredoc();
		while (1)
			if (loop_heredoc(lst, pos, file) == 1)
				break ;
		heredoc_signal_check(0);
		exit(0);
	}
	wait(&child);
	close(f1);
}

static int	loop_check_here(t_lst *lst, t_info *info, int y, int n)
{
	int		i;
	char	*nbr;
	int		num;
	char	*file;

	i = 0;
	num = n;
	while (lst->argv[i] && g_general_data->signal_heredoc == 0)
	{
		if (lst->type[i] == 6)
		{
			nbr = ft_itoa(y);
			file = ft_strjoin("/tmp/.temp", nbr);
			make_heredoc(lst, file, i + 1);
			free(file);
			free(nbr);
			if (heredoc_signal_check(1))
				g_general_data->signal_heredoc = 1;
			info->nh = num;
			num++;
		}
		i++;
	}
	return (num);
}

void	check_here(t_info *info, t_lst *lst)
{
	int		y;
	int		num;

	num = 0;
	y = 0;
	g_general_data->signal_heredoc = 0;
	while (lst)
	{
		num = loop_check_here(lst, info, y, num);
		if (g_general_data->signal_heredoc == 1)
			break ;
		lst = lst->next;
		y++;
	}
	if (info->nh == 0)
		info->nh = -1;
}
