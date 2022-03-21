/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:50:27 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/21 13:17:16 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	signal_control(int signum)
{
	if (signum == SIGINT)
		printf("\n");
	printf(BLUE"Mini"YELLOW"Shell"RESET" ");
}

void	signal_declaration(void)
{
	signal(SIGINT, signal_control);
	signal(SIGQUIT, signal_control);
}
