/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 03:49:22 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/14 05:03:51 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define WS " \t\v"

typedef struct list
{
	void		*data;
	struct list	*next;
}	t_list;

int		get_next_line(const int fd, char **line);
char	**ft_split(char const *s, char *c);
size_t	ft_strlen(const char *s);
int		is_whitespace(char c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *s);

t_list	*push_front(t_list **list, void *data);

#endif