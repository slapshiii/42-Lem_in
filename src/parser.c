/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 04:07:30 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/14 05:16:15 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	parser_nb_ants(t_config *conf, t_state *state, char *str)
{
	int	res;

	res = ft_atoi(str);
	if (res < 1)
	{
		*state = error;
		dprintf(2, "./lem-in: Error: number_of_ants invalid.\n");
	}
	else
		*state = room;
	conf->nb_ants = res;
}

static void	parser_room(t_config *conf, t_state *state, char *str)
{
	char	**tab;
	if (!ft_strcmp(str, "##start"))
		*state = r_start;
	else if (!ft_strcmp(str, "##end"))
		*state = r_end;
	else
	{
		++conf->nb_nodes;
		tab = ft_split(str, WS);
		push_front(&conf->nodes, tab[0]);
	}
}

/*
**	return 1 if failed
**	return 0 otherwise
*/
int	parse_input(t_config *conf)
{
	t_state	state;
	char	*line;

	state = nb_ants;
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '#' && line[1] != '#')
			break;
		if (state == nb_ants)
			parser_nb_ants(conf, &state, line);
		else if (state == room)
			parser_room(conf, &state, line);
		else if (state == tube)
			;
		else if (state == error)
			;
		free(line);
	}
	free(line);
	if (state == tube)
		return (0);
	return (1);
}
