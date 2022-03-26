/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:50:27 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/26 23:45:59 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	signal_control(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (signum == SIGQUIT)
	{
		rl_on_new_line();
		rl_replace_line(rl_line_buffer, rl_end);
		rl_redisplay();
	}
}

void	signal_son(void)
{
	int k;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	if (g_general_data->g_output_code != 0 && WIFSIGNALED(k))
			g_general_data->g_output_code += WTERMSIG(k) + 1;
}

void	signal_ing(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	signal_heredoc(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
}

void	signal_main(void)
{
	signal(SIGINT, signal_control);
	signal(SIGQUIT, signal_control);
}
