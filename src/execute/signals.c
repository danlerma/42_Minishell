/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:50:27 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/18 15:33:05 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	signal_control(int signum)
{
	//printf("Señal recibida %i \n",signum);
	if (signum == SIGINT)
		printf("\n");
	printf(BLUE"Mini"YELLOW"Shell"RESET" ");
}
//else if (signum == SIGQUIT)

void	signal_declaration(void)
{
	signal(SIGINT, signal_control);
	signal(SIGQUIT, signal_control);
}
