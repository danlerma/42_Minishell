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

//TODO Liberar
static void	new_variable(t_lst *lst, t_env **env)
{
	t_mirage	*temp;
	t_mirage	*aux;
	int			i;
	char		**split;

	i = 1;
	while (lst->argv[i] != NULL)
	{
		if (check_chars_ex(lst, (*env)->env, i) == 1)
			break ;
		if (ft_strchr(lst->argv[i], '=') != NULL)
		{
			split = ft_split(lst->argv[i], '=');
			if (get_name_env((*env)->env, split[0]) != NULL)
				change_val_env(&(*env)->env, split[0], split[1], lst->argv[i]);
			else
			{
				temp = (t_mirage *)ft_calloc(1, sizeof(t_mirage));
				if (temp == NULL)
					exit(0);
				temp->var = ft_strdup(lst->argv[i]); //esto puede dar problemas
				split_variables(lst->argv[i], &temp);
				temp->next = NULL;
				add_back_env(&(*env)->env, temp);
			}
			ft_free_malloc(split);
		}
		else
		{
			temp = (t_mirage *)ft_calloc(1, sizeof(t_mirage));
			if (temp == NULL)
				exit(0);
			temp->var = ft_strdup(lst->argv[i]); //esto puede dar problemas
			split_variables(lst->argv[i], &temp);
			temp->next = NULL;
			add_back_env(&(*env)->ex_env, temp);
		}
		// if (ft_strchr(lst->argv[i], '=') != NULL)
		// {
		// 	temp = (t_mirage *)ft_calloc(1, sizeof(t_mirage));
		// 	if (temp == NULL)
		// 		exit(0);
		// 	temp->var = ft_strdup(lst->argv[i]);
		// 	split_variables(lst->argv[i], &temp);
		// 	temp->next = NULL;
		// 	if (get_name_env(*env, temp->name) != NULL)
		// 		delete_var(env, temp->name);
		// 	add_back_env(env, temp);
		// }
		i++;
	}
}

//TODO Liberar
void	make_export(t_lst *lst, t_info *info, t_env **env)
{
	if (lst->n_words == 1)
		sort_export(lst, (*env)->ex_env);
	else
		new_variable(lst, env);
}
