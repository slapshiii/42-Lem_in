/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 01:34:57 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/26 16:58:21 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	bfs(t_config *conf)
{
	t_list	*queue;
	t_list	*tofree;
	t_list	*u;
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
		if (bfs_solve(conf, edge, &queue, u))
			return (1);
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
			fordfulerson_resolve(conf, node, path);
		}
		if (path && path->dist != -1)
			ft_lstadd_front(&conf->paths, ft_lstnew(path));
		else
			del_path(path);
		++index;
	}
	conf->nb_paths = index;
}
