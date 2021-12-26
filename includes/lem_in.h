/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:36:45 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/26 12:22:47 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define INF_MAX 2147483647

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include "parser.h"

void	del_path(void *path);
void	fordfulkerson(t_config *conf);
int 	solver(t_config *conf);

t_tunnel	init_tunnel(t_path *path);
t_tunnel	*init_tunnels(t_config *conf);
t_solver    *init_solver(t_config *conf);

#endif