/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:32:42 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/26 21:15:27 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

static void	redir_out(t_info *info, t_lst *lst, char *file, int n)
{
	int	out;

	(void)info;
	(void)lst;
	out = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (out < 0)
	{
		perror(file);
		exit(EXIT_FAILURE);
	}
	if (n == 1)
		dup2(out, STDOUT_FILENO);
	close(out);
}

static void	redir_in(t_info *info, t_lst *lst, char *file, int n)
{
	int	in;

	(void)info;
	(void)lst;
	in = open(file, O_RDONLY);
	if (in < 0)
	{
		perror(file);
		exit(EXIT_FAILURE);
	}
	if (n == 1)
		dup2(in, STDIN_FILENO);
	close(in);
}

static void	redir_appd(t_info *info, t_lst *lst, char *file, int n)
{
	int	end;

	(void)info;
	(void)lst;
	end = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (end < 0)
	{
		perror(file);
		exit(EXIT_FAILURE);
	}
	if (n == 1)
		dup2(end, STDOUT_FILENO);
	close(end);
}

static void	redir_here(t_info *info, t_lst *lst, char *file, int n)
{
	char	*f;
	char	*nbr;

	(void)n;
	nbr = ft_itoa(info->pos);
	f = ft_strjoin(file, nbr);
	redir_in(info, lst, f, 1);
	free(f);
	free(nbr);
}

void	check_redir(t_info *info, t_lst *lst, int n)
{
	int	i;

	i = 0;
	while (lst->argv[i])
	{
		if (lst->type[i] == 4 && lst->type[i + 1])
			redir_out(info, lst, lst->argv[i + 1], n);
		if (lst->type[i] == 2 && lst->type[i + 1])
			redir_in(info, lst, lst->argv[i + 1], n);
		if (lst->type[i] == 7 && lst->type[i + 1])
			redir_appd(info, lst, lst->argv[i + 1], n);
		if (lst->type[i] == 6 && lst->argv[i + 1])
			redir_here(info, lst, "/tmp/.temp", 1);
		i++;
	}
}
