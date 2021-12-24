/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 03:42:45 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/24 01:32:24 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "node.h"

# define WS " \t\r"

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
	int		valid;
	t_list	*nodes;
}	t_config;

int		parse_input(t_config *conf);

t_state	addroom(t_config *conf, t_state	*state, char **tab);
t_state addedge(t_config *conf, char **tab);

#endif