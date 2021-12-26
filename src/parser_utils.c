/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:06:49 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/26 22:04:16 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

t_state	addroom(t_config *conf, t_state	*state, char **tab)
{
	t_node	*node;

	if (tab[0] && tab[1] && tab[2] && !tab[3])
	{
		if (!ft_isnumber(tab[1]) || !ft_isnumber(tab[2])
			|| ft_lstfind(&(conf->nodes), &node_by_name, tab[0]))
			return (error);
		node = new_node(tab[0], (t_pos)(*state) - 1,
				(t_coord){ft_atoi(tab[1]), ft_atoi(tab[2])});
		if (!node)
			return (error);
		ft_lstadd_front(&(conf->nodes), ft_lstnew(node));
		++conf->nb_nodes;
		if (*state == r_end)
			conf->valid |= 1 << 2;
		else if (*state == r_start)
			conf->valid |= 1 << 1;
		return (room);
	}
	if (tab[0] && !tab[1])
		return (tube);
	return (error);
}

t_state	addedge(t_config *conf, char **tab)
{
	t_list	*elem;
	t_list	*to;

	elem = ft_lstfind(&(conf->nodes), &node_by_name, tab[0]);
	to = ft_lstfind(&(conf->nodes), &node_by_name, tab[1]);
	if (elem == NULL || to == NULL)
		return (error);
	ft_lstadd_front(&(((t_node *)elem->content)->edge),
		ft_lstnew(((t_node *)to->content)->name));
	ft_lstadd_front(&(((t_node *)to->content)->edge),
		ft_lstnew(((t_node *)elem->content)->name));
	return (tube);
}
