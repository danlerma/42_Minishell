#include<pipes.h>

/*
	Dentro del nodo, saber cual es la posicion donde esta
	el comando y cuantas partes de comando hay.
	Si se diese el caso que no hay ningun comando, se pone la posicion
	a 0 por defecto, para que no haya segfault.
		lst->lista de parseo
		info->estructura principal de datos
*/
void	init_commands(t_lst *lst, t_info *info)
{
	int	i;

	i = -1;
	info->cmd->pos = -1;
	info->cmd->nc = 0;
	while (lst->argv[++i] != NULL)
	{
		if (lst->type[i] == 1 && info->cmd->pos == -1)
			info->cmd->pos = i;
		if (lst->type[i] == 1)
			info->cmd->nc++;
	}
	if (info->cmd->pos == -1)
	{
		check_redir(info, lst, 0);
		info->cmd->pos = 0;
	}
}

/*
	Inicializa todos los valores de las estructuras
		lst->lista de parseo
		info->estructura principal de datos
		environ-> datos de env
*/
void	init_structs(t_lst **lst, t_info *info, char **environ)
{
	info->nlst = lstsize(*lst);
	info->paths = find_path(environ);
	valid_path(info);
	info->cmd = (t_command *)ft_calloc(1, sizeof(t_command));
	info->pipe = (int **)ft_calloc(info->nlst, sizeof(int *));
	if (info->cmd == NULL || info->pipe == NULL)
		exit(0);
	info->pos = 0;
	info->np = 0;
	info->nc = 0;
	open_pipes(info);
}
