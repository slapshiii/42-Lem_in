/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:37:27 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/14 05:28:00 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(int ac, char **av)
{
	t_config	conf;

	if (ac != 1)
	{
		dprintf(2, "%s: Error: Invalid arguments\n", av[0]);
		return (1);
	}
	if (parse_input(&conf))
	{
		return (2);
	}
	return (0);
}
