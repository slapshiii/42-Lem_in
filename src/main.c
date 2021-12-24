/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:37:27 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/24 01:15:45 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_config(t_config conf)
{
	printf("\n\nPRINT CONTENT\nnb_ants: %d\nnb_nodes: %d\nvalid: %d\n-----\n",
		conf.nb_ants, conf.nb_nodes, conf.valid);
	ft_lstiter(conf.nodes, print_node);
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
	ft_bzero(&conf, sizeof(t_config));
	if (parse_input(&conf))
	{
		ft_putstr_fd("./lem-in: error: Error in input\n", 2);
		return (2);
	}
	print_config(conf);
	free_parser(&conf);
	return (0);
}
