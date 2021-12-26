/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 01:34:57 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/26 11:18:17 by phnguyen         ###   ########.fr       */
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

int	bfs(t_config *conf)
{
	t_list	*queue;
	t_list	*tofree;
	t_list	*u;
	t_list	*v;
	t_list	*edge;

	ft_lstiter(conf->nodes, reset_node);
	u = conf->nodes;
	queue = NULL;
	while (u && ((t_node *)u->content)->pos != p_start)
		u = u->next;
	ft_lstadd_back(&queue, ft_lstnew(((t_node *)u->content)->name));
	((t_node *)u->content)->visited = 1;
	while (ft_lstsize(queue))
	{
		u = ft_lstfind(&conf->nodes, &node_by_name, queue->content);
		tofree = queue;
		queue = queue->next;
		ft_lstdelone(tofree, NULL);
		tofree = NULL;
		edge = ((t_node *)u->content)->edge;
		while (edge)
		{
			v = ft_lstfind(&conf->nodes, &node_by_name, edge->content);
			if (v && ((t_node *)v->content)->visited == 0)
			{
				if (((t_node *)v->content)->pos == p_end)
				{
					((t_node *)v->content)->parent = ((t_node *)u->content)->name;
					ft_lstclear(&queue, NULL);
					return (1);
				}
				ft_lstadd_back(&queue, ft_lstnew(((t_node *)v->content)->name));
				((t_node *)v->content)->parent = ((t_node *)u->content)->name;
				((t_node *)v->content)->visited = 1;
			}
			edge = edge->next;
		}
	}
	return (0);
}

void	del_path(void *path)
{
	t_path	*p;

	if (!path)
		return ;
	p = (t_path *)path;
	ft_lstclear(&p->path, NULL);
	free(path);
}

void	fordfulkerson(t_config *conf)
{
	t_path	*path;
	t_list	*node;
	char	*prev;
	int		index;

	index = 0;
	while (bfs(conf))
	{
		node = conf->nodes;
		path = (t_path *)malloc(sizeof(t_path));
		if (path)
		{
			ft_bzero(path, sizeof(t_path));
			path->dist = -1;
			path->index = index;
			while (node && ((t_node *)node->content)->pos != p_end)
				node = node->next;
			while (node)
			{
				++path->dist;
				ft_lstadd_front(&path->path, ft_lstnew(((t_node *)node->content)->name));
				if (!((t_node *)node->content)->parent)
					break ;
				prev = ((t_node *)node->content)->name;
				node = ft_lstfind(&conf->nodes, &node_by_name, ((t_node *)node->content)->parent);
				dc_edge(&((t_node *)node->content)->edge, prev);
			}
		}
		if (path && path->dist != -1)
			ft_lstadd_front(&conf->paths, ft_lstnew(path));
		else
			del_path(path);
		++index;
	}
	conf->nb_paths = index;
}
