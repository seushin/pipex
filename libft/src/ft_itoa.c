/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:08:08 by seushin           #+#    #+#             */
/*   Updated: 2021/11/06 00:37:05 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_chrcat(char *str, char c)
{
	str = ft_strchr(str, 0);
	*str++ = c;
	*str = 0;
}

static void	ft_putnbr_str(int n, char *str)
{
	int		tmp;

	tmp = n % 10;
	n /= 10;
	if (n != 0)
		ft_putnbr_str(n, str);
	if (tmp < 0)
	{
		if (n == 0)
			ft_chrcat(str, '-');
		ft_chrcat(str, -tmp + '0');
	}
	else
		ft_chrcat(str, tmp + '0');
}

char	*ft_itoa(int n)
{
	char	*res;
	int		is_neg;

	is_neg = 0;
	if (n < 0)
		is_neg = 1;
	res = (char *)malloc(ft_nbrlen(n, 10) + is_neg + 1);
	if (!res)
		return (0);
	*res = 0;
	ft_putnbr_str(n, res);
	return (res);
}
