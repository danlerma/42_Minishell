/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:38:20 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/21 13:17:06 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

void	lstdelone(t_lst *lst, void (*del)(void*))
{
	int	i;

	if (lst)
	{
		i = -1;
		while (lst->argv[++i] != NULL)
			(*del)(lst->argv[i]);
		(*del)(lst->argv);
		(*del)(lst->type);
	}
}

void	lstclear(t_lst **lst, void (*del)(void *))
{
	t_lst	*next;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		next = (*lst)->next;
		lstdelone(*lst, del);
		free(*lst);
		*lst = next;
	}
}

t_lst	*lstlast(t_lst *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*aux;

	if (*lst == NULL)
		*lst = new;
	else if (*lst)
	{
		aux = lstlast(*lst);
		aux->next = new;
	}
}

int	lstsize(t_lst *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
