/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:34:24 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/10 13:20:32 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

static int	check_chars_ex(t_lst *lst, t_mirage *env, int i)
{
	int	y;

	(void) env;
	if (ft_isalpha(lst->argv[i][0]) == 0)
	{
		printf("export: '%s' : not a valid identifier\n", lst->argv[1]);
		return (1);
	}
	y = 0;
	while (lst->argv[i][y] != 0)
	{
		if (lst->argv[i][y] == 61)
		{
			y++;
			if (lst->argv[i][y] == 0)
				break ;			
		}
		if ((lst->argv[i][y] >= 33 && lst->argv[i][y] <= 47) ||
			(lst->argv[i][y] >= 58 && lst->argv[i][y] <= 64))
		{
			printf("export: '%s' : not a valid identifier\n", lst->argv[i]);
			return (1);
		}
		y++;
	}
	return (0);
}

static void	sort_export(t_lst *lst, t_mirage *env)
{
	t_mirage	*head;
	t_mirage	*show;
	int			i;
	int			len;

	(void)lst;
	show = lstnew_env(&env);
	i = 0;
	len = lstsize_env(show);
	head = show;
	while (is_sorted(&head, len) == 1)
	{
		if (show->next->next != NULL)
			i = cond_export(&head, &show, i);
		else if (show->next->next == NULL)
		{
			show = head;
			i = -1;
		}
		i++;
	}
	show_export(head);
	lstclear_env(&head, free);
}

static t_mirage	*new_node_env(char *cont)
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

//TODO Liberar
static void	new_variable(t_lst *lst, t_env **env)
{
	int			i;
	char		**split;

	i = 0;
	while (lst->argv[++i] != NULL)
	{
		if (check_chars_ex(lst, (*env)->env, i) == 1)
			break ;
		if (ft_strchr(lst->argv[i], '=') != NULL)
		{
			split = ft_split(lst->argv[i], '=');
			if (get_name_env((*env)->ex_env, split[0]) != NULL)
				change_val_env(&(*env)->ex_env, split[0], split[1], lst->argv[i]);
			if (get_name_env((*env)->env, split[0]) != NULL)
				change_val_env(&(*env)->env, split[0], split[1], lst->argv[i]);
			else
			{
				add_back_env(&(*env)->env, new_node_env(lst->argv[i]));
				if (get_name_env((*env)->ex_env, split[0]) == NULL)
					add_back_env(&(*env)->ex_env, new_node_env(lst->argv[i]));
			}
			ft_free_malloc(split);
		}
		else
			add_back_env(&(*env)->ex_env, new_node_env(lst->argv[i]));
	}
}

//TODO Liberar
void	make_export(t_lst *lst, t_info *info, t_env **env)
{
	(void)info;
	if (lst->n_words == 1)
		sort_export(lst, (*env)->ex_env);
	else
		new_variable(lst, env);
}
