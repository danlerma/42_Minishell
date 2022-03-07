/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:51:10 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/07 12:51:26 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H

# define GENERAL_H

typedef struct s_lst
{
	int				n_words;
	char			**argv;
	int				*type;
	int				*flag;
	struct s_lst	*next;
}t_lst;

typedef struct s_mirage
{
	char				*var;
	char				*name;
	char				*value;
	struct s_mirage		*next;
}t_mirage;

#endif