/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:33:19 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/08 17:36:39 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	make_heredoc(t_lst *lst, char *file, int pos)
{
	char	*line;
	int		f1;
	int		f2;

	f1 = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0)
		error(file);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			break ;
		if (ft_strncmp(line, lst->argv[pos], ft_strlen(lst->argv[pos])) == 0
			&& (ft_strlen(line) - 1) == ft_strlen(lst->argv[pos]))
		{
			free(line);
			break ;
		}
		f2 = open(file, O_RDWR | O_APPEND, line);
		if (f2 < 0)
			exit(0);
		write(f2, line, ft_strlen(line));
		close(f2);
		free(line);
	}
	close(f1);
}

void	check_here(t_info *info, t_lst *lst)
{
	int		i;
	int		y;
	int		num;
	char	*nbr;
	char	*file;

	num = 0;
	y = 0;
	while (lst)
	{
		i = 0;
		while (lst->argv[i])
		{
			if (lst->type[i] == 6)
			{
				nbr = ft_itoa(y);
				file = ft_strjoin("/tmp/.temp", nbr);
				make_heredoc(lst, file, i + 1);
				free(file);
				free(nbr);
				info->nh = num;
				num++;
			}
			i++;
		}
		lst = lst->next;
		y++;
	}
	if (info->nh == 0)
		info->nh = -1;
}
