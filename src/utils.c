/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 04:23:42 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/14 05:04:03 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	is_whitespace(char c)
{
	if (c == 32 || (c < 14 && c > 8))
		return (1);
	return (0);
}

int	ft_atoi(const char *s)
{
	int	res;
	int	sig;

	res = 0;
	sig = -1;
	while (*s && is_whitespace(*s))
		++s;
	if (*s && *s == '-')
	{
		sig = 1;
		++s;
	}
	else if (*s && *s == '+')
		++s;
	while (*s && *s >= '0' && *s <= '9')
	{
		res = (res * 10) + (*s - '0');
		++s;
	}
	return (res * (-sig));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return ((unsigned const char)*s1 - (unsigned const char)*s2);
}
