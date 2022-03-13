/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:38:50 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/02 17:55:58 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

void	s_list(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i = 0;
		printf("Direction: %p\n", lst);
		while (lst->argv[i])
		{
			printf("\tArgv(%d): %s\n\tType(%d): %d\n\n", i,
				lst->argv[i], i, lst->type[i]);
			i++;
		}
		printf("Next:      %p\n", lst->next);
		lst = lst->next;
	}
	printf("\n");
}

void	s_mirage(t_mirage *lst)
{
	while (lst != NULL)
	{
		printf("Direction: %p\n", lst);
		printf("\tVARIABLE: %s\n", lst->var);
		printf("\tNAME: %s\n", lst->name);
		printf("\tVALUE: %s\n", lst->value);
		printf("Next:      %p\n\n", lst->next);
		lst = lst->next;
	}
	printf("\n");
}
