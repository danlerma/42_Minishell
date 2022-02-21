#include <pipes.h>

/*
	Abrir todas las pipes +1 de momento
*/
void	open_pipes(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nlst)
	{
		info->pipe[i] = (int *)ft_calloc(2, sizeof(int));
		if (info->pipe[i] == NULL)
			exit(0);
		pipe(info->pipe[i]);
		i++;
	}
}

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
	while (lst->argv[i])
	{
		if (lst->type[i] == 1)
		{
			str[y] = ft_strdup(lst->argv[i]);
			y++;
		}
		i++;
	}
	return (str);
}

/*
	Busca en env la PATH y almacena la ruta
		environ-> datos de env
*/
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

/*
	Transforma la path guardada a una path que se pueda 
	ejecutar añadiendo un comando
		info->estructura principal de datos
*/
void	valid_path(t_info *info)
{
	int		i;
	char	*aux;

	i = 0;
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
