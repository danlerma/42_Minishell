#include <pipes.h>

static void	wait_child(t_info *info)
{
	int	i;
	int	*k;

	i = 0;
	k = NULL;
	while (i < info->nlst)
	{
		waitpid(-1, k, 0);
		i++;
	}
}

static void	make_heredoc(t_info *info, t_lst *lst, char *file, int pos)
{
	char	*line;
	int		f;

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
	
}

static void	check_here(t_info *info, t_lst *lst)
{
	int		i;
	int		f;
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
				f = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
				if (f < 0)
					error(file);
				make_heredoc(info, lst, file, i + 1);
				free(file);
				free(nbr);
				close(f);
				info->nh = num;
				num++;
			}
			i++;
		}
		lst = lst->next;
	}
}

/*
	Según los argumentos, va a redirigir a sitios 
	donde se van a crear los procesos
		info->estructura principal de datos
		environ-> datos de env
*/
void	make_process(t_info *info, t_lst *lst, char **environ)
{
	int	i;

	i = 0;
	check_here(info, lst);
	while (lst)
	{
		info->pos = i;
		commands(info, lst, environ);
		lst = lst->next;
		i++;
	}
	wait_child(info);
}
