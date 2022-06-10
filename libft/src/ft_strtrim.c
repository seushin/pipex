/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 19:00:45 by seushin           #+#    #+#             */
/*   Updated: 2021/11/06 00:08:53 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*res;
	int		start;
	int		end;

	if (!s1)
		return (0);
	start = 0;
	while (s1[start] && ft_is_set(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_is_set(set, s1[end]))
		end--;
	res = (char *)malloc(end - start + 2);
	if (!res)
		return (0);
	ft_strlcpy(res, s1 + start, end - start + 2);
	return (res);
}
