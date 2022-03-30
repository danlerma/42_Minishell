/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:40:23 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/30 14:50:52 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

static void	wait_child(t_info *info)
{
	int	i;
	int	*k;

	i = 0;
	k = ft_calloc(sizeof(int), 1);
	while (i < info->nlst)
	{
		waitpid(-1, k, 0);
		//printf("Pid a tratar -> %i\n", info->order_pid[i]);
		//printf("Prueba %i %i | %i %i\n", WIFEXITED(info->order_pid[i]), WEXITSTATUS(info->order_pid[i]) , WIFSIGNALED(info->order_pid[i]), WTERMSIG(info->order_pid[i]));
		//printf("Resultado -> %i\n", *k);
		i++;
	}
	/*waitpid(info->order_pid, k, 0);
	//wait(&info->order_pid);
	printf("Resultados del ultimo lst -> %i \n", info->order_pid);
	printf("Resultado -> %i\n", *k);
	printf("Prueba %i %i | %i %i\n", WIFEXITED(info->order_pid), WEXITSTATUS(info->order_pid) , WIFSIGNALED(info->order_pid), WTERMSIG(info->order_pid));
	*/free(k);
}

void	make_process(t_info *info, t_lst *lst, t_env **env)
{
	int	i;

	i = 0;
	check_here(info, lst);
	if (g_general_data->signal_heredoc == 0)
	{
		while (lst)
		{
			g_general_data->g_output_code = 0;
			info->pos = i;
			commands(info, lst, env);
			lst = lst->next;
			i++;
		}
		wait_child(info);
	}
	else
	{
		g_general_data->g_output_code = 1;
		printf("\n");
	}
}
