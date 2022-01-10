/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:06:49 by phnguyen          #+#    #+#             */
/*   Updated: 2022/01/10 19:06:55 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

t_list	*get_elem(t_list **list, char *name)
{
	t_list	*temp;
	int		res;

	temp = *list;
	while (temp)
	{
		res = ft_strcmp(((t_node *)temp->content)->name, name);
		if (res == 0)
			return (temp);
		else if (res > 0)
			return (NULL);
		temp = temp->next;
	}
	return (NULL);
}

int	insert_node(t_node *node, t_list **list)
{
	t_list	*curr;
	t_list	*prev;
	t_list	*n;

	curr = *list;
	prev = *list;
	n = ft_lstnew(node);
	if (!n)
		return (1);
	if (!curr || ft_strcmp(node->name, ((t_node *)curr->content)->name) < 0)
		ft_lstadd_front(list, n);
	else
	{
		while (curr
			&& ft_strcmp(node->name, ((t_node *)curr->content)->name) > 0)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr && ft_strcmp(node->name, ((t_node *)curr->content)->name) == 0)
			return (1);
		n->next = prev->next;
		prev->next = n;
	}
	return (0);
}

t_state	addroom(t_config *conf, t_state	*state, char **tab)
{
	t_node	*node;

	if (tab[0] && tab[1] && tab[2] && !tab[3])
	{
		if (!ft_isnumber(tab[1]) || !ft_isnumber(tab[2]))
			return (error);
		node = new_node(tab[0], (t_pos)(*state) - 1,
				(t_coord){ft_atoi(tab[1]), ft_atoi(tab[2])}, conf->nb_nodes);
		if (!node)
			return (error);
		if (insert_node(node, &(conf->nodes)))
		{
			free(node);
			return (error);
		}
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

int	init_edges(t_config *conf)
{
	int	i;

	i = 0;
	conf->edges = (int **)malloc(sizeof(int *) * conf->nb_nodes);
	if (conf->edges)
	{
		while (i < conf->nb_nodes)
		{
			conf->edges[i] = (int *)ft_calloc(conf->nb_nodes, sizeof(int));
			if (!conf->edges[i])
			{
				while (--i >= 0)
					free(conf->edges[i]);
				free(conf->edges);
				conf->edges = NULL;
				return (0);
			}
			++i;
		}
	}
	return (1);
}

t_state	addedge(t_config *conf, char **tab)
{
	t_list	*elem;
	t_list	*to;

	elem = get_elem(&(conf->nodes), tab[0]);
	to = get_elem(&(conf->nodes), tab[1]);
	if (elem == NULL || to == NULL)
		return (error);
	conf->edges[((t_node *)elem->content)->index]
	[((t_node *)to->content)->index] = LINK;
	conf->edges[((t_node *)to->content)->index]
	[((t_node *)elem->content)->index] = LINK;
	++conf->nb_edges;
	return (tube);
}
