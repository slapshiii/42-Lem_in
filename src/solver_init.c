/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:10:41 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/26 16:30:37 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_tunnel	init_tunnel(t_path *path)
{
	t_tunnel	res;
	t_list		*curr;
	int			i;

	curr = path->path->next;
	i = 0;
	res = (t_tunnel){0, 0, path->index, path->dist, NULL};
	res.room_name = (char **)malloc(sizeof(char *) * res.dist);
	if (res.room_name)
	{
		while (curr)
		{
			res.room_name[i] = (char *)curr->content;
			curr = curr->next;
			++i;
		}
	}
	if (i != res.dist)
	{
		free(res.room_name);
		res.room_name = NULL;
	}
	return (res);
}

t_tunnel	*init_tunnels(t_config *conf)
{
	t_tunnel	*res;
	t_list		*p;
	t_path		*data;

	p = conf->paths;
	res = (t_tunnel *)malloc(sizeof(t_tunnel) * conf->nb_paths);
	if (res)
	{
		while (p)
		{
			data = (t_path *)p->content;
			res[data->index] = init_tunnel(data);
			if (res[data->index].room_name == NULL)
			{
				free(res);
				res = NULL;
				return (res);
			}
			p = p->next;
		}
	}
	return (res);
}

void	assign_ants(t_config *conf, t_solver *solver)
{
	int	i;
	int	turn;

	turn = 1;
	while (solver->ants_remaining)
	{
		i = -1;
		while (++i < conf->nb_paths && solver->ants_remaining)
		{
			if (solver->ar_tuns[i].dist % turn)
			{
				++solver->ar_tuns[i].nb_ants;
				--solver->ants_remaining;
			}
		}
		++turn;
	}
}

t_solver	*init_solver(t_config *conf)
{
	t_solver	*solver;

	solver = (t_solver *)malloc(sizeof(t_solver));
	if (!solver)
		return (NULL);
	solver->ants_remaining = conf->nb_ants;
	solver->ar_tuns = init_tunnels(conf);
	if (solver->ar_tuns)
		assign_ants(conf, solver);
	else
	{
		free (solver);
		solver = NULL;
	}
	return (solver);
}
