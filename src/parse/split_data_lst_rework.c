/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_data_lst_rework.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:24:04 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/21 16:26:49 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	get_tam_token_rework(char const *s)
{
	if (s[0] == '>' || s[0] == '<' || s[0] == '|')
	{
		if (s[1] == '>' || s[1] == '<')
			return (2);
		return (1);
	}
	return (0);
}

static int	dst_next_word_rework(char const *s)
{
	int	dst;

	dst = 0;
	while (s[dst] != 0)
	{
		if (s[dst] != ' ')
			break ;
		dst++;
	}
	return (dst);
}

static	t_list	*cut_last_null(t_list *lst)
{
	t_list	*aux_lst;

	aux_lst = lst;
	if (lst->content == 0)
	{
		free(lst);
		return (0);
	}
	else
	{
		while (aux_lst->next->content != 0)
			aux_lst = aux_lst->next;
		free(aux_lst->next);
		aux_lst->next = NULL;
	}
	return (lst);
}

static t_list	*make_lst_rework(t_list *lst, char const *s)
{
	t_list	*aux_lst;
	int		i;

	i = 0;
	aux_lst = lst;
	while (s[i] != 0)
	{
		i += dst_next_word_rework(&s[i]);
		if (!is_separator_rework(&s[i]) && s[i] != 0)
		{
			lst->content = ft_substr (s, i, get_tam_word_rework(&s[i]));
			i += get_tam_word_rework(&s[i]);
		}
		else if (s[i] != 0)
		{
			lst->content = ft_substr (s, i, get_tam_token_rework(&s[i]));
			i += get_tam_token_rework(&s[i]);
		}
		else
			break ;
		lst->next = ft_lstnew(0);
		lst = lst->next;
	}
	return (aux_lst);
}

t_list	*split_data_rework(char const *s)
{
	t_list	*aux;

	if (s == NULL)
		return (0);
	aux = make_lst_rework(ft_lstnew(0), s);
	aux = cut_last_null(aux);
	return (aux);
}
