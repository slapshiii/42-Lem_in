/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:37:27 by phnguyen          #+#    #+#             */
/*   Updated: 2022/01/10 19:20:14 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	init_lemin(t_lemin *param, t_config conf)
{
	t_list	*curr;
	t_node	*n;

	curr = conf.nodes;
	param->nb_ants = conf.nb_ants;
	param->nb_nodes = conf.nb_nodes;
	param->nb_edges = conf.nb_edges;
	param->start = conf.start;
	param->end = conf.end;
	param->edges = conf.edges;
	param->n = (t_node **)malloc(sizeof(t_node *) * conf.nb_nodes);
	if (!param->n)
		return (1);
	while (curr)
	{
		n = (t_node *)curr->content;
		param->n[n->index] = n;
		curr = curr->next;
	}
	if (conf.nodes)
		ft_lstclear(&(conf.nodes), NULL);
	return (0);
}

void	param_cleaner(t_lemin *param)
{
	int	i;

	i = 0;
	if (param->edges)
	{
		while (i < param->nb_nodes)
			free(param->edges[i++]);
		free(param->edges);
	}
	i = 0;
	if (param->n)
	{
		while (i < param->nb_nodes)
			del_node((void *)param->n[i++]);
		free(param->n);
	}
}

int	main(int ac, char **av)
{
	t_config	conf;
	t_lemin		param;

	(void)av;
	if (ac != 1)
	{
		ft_putstr_fd("./lem-in: error: Invalid arguments\n", 2);
		return (1);
	}
	ft_bzero(&conf, sizeof(t_config));
	ft_bzero(&param, sizeof(t_lemin));
	if (parse_input(&conf))
		ft_putstr_fd("ERROR\n", 2);
	else if (init_lemin(&param, conf))
		ft_putstr_fd("ERROR\n", 2);
	else
	{
		fordfulkerson(&param);
	}
	param_cleaner(&param);
	return (0);
}
