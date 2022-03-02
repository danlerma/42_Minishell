/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:54:42 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/02 14:40:21 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

void	add_back_env(t_mirage **lst, t_mirage *new)
{
	t_mirage	*aux;

	if (*lst == NULL)
		*lst = new;
	else if (*lst)
	{
		aux = lstlast_env(*lst);
		aux->next = new;
	}
}

t_mirage	*lstlast_env(t_mirage *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lstdelone_env(t_mirage *lst, void (*del)(void*))
{

	if (lst)
	{
		(*del)(lst->var);
	}
}

void	lstclear_env(t_mirage **lst, void (*del)(void *))
{
	t_mirage	*next;

	(void)(*del);
	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
}
