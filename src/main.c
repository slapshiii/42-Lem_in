/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:37:27 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/26 18:20:40 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	conf_cleaner(t_config *conf)
{
	int	i;

	i = 0;
	ft_lstclear(&(conf->nodes), &del_node);
	ft_lstclear(&(conf->paths), &del_path);
	if (conf->solver)
	{
		while (i < conf->nb_paths)
		{
			free((conf->solver->ar_tuns[i]).room_name);
			++i;
		}
		free(conf->solver->ar_tuns);
		free(conf->solver);
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
	ft_bzero(&conf, sizeof(t_config));
	if (parse_input(&conf))
	{
		ft_putstr_fd("ERROR\n", 2);
		return (2);
	}
	fordfulkerson(&conf);
	if (solver(&conf))
		ft_putstr_fd("ERROR\n", 2);
	conf_cleaner(&conf);
	return (0);
}
