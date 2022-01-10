/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:36:45 by phnguyen          #+#    #+#             */
/*   Updated: 2022/01/10 19:20:23 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define INF_MAX 2147483647

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include "parser.h"

typedef struct s_lemin {
	int			nb_ants;
	int			nb_nodes;
	int			nb_paths;
	int			nb_edges;
	int			end;
	int			start;
	int			**edges;
	t_node		**n;
}	t_lemin;

void		fordfulkerson(t_lemin *conf);

#endif