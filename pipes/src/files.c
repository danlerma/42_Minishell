#include<pipes.h>

static void	redir_out(t_info *info, t_lst *lst, char *file, int n)
{
	int	out;

	out = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (out < 0)
		error(file);
	if (n == 1)
		dup2(out, STDOUT_FILENO);
	close(out);
}

static void	redir_in(t_info *info, t_lst *lst, char *file, int n)
{
	int	in;

	in = open(file, O_RDONLY);
	if (in < 0)
		error(file);
	if (n == 1)
		dup2(in, STDIN_FILENO);
	close(in);
}

static void	redir_appd(t_info *info, t_lst *lst, char *file, int n)
{
	int	end;

	end = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (end < 0)
		error(file);
	if (n == 1)
		dup2(end, STDOUT_FILENO);
	close(end);
}

static void	redir_here(t_info *info, t_lst *lst, char *file, int n)
{
	int		in;
	char	*f;
	char	*nbr;

	nbr = ft_itoa(info->nh);
	f = ft_strjoin(file, nbr);
	in = open(f, O_RDONLY);
	if (in < 0)
		error(f);
	if (n == 1)
		dup2(in, STDIN_FILENO);
	close(in);
	free(f);
	free(nbr);
	info->nh++;
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
