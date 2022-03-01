/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_data_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:17:34 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/01 14:37:19 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**create_array(t_list *lst)
{
	char	**array;
	int		i;
	t_list	*aux;

	i = 0;
	aux = lst;
	while (aux)
	{
		aux = aux->next;
		i++;
	}
	array = ft_calloc(sizeof(char *), i);
	i = 0;
	while (lst)
	{
		array[i] = lst->content;
		aux = lst->next;
		free(lst);
		lst = aux;
		i++;
	}
	free(lst);
	return (array);
}

char	**fakedata(void)
{
	char	**data;

	data = ft_calloc(sizeof(char *), 6 + 1);
	data[0] = ft_strdup("ls");
	data[1] = ft_strdup("-la");
	data[2] = ft_strdup("|");
	data[3] = ft_strdup("cat");
	data[4] = ft_strdup(">>");
	data[5] = ft_strdup("texto");
	return (data);
}

char	**split_data(char const *s)
{
	char	**aux1;
	t_list	*aux2;

	if (s == NULL)
		return (0);
	aux2 = make_lst(ft_lstnew(0), s);
	aux1 = create_array(aux2);
	//aux1 = fakedata();
	return (aux1);
}
