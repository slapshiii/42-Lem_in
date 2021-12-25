/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:37:27 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/25 01:59:15 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_config(t_config conf)
{
	t_list	*p;
	t_list	*n;
	
	printf("\n\nPRINT CONTENT\nnb_ants: %d\nnb_nodes: %d\nvalid: %d\n-----\n",
		conf.nb_ants, conf.nb_nodes, conf.valid);
	ft_lstiter(conf.nodes, print_node);
	p = conf.paths;
	printf("\nPATHS:\n");
	while (p)
	{
		printf("P%d dist: %d [", ((t_path *)p->content)->index, ((t_path *)p->content)->dist);
		n = ((t_path *)p->content)->path;
		while (n)
		{
			printf("%s", (char *)n->content);
			n = n->next;
			if (n)
				printf("-");
		}
		printf("]\n");
		p = p->next;
	}
}

void	conf_cleaner(t_config *conf)
{
	ft_lstclear(&(conf->nodes), &del_node);
	ft_lstclear(&(conf->paths), &del_path);
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
	//print_config(conf);
	ft_putstr_fd("ford", 2);
	fordfulkerson(&conf);
	print_config(conf);
	printf("\n\nPRINT CONTENT\nnb_ants: %d\nnb_nodes: %d\nvalid: %d\n-----\n",
		conf.nb_ants, conf.nb_nodes, conf.valid);
	conf_cleaner(&conf);
	return (0);
}
