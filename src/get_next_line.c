/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 03:48:52 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/14 04:21:23 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	recursive(const int fd, char **line, size_t index)
{
	char	buf;
	int		ret;

	ret = read(fd, &buf, 1);
	if (ret == 1 && buf != '\n')
	{
		recursive(fd, line, index + 1);
		(*line)[index] = buf;
	}
	else
	{
		*line = (char *)malloc(sizeof(char) * index + 1);
		(*line)[index] = '\0';
	}
	return (ret);
}

/*
**	return 0 if EOF
*/
int	get_next_line(const int fd, char **line)
{
	int		ret;

	ret = recursive(fd, line, 0);
	return (ret);
}
