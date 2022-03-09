/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:57:38 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/09 13:36:46 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	leaks(void)
{
	system("leaks -q minishell > exit");
}

int	main(void)
{
	char		*argv;
	t_lst		*nodes;
	t_list		*sep;
	t_mirage	*env;

	//atexit(leaks);
	g_output_code = 0;
	signal_declaration();
	env = init_env();
	while (1)
	{
		argv = readline(BLUE"Mini"YELLOW"Shell"RESET" ");
		if (argv == NULL)
			exit(0);
		add_history(argv);
		sep = split_data_rework(argv);
		nodes = create_nodes_rework(sep, env);
		if (nodes_check_error(nodes))
		{
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