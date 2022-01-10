/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 01:34:57 by phnguyen          #+#    #+#             */
/*   Updated: 2022/01/10 19:20:49 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void	fordfulkerson(t_lemin *conf)
{
	int	i;
	int	j;

	i = 0;
	printf("nb_ants:%d\nnb_nodes:%d\nnb_edges:%d\nnb_paths:%d\nend:%d\nstart:%d\n",
		conf->nb_ants, conf->nb_nodes, conf->nb_edges, conf->nb_paths, conf->end, conf->start);
	while (i < conf->nb_nodes)
	{
		j = 0;
		printf("\n[%d]%s:", i, (conf->n[i])->name);
		while (j < conf->nb_nodes)
		{
			if (conf->edges[i][j] != NOLINK)
				printf("%s-", (conf->n[j])->name);
			++j;
		}
		++i;
	}
}
