/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:37:19 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/26 19:04:20 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	find the edge with the name name and remove it from the list
*/
void	dc_edge(t_list **edge, char *name)
{
	t_list	*tmp;
	t_list	*tofree;
	t_list	*prev;

	tmp = *edge;
	prev = NULL;
	while (tmp)
	{
		if (ft_strcmp((char *)tmp->content, name) == 0)
		{
			tofree = tmp;
			if (prev)
				prev->next = tmp->next;
			else
				*edge = tmp->next;
			tmp = tmp->next;
			ft_lstdelone(tofree, NULL);
		}
		else
		{
			prev = tmp;
			tmp = tmp->next;
		}
	}
}

int	bfs_solve(t_config *conf, t_list *edges, t_list **queue, t_list	*u)
{
	t_list	*v;

	while (edges)
	{
		v = ft_lstfind(&conf->nodes, &node_by_name, edges->content);
		if (v && ((t_node *)v->content)->visited == 0)
		{
			if (((t_node *)v->content)->pos == p_end)
			{
				((t_node *)v->content)->parent = ((t_node *)u->content)->name;
				ft_lstclear(queue, NULL);
				return (1);
			}
			ft_lstadd_back(queue, ft_lstnew(((t_node *)v->content)->name));
			((t_node *)v->content)->parent = ((t_node *)u->content)->name;
			((t_node *)v->content)->visited = 1;
		}
		edges = edges->next;
	}
	return (0);
}

void	fordfulerson_resolve(t_config *conf, t_list *node, t_path *path)
{
	char	*prev;
	t_list	*child;

	while (node && ((t_node *)node->content)->pos != p_end)
		node = node->next;
	while (node)
	{
		++path->dist;
		ft_lstadd_front(&path->path,
			ft_lstnew(((t_node *)node->content)->name));
		if (!((t_node *)node->content)->parent)
			break ;
		prev = ((t_node *)node->content)->name;
		node = ft_lstfind(&conf->nodes, &node_by_name,
				((t_node *)node->content)->parent);
		child = ft_lstfind(&conf->nodes, &node_by_name, prev);
		dc_edge(&((t_node *)node->content)->edge, prev);
		dc_edge(&((t_node *)child->content)->edge,
			((t_node *)node->content)->name);
	}
}
