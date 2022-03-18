/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:20:16 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/18 17:20:44 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H

# define GENERAL_H

int	g_output_code;

typedef struct s_lst
{
	int				n_words;
	char			**argv;
	int				*type;
	int				*flag;
	int				built;
	struct s_lst	*next;
}t_lst;

typedef struct s_mirage
{
	char			*var;
	char			*name;
	char			*value;
	int				mem;
	struct s_mirage	*next;
}t_mirage;

typedef struct s_env
{
	t_mirage	*env;
	t_mirage	*ex_env;
}t_env;

#endif