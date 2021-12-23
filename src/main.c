/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:37:27 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/23 23:39:12 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_config(t_config conf)
{
	t_list	*node;
	t_list	*edges;
	t_node	*elem;

	node = conf.nodes;
	printf("\n\nPRINT CONTENT\nnb_ants: %d\nnb_nodes: %d\nvalid: %d\n-----\n",
		conf.nb_ants, conf.nb_nodes, conf.valid);
	while (node)
	{
		elem = (t_node *)(node->content);
		edges = elem->edge;
		if (elem->pos == p_room)
			printf("\t");
		else if (elem->pos == p_start)
			printf("start\t");
		else
			printf("end\t");
		printf("name: %s %d-%d [", (char *)(elem->name), elem->coord.x, elem->coord.y);
		while (edges)
		{
			printf("%s", (char *)edges->content);
			edges = edges->next;
		}
		printf("]\n");
		node = node->next;
	}
}

int	main(int ac, char **av)
{
	t_config	conf;

	(void)av;
	if (ac != 1)
	{
		ft_putstr_fd("./lem-in: error: Invalid arguments\n", 2);
		return (1);
	}
	if (parse_input(&conf))
	{
		ft_putstr_fd("./lem-in: error: Error in input\n", 2);
		//return (2);
	}
	print_config(conf);
	free_parser(&conf);
	sleep(10);
	return (0);
}
