/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:06:49 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/24 02:03:38 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

t_state	addroom(t_config *conf, t_state	*state, char **tab)
{
	t_node	*node;

	if (tab[0] && tab[1] && tab[2] && !tab[3])
	{
		node = new_node(tab[0], (t_pos)(*state) - 1,
				(t_coord){ft_atoi(tab[1]), ft_atoi(tab[2])});
		if (!node || ft_lstfind(&(conf->nodes), &node_by_name, tab[0]))
			return (error);
		ft_lstadd_front(&(conf->nodes), ft_lstnew(node));
		++conf->nb_nodes;
		return (room);
	}
	if (tab[0] && !tab[1])
		return (tube);
	return (error);
}

t_state	addedge(t_config *conf, char **tab)
{
	t_list	*elem;
	t_node	*node;

	elem = ft_lstfind(&(conf->nodes), &node_by_name, tab[0]);
	if (elem == NULL)
		return (error);
	node = (t_node *)elem->content;
	ft_lstadd_front(&(node->edge), ft_lstnew(ft_strdup(tab[1])));
	return (tube);
}
