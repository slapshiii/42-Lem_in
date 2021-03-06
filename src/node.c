/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:34:24 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/26 11:14:57 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

t_node	*new_node(char *name, t_pos pos, t_coord coord)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node)
	{
		ft_bzero(new_node, sizeof(t_node));
		new_node->name = ft_strdup(name);
		if (new_node->name == NULL)
		{
			free(new_node);
			return (NULL);
		}
		new_node->coord = coord;
		new_node->pos = pos;
		new_node->edge = NULL;
		new_node->parent = NULL;
		new_node->path = -1;
		new_node->visited = 0;
	}
	return (new_node);
}

void	del_node(void *node)
{
	t_node	*tofree;

	tofree = (t_node *)node;
	free(tofree->name);
	if (tofree->edge)
		ft_lstclear(&(tofree->edge), NULL);
	free(tofree);
}

int	node_by_name(void *node_value, void *value)
{
	t_node	*node_content;

	node_content = (t_node *)node_value;
	return (ft_strcmp(node_content->name, (char *)value));
}

void	reset_node(void *node)
{
	t_node	*n;

	n = (t_node *)node;
	n->visited = 0;
}

void	print_node(void *node)
{
	t_list	*edges;

	edges = ((t_node *)node)->edge;
	if (((t_node *)node)->pos == p_room)
		ft_putchar_fd('\t', 1);
	else if (((t_node *)node)->pos == p_start)
		ft_putstr_fd("start\t", 1);
	else
		ft_putstr_fd("end\t", 1);
	ft_putstr_fd("name: ", 1);
	ft_putstr_fd((char *)(((t_node *)node)->name), 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(((t_node *)node)->coord.x, 1);
	ft_putchar_fd('-', 1);
	ft_putnbr_fd(((t_node *)node)->coord.y, 1);
	ft_putstr_fd(" [", 1);
	while (edges)
	{
		ft_putstr_fd((char *)edges->content, 1);
		edges = edges->next;
		if (edges)
			ft_putchar_fd('-', 1);
	}
	ft_putstr_fd("]\n", 1);
}
