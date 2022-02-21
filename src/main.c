#include <minishell.h>

void	leaks()
{
	system("leaks -q minishell");
}

int	main(void)
{
	char	*argv;
	while (1)
	{
		argv = readline("\033[1;33m""Minishell ""\033[0m");
		add_history(argv);
	}
	return (0);
}
