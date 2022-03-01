/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:57:38 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/01 16:12:02 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	leaks()
{
	system("leaks -q minishell");
	//> > leaks_texto
}

void	signal_control(int signum)
{
	printf("\nSignal %i\n",signum);
	if (signum == SIGINT)
	{
		printf("\n");
		exit (0);
	}
	else if (signum == SIGQUIT)
		printf("Control 4 llamado\n");
}

void	show_recorded(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != 0)
	{
		printf("%s\n",argv[i++]);
	}
	printf("\n");
}

void	show_nodes(t_lst *nodes)
{
	int		i;
	int		nodes_i;
	t_lst	*aux;

	aux = nodes;
	nodes_i = 1;
	i = 0;
	while (aux)
	{
		printf("Node %i :\n", nodes_i);
		while (aux->argv[i] != 0)
		{
			printf("Argv - %s\n",aux->argv[i]);
			printf("Type - %i\n",aux->type[i]);
			printf("Flag - %i\n",aux->flag[i]);
			printf("\n");
			i++;
		}
		i = 0;
		aux = aux->next;
		nodes_i++;
	}
}

int	main(void)
{
	char	*argv;
	char	**sep;
	t_lst	*nodes;

	// atexit(leaks);
	signal(EOF, signal_control);
	signal(SIGINT, signal_control);
	signal(SIGQUIT, signal_control);
	while (1)
	{
		argv = readline("\033[1;34m""Mini""\033[1;33m""Shell""\033[0m"" ");
		add_history(argv);
		//__________________
		sep = split_data(argv);
		nodes = create_nodes(sep);
		nodes = set_data_nodes(nodes);
		if (nodes_check_error(nodes))
		{
			//show_recorded(sep);
			//show_nodes(nodes);
			exec(nodes);
		}
		free_nodes(nodes);
		free_argv(sep, argv);
	}
	return (0);
}
/*
		argv = readline("\033[1;34m""Mini""\033[1;33m""Shell""\033[0m"" ");
		//printf("\033[0m""");
		add_history(argv);
		sep = split_data(argv);
		nodes = create_nodes(sep);
		printf("NO PETA\n");
		nodes = set_data_nodes(nodes);
		//show_recorded(sep);
		show_nodes(nodes);
		exec(nodes);
		free_nodes(nodes);
		free_argv(sep, argv);*/