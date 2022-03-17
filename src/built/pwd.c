/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:15:33 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/17 13:36:50 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	make_pwd(t_lst *lst, t_info *info, t_env *env)
{
	char	dir[4096];

	(void)env;
	(void)lst;
	(void)info;
	getcwd(dir, sizeof(dir));
	printf("%s\n", dir);
}
