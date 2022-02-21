/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:21:45 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/08/11 12:31:13 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	size;

	i = 0;
	if (s != NULL)
	{
		size = ft_strlen(s);
		while (i < size)
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}
