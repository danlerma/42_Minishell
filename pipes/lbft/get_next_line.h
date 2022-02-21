/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 14:10:20 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/11/03 17:10:37 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
size_t	ft_cleanlen_gnl(const char *c, int num, void *s, size_t n);
char	*ft_strdup_gnl(const char *s1);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);

#endif
