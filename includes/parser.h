/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 03:42:45 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/14 04:54:39 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "utils.h"

typedef enum state
{
	nb_ants = 0,
	room,
	r_start,
	r_end,
	tube,
	end,
	error
}	t_state;

typedef struct config
{
	int		nb_ants;
	int		nb_nodes;
	int		start;
	int		end;
	t_list	*edges;
	t_list	*nodes;
}	t_config;

int	parse_input(t_config *conf);

#endif