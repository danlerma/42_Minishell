/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 14:09:52 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/01/08 10:25:08 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*assign_chars(char *aux)
{
	int		i;
	char	*str;

	i = 0;
	while (aux[i] != '\n' && aux[i] != '\0')
		i++;
	str = ft_substr_gnl(aux, 0, i + 1);
	return (str);
}

static char	*read_line(int size, int fd, char *buff, char **str)
{
	char	*aux;

	while (size > 0)
	{
		buff[size] = '\0';
		aux = *str;
		*str = ft_strjoin_gnl(aux, buff);
		if (str == NULL)
			return (NULL);
		free(aux);
		if (ft_strchr(*str, '\n') != NULL)
			break ;
		size = read(fd, buff, BUFFER_SIZE);
		if (size == -1)
			return (NULL);
	}
	free(buff);
	return (*str);
}

static char	*check_next_line(char **str, char **remainder)
{
	char	*aux;

	if (ft_strchr(*str, '\n') != NULL)
	{
		aux = *remainder;
		*remainder = ft_strdup_gnl(ft_strchr(*str, '\n') + 1);
		if (remainder == NULL)
			return (NULL);
		free(aux);
	}
	aux = *str;
	*str = assign_chars(aux);
	free(aux);
	return (*str);
}

static int	checking(char **remainder, ssize_t size, char **buff)
{
	if (!*remainder)
	{
		*remainder = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (*remainder == NULL)
			return (0);
		ft_cleanlen_gnl("\0", 1, *remainder, BUFFER_SIZE + 1);
	}
	if (size == -1 || (size == 0 && *remainder[0] == '\0'))
	{
		free(*remainder);
		free(*buff);
		*remainder = NULL;
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*str;
	static char	*remainder;
	ssize_t		size;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	ft_cleanlen_gnl("\0", 1, buff, BUFFER_SIZE + 1);
	if (read(fd, buff, 0) == -1 || BUFFER_SIZE < 1 || fd < 0)
	{
		free(buff);
		return (NULL);
	}
	size = read(fd, buff, BUFFER_SIZE);
	if (checking(&remainder, size, &buff) == 0)
		return (NULL);
	str = ft_strdup_gnl((char *)remainder);
	if (str == NULL)
		return (NULL);
	ft_cleanlen_gnl("\0", 1, remainder, ft_cleanlen_gnl(remainder, 0, 0, 0));
	str = read_line(size, fd, buff, &str);
	return (check_next_line(&str, &remainder));
}
