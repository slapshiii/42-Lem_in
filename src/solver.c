/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:16:43 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/26 11:07:30 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int solver(t_config *conf)
{
    t_solver	*solver;

	solver = (t_solver *)malloc(sizeof(t_solver));
	if (solver)
	{
		ft_bzero(solver, sizeof(t_solver));
		solver->ar_path = (t_path *)malloc(sizeof(t_path) * conf->nb_paths);
	}
	return 0;
}