/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:34:24 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/30 17:25:10 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

static int	check_chars_ex(t_lst *lst, int i)
{
	int	y;

	if (ft_isalpha(lst->argv[i][0]) == 0 && lst->type[i] == 1)
	{
		printf("export: '%s' : not a valid identifier\n", lst->argv[i]);
		g_output_code = 1;
		return (1);
	}
	y = -1;
	while (lst->argv[i][++y] != 0 && lst->type[i] == 1)
	{
		if (lst->argv[i][y] == 61)
		{
			if (lst->argv[i][++y] == 0)
				break ;
		}
		if ((lst->argv[i][y] >= 33 && lst->argv[i][y] <= 44) ||
			(lst->argv[i][y] >= 59 && lst->argv[i][y] <= 64))
		{
			printf("export: '%s' : not a valid identifier\n", lst->argv[i]);
			g_output_code = 1;
			return (1);
		}
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

static void	con_env_var(t_lst *lst, int i, t_env **env)
{
	char	**split;

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

static void	new_variable(t_lst *lst, t_env **env)
{
	int	i;

	i = 0;
	while (lst->argv[++i] != NULL)
	{
		if (check_chars_ex(lst, i) == 1)
			continue ;
		else if (ft_strchr(lst->argv[i], '=') != NULL)
			con_env_var(lst, i, env);
		else if (get_name_env((*env)->ex_env, lst->argv[i]) == NULL)
			add_back_env(&(*env)->ex_env, new_node_env(lst->argv[i]));
	}
}

void	make_export(t_lst *lst, t_info *info, t_env **env)
{
	(void)info;
	if (lst->argv[1] == NULL || lst->type[1] != 1)
		sort_export(lst, (*env)->ex_env);
	else
		new_variable(lst, env);
}
