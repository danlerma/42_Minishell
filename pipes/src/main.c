#include <pipes.h>
//valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./pipes ls ">" salida -l ">" salida2 -a "|" wc "|"
void	leaks(void)
{
	system("leaks -q pipes\n");
}

static void	free_pipes(int **pipe, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		free(pipe[i]);
		i++;
	}
	free(pipe);
}

static void	free_all(t_info *info, t_lst **lst)
{
	lstclear(lst, free);
	free(info->cmd);
	free_pipes(info->pipe, info->nlst);
	ft_free_malloc(info->paths);
	ft_free_malloc(info->path);
}

int	main(int argc, char **argv)
{
	extern char	**environ;
	t_lst		*lst;
	t_info		info;

	// atexit(leaks);
	lst = NULL;
	lst = argv_init_temp(argv, argc);
	// s_list(lst);
	init_structs(&lst, &info, environ);
	make_process(&info, lst, environ);
	free_all(&info, &lst);
	return (0);
}
