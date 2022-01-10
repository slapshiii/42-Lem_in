/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 03:42:45 by phnguyen          #+#    #+#             */
/*   Updated: 2022/01/10 17:57:56 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "node.h"

# define WS " \t\r"

# define NOLINK 0
# define LINK 1
# define USED 2
# define RESIDUAL 3

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

typedef struct s_path
{
	int		dist;
	int		index;
	t_list	*path;
}	t_path;

typedef struct s_tunnel
{
	int		nb_ants;
	int		index;
	int		dist;
	int		*room_occupant;
	char	**room_name;
}	t_tunnel;

typedef struct s_solver
{
	int			ants_remaining;
	t_tunnel	*ar_tuns;
}	t_solver;

typedef struct config
{
	int			nb_ants;
	int			nb_nodes;
	int			nb_edges;
	int			valid;
	int			end;
	int			start;
	int			**edges;
	t_list		*nodes;
}	t_config;

int		parse_input(t_config *conf);
t_list	*get_elem(t_list **list, char *name);

t_state	addroom(t_config *conf, t_state	*state, char **tab);
t_state	addedge(t_config *conf, char **tab);
int		init_edges(t_config *conf);

#endif