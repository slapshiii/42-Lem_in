/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:06:49 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/16 04:33:58 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	addroom(t_config *conf, t_state	*state, char *str)
{
	tab = ft_split(str, WS);
	res = checkroom(tab, conf);
	if (res == 0)
		*state = error;
}

/*
**	0 = error
**	1 = good
**	2 = tube
*/
int	checkroom(char **tab, t_config *conf)
{
	char	**tube;
	t_node	*new_node;
	size_t	i;

	i = 0;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	if (tab[0] && tab[1] && tab[2] && !tab[3])
	{
		new_node->name = ft_strdup(tab[0]);
		new_node->coord.x = ft_atoi(tab[1]);
		new_node->coord.y = ft_atoi(tab[2]);
	}
	else if (tab[0] && !tab[1])
	{

	}
	return (0);
}