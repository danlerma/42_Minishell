/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:57:38 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/04 14:29:55 by mortiz-d         ###   ########.fr       */
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

void	show_recorded_lst(t_list *argv)
{
	t_list	*aux;

	aux = argv;
	while (aux)
	{
		printf("Palabra : %s - %p\n", aux->content, aux->content);
		aux = aux->next;
	}
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
			printf("Argv - %s - %p\n", aux->argv[i], aux->argv[i]);
			printf("Type - %i\n", aux->type[i]);
			printf("Flag - %i\n", aux->flag[i]);
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
	char		*argv;
	t_lst		*nodes;
	t_list		*sep;
	t_mirage	*env;

	//atexit(leaks);
	signal(EOF, signal_control);
	signal(SIGINT, signal_control);
	signal(SIGQUIT, signal_control);
	env = init_env();
	while (1)
	{
		argv = readline(BLUE"Mini"YELLOW"Shell"RESET" ");
		if (argv == NULL)
			exit(0);
		//argv = readline("MINISHELL ");

		add_history(argv);
		sep = split_data_rework(argv);
		//show_recorded_lst(sep);
		nodes = create_nodes_rework(sep);
		nodes = set_data_nodes(nodes, env);
		if (nodes_check_error(nodes))
		{
			//show_nodes(nodes);
			//printf("JAJA VOY A EJECUTAR EL CODIGO\n");
			exec(nodes, &env);
		}
		free_nodes(nodes);
		free_argv(sep, argv);
		//system("leaks -q minishell");
	}
	lstclear_env(&env, free);
	return (0);
}
//system("leaks -q minishell");
//s_mirage(env);