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
				free(file);
				free(nbr);
				// lst->type[i] = 4;
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
