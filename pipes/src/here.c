/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:33:19 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/02/23 19:47:37 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipes.h>

static void	make_heredoc(t_lst *lst, char *file, int pos)
{
	char	*line;
	int		f;

	f = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f < 0)
		error(file);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(line, lst->argv[pos], ft_strlen(lst->argv[pos])) == 0
			&& ((int)ft_strlen(line) - 1) == ft_strlen(lst->argv[pos]))
		{
			free(line);
			break ;
		}
		f = open(file, O_RDWR | O_APPEND, line);
		if (f < 0)
			exit(0);
		write(f, line, ft_strlen(line));
		close(f);
		free(line);
	}
	close(f);
}

void	check_here(t_info *info, t_lst *lst)
{
	int		i;
	int		num;
	char	*nbr;
	char	*file;

	num = 0;
	while (lst)
	{
		i = 0;
		while (lst->argv[i])
		{
			if (lst->type[i] == 6)
			{
				nbr = ft_itoa(num);
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
	}
	if (info->nh == 0)
		info->nh = -1;
}
