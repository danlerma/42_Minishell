/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:50:27 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/23 16:49:19 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static	void	jump_line(void)
{
	//printf("jfewkejgbeb");
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

void	signal_son(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
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
