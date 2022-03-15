/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:54:42 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/15 13:44:02 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

t_mirage	*lstnew_env(t_mirage **env)
{
	t_mirage	*temp;
	t_mirage	*aux;
	t_mirage	*lst;

	temp = *env;
	lst = NULL;
	while (temp != NULL)
	{
		aux = (t_mirage *)ft_calloc(1, sizeof(t_mirage));
		if (aux == NULL)
			exit(0);
		aux->var = temp->var;
		aux->name = ft_strdup(temp->name);
		if (temp->value != NULL)
			aux->value = ft_strdup(temp->value);
		else
			aux->value = ft_strdup("");
		aux->next = NULL;
		add_back_env(&lst, aux);
		temp = temp->next;
	}
	return (lst);
}

t_mirage	*new_node_env(char *cont)
{
	t_mirage	*node;

	node = (t_mirage *)ft_calloc(1, sizeof(t_mirage));
	if (node == NULL)
		exit(0);
	node->var = ft_strdup(cont);
	split_variables(cont, &node);
	node->next = NULL;
	return (node);
}

int	lstsize_env(t_mirage *lst)
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
		(*del)(lst->value);
		(*del)(lst->name);
	}
}

void	lstclear_env(t_mirage **lst, void (*del)(void *))
{
	t_mirage	*next;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		next = (*lst)->next;
		lstdelone_env(*lst, del);
		free(*lst);
		*lst = next;
	}
}
