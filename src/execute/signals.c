/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:50:27 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/21 14:31:14 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static	void	jump_line(void)
{
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static	void	do_nothing(void)
{
	rl_on_new_line();
	rl_replace_line(rl_line_buffer, rl_end);
	rl_redisplay();
}

static void	signal_control(int signum)
{
	if (signum == SIGINT)
		jump_line();
	else if (signum == SIGQUIT)
		do_nothing();
}

void	signal_declaration(void)
{
	signal(SIGINT, signal_control);
	signal(SIGQUIT, signal_control);
}
