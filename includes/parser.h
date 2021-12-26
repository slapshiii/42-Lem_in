/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 03:42:45 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/25 21:46:45 by phnguyen         ###   ########.fr       */
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
	int		nb_paths;
	t_list	*nodes;
	t_list	*paths;
}	t_config;

int		parse_input(t_config *conf);

t_state	addroom(t_config *conf, t_state	*state, char **tab);
t_state addedge(t_config *conf, char **tab);

#endif