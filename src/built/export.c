/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:34:24 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/08 16:56:01 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

static void	check_chars(t_lst *lst, t_mirage *env)
{
	
}

static void	sort_export(t_lst *lst, t_mirage *env)
{
	t_mirage	*head;
	t_mirage	*aux;
	int			i;
	int			len;

	i = 0;
	len = lstsize_env(env);
	head = env;
	while (is_sorted(&head, len) == 1)
	{
		if (env->next->next != NULL)
			i = cond_export(&head, &env, i);
		else if (env->next->next == NULL)
		{
			env = head;
			i = -1;
		}
		i++;
	}
	show_export(head);
	lstclear_env(&head, free);
}

//TODO Liberar
static void	new_variable(t_lst *lst, t_mirage **env)
{
	t_mirage	*temp;
	int			i;

	i = 1;
	while (lst->argv[i] != NULL)
	{
		if (ft_strchr(lst->argv[i], '=') != NULL)
		{
			temp = (t_mirage *)ft_calloc(1, sizeof(t_mirage));
			if (temp == NULL)
				exit(0);
			temp->var = ft_strdup(lst->argv[i]);
			split_variables(lst->argv[i], &temp);
			temp->next = NULL;
			if (get_name_env(*env, temp->name) != NULL)
				delete_var(env, temp->name);
			add_back_env(env, temp);
		}
		i++;
	}
}

void	make_export(t_lst *lst, t_info *info, t_mirage **env)
{
	t_mirage	*e;

	e = *env;
	if (lst->n_words == 1)
		sort_export(lst, e);
	else
	{
		check_chars(lst, *env);
		new_variable(lst, env);
	}
}
