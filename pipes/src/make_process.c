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
	while (lst)
	{
		info->pos = i;
		commands(info, lst, environ);
		lst = lst->next;
		i++;
	}
	wait_child(info);
}
