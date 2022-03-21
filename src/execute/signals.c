/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:50:27 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/21 19:17:55 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static	void	jump_line(void)
{
	if (g_general_data->is_here_doc == 1)
			g_general_data->signal_heredoc = 1;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	signal_control(int signum)
{
	if (signum == SIGINT)
		jump_line();
	else if (signum == SIGQUIT)
	{
		rl_on_new_line();
		rl_replace_line(rl_line_buffer, rl_end);
		rl_redisplay();
	}
}
/*
static void	signal_control_heredoc(int signum)
{
	if (signum == SIGINT)
	{
		if (g_general_data->is_here_doc == 1)
			g_general_data->signal_heredoc = 1;
	}
}

void	signal_heredoc(void)
{
	signal(SIGINT, signal_control_heredoc);
	signal(SIGQUIT, signal_control_heredoc);
}
*/

void	signal_main(void)
{
	signal(SIGINT, signal_control);
	signal(SIGQUIT, signal_control);
}
