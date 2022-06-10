/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 20:40:18 by seushin           #+#    #+#             */
/*   Updated: 2021/11/06 00:38:24 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	count_words(const char *s, char c)
{
	int		count;

	count = 0;
	while (s && *s)
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			s = ft_strchr(s, c);
		}
	}
	return (count);
}

static char	**free_words(char **words)
{
	int		i;

	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
	return (0);
}

static char	*get_single_word(const char *s, char c)
{
	char	*res;
	int		len;

	if (ft_strchr(s, c))
		len = ft_strchr(s, c) - s;
	else
		len = ft_strlen(s);
	res = ft_substr(s, 0, len);
	return (res);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		count;
	int		i;

	if (!s)
		return (0);
	count = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (count + 1));
	if (!res)
		return (0);
	i = 0;
	while (i < count)
	{
		while (*s && *s == c)
			s++;
		res[i] = get_single_word(s, c);
		if (!res[i])
			return (free_words(res));
		s = ft_strchr(s, c);
		i++;
	}
	res[i] = 0;
	return (res);
}
