/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 13:42:50 by seushin           #+#    #+#             */
/*   Updated: 2021/11/07 15:16:02 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"

static void	reset(char **line, char **cache)
{
	free(*line);
	free(*cache);
	*line = 0;
	*cache = 0;
}

static int	split_cache(char **line, char **cache)
{
	char		*tmp;
	char		*newline;

	if (!*cache)
		*cache = ft_strndup("", 0);
	if (!*cache)
		return (ERRNO);
	newline = ft_strchr(*cache, '\n');
	if (newline)
	{
		*line = ft_strndup(*cache, newline - *cache);
		tmp = ft_strndup(newline + 1, ft_strlen(newline + 1));
		free(*cache);
		*cache = tmp;
		if (!*line || !*cache)
		{
			reset(line, cache);
			return (ERRNO);
		}
		return (1);
	}
	*line = *cache;
	*cache = 0;
	return (0);
}

static int	realloc_cache(char **cache, char *buf)
{
	char		*tmp;

	tmp = ft_strjoin(*cache, buf);
	free(*cache);
	*cache = tmp;
	if (!*cache)
	{
		free(buf);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	get_next_line(int fd, char **line)
{
	static char	*cache[OPEN_MAX + 1];
	char		*buf;
	int			n;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE < 1)
		return (ERRNO);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (ERRNO);
	n = read(fd, buf, BUFFER_SIZE);
	while (n > 0)
	{
		buf[n] = '\0';
		if (realloc_cache(&cache[fd], buf) == FAILURE)
			return (ERRNO);
		if (ft_strchr(cache[fd], '\n'))
			break ;
		n = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (n < 0)
		return (ERRNO);
	return (split_cache(line, &cache[fd]));
}
