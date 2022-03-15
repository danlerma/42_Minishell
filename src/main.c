/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:57:38 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/15 18:23:46 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	leaks(void)
{
	system("leaks -q minishell");
}

static void	free_env(t_env **env_lst)
{
	lstclear_env(&(*env_lst)->env, free);
	lstclear_env(&(*env_lst)->ex_env, free);
	free(*env_lst);
}

int	main(void)
{
	char	*argv;
	t_lst	*nodes;
	t_env	*env_lst;

	atexit(leaks);
	g_output_code = 0;
	signal_declaration();
	env_lst = init_env();
	while (1)
	{
		argv = readline(BLUE"Mini"YELLOW"Shell"RESET" ");
		if (argv == NULL)
			exit(0);
		add_history(argv);
		nodes = create_nodes_rework(argv, env_lst->env);
		if (nodes_check_error(nodes))
		{
			exec(nodes, &env_lst);
		}
		free_nodes(nodes, argv);
		//system("leaks -q minishell");
	}
	s_mirage(env_lst->ex_env);
	free_env(&env_lst);
	return (0);
}
//system("leaks -q minishell");
//s_mirage(env);