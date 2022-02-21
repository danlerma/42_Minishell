/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_init_temp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:04:57 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/02/15 13:24:33 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<pipes.h>

static t_lst *assing_loop(int cont, int prev, char **argv)
{
	int		i;
	t_lst	*temp;

	if (ft_strncmp(argv[prev], "|", 1) == 0)
		prev++;
	temp = (t_lst *)ft_calloc(1, sizeof(t_lst));
	if (temp == NULL)
		exit(0);
	temp->argv = (char **)ft_calloc(cont - prev + 1, sizeof(char *));
	temp->type = (int *)ft_calloc(cont - prev + 1, sizeof(int));
	if (temp->argv == NULL || temp->type == NULL)
		exit(0);
	i = 0;
	while (prev <= cont && ft_strncmp(argv[prev], "|", 1) != 0)
	{
		temp->argv[i] = ft_strdup(argv[prev]);
		if (i != 0 && (temp->type[i - 1] == 4 || temp->type[i - 1] == 7))
			temp->type[i] = 5;
		else if (i != 0 && temp->type[i - 1] == 6)
			temp->type[i] = 8;
		else if (i != 0 && temp->type[i - 1] == 2)
			temp->type[i] = 3;
		else if (ft_strncmp(temp->argv[i], ">", sizeof(temp->argv[i])) == 0)
			temp->type[i] = 4;
		else if (ft_strncmp(temp->argv[i], ">>", sizeof(temp->argv[i])) == 0)
			temp->type[i] = 7;
		else if (ft_strncmp(temp->argv[i], "<<", sizeof(temp->argv[i])) == 0)
			temp->type[i] = 6;
		else if (ft_strncmp(temp->argv[i], "<", sizeof(temp->argv[i])) == 0)
			temp->type[i] = 2;
		else if (temp->type[i] == 0)
			temp->type[i] = 1;
		i++;
		prev++;
	}
	temp->next = NULL;
	return (temp);
}

t_lst	*argv_init_temp(char **argv, int argc)
{
	t_lst	*lst;
	t_lst	*temp;
	int		i;
	int		prev;

	i = 1;
	prev = 1;
	lst = NULL;
	temp = NULL;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "|", 1) == 0 || i + 1 == argc)
		{
			temp = assing_loop(i, prev, argv);
			lstadd_back(&lst, temp);
			prev = i;
		}
		i++;
	}
	return (lst);
}
