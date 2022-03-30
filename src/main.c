/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:57:38 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/30 15:07:42 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static	t_global_lst	*declare_global_struct(void)
{
	t_global_lst	*list;

	list = ft_calloc(sizeof(t_global_lst), 1);
	list->g_output_code = 0;
	list->signal_heredoc = 0;
	return (list);
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

	g_general_data = declare_global_struct();
	env_lst = init_env();
	while (1)
	{
		signal_main();
		argv = readline(BLUE"Mini"YELLOW"Shell"RESET" ");
		if (argv == NULL)
		{
			printf("exit\n");
			exit(EXIT_SUCCESS);
		}
		add_history(argv);
		nodes = create_nodes_rework(argv, env_lst->env);
		if (nodes_check_error(nodes))
			exec(nodes, &env_lst);
		free_nodes(nodes, argv);
		//system("leaks -q minishell");
	}
	s_mirage(env_lst->ex_env);
	free_env(&env_lst);
	return (0);
}
