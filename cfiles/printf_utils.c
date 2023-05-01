/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:34:12 by btomlins          #+#    #+#             */
/*   Updated: 2023/05/01 13:11:53 by btomlins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	printf_percent(void)
{
	write(1, "%", 1);
}

static unsigned int	arrlen(int n)
{
	unsigned int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	i;
	unsigned int	len;
	char			*res;

	len = arrlen(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	i = n;
	if (!res)
		return (0);
	if (n < 0)
	{
		res[0] = '-';
		i = -n;
	}
	if (i == 0)
		res[0] = '0';
	res[len] = '\0';
	while (i != 0)
	{
		res[len - 1] = (i % 10) + 48;
		i = i / 10;
		len--;
	}
	return (res);
}
