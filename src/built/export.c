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

	if (ft_isalpha(lst->argv[i][0]) == 0)
	{
		printf("export: '%s' : not a valid identifier\n", lst->argv[1]);
		return (1);
	}
	y = 0;
	while (lst->argv[i][y])
	{
		if (lst->argv[i][y] == 61)
			y++;
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
		if (check_chars_ex(lst, *env, i) == 1)
			break ;
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

//TODO Liberar
void	make_export(t_lst *lst, t_info *info, t_mirage **env)
{
	t_mirage	*e;

	e = NULL;
	if (lst->n_words == 1)
	{
		e = lstnew_env(env);
		sort_export(lst, e);
	}
	else
		new_variable(lst, env);
}
