/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 04:07:30 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/24 01:32:14 by phnguyen         ###   ########.fr       */
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
		ft_putstr_fd("./lem-in: Error: number_of_ants invalid.\n", 2);
	}
	else
		*state = room;
	conf->nb_ants = res;
}

static void	parser_room(t_config *conf, t_state *state, char *str)
{
	char	**tab;

	tab = ft_split(str, WS);
	if (!ft_strcmp(str, "##start"))
	{
		if ((conf->valid & 0b010) == 0)
			*state = r_start;
		else
			*state = error;
		conf->valid |= 1 << 1;
	}
	else if (!ft_strcmp(str, "##end"))
	{
		if ((conf->valid & 0b100) == 0)
			*state = r_end;
		else
			*state = error;
		conf->valid |= 1 << 2;
	}
	else
		*state = addroom(conf, state, tab);
	ft_deletesplit(tab);
}

static void	parser_tube(t_config *conf, t_state *state, char *str)
{
	char	**tab;

	tab = ft_split(str, "-");
	if (!tab[0] || !tab[1] || tab[2])
		*state = error;
	else
		*state = addedge(conf, tab);
	ft_deletesplit(tab);
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
		if (line[0] && !(line[0] == '#' && line[1] != '#'))
		{
			if (state == nb_ants)
				parser_nb_ants(conf, &state, line);
			else if (state >= room && state <= r_end)
				parser_room(conf, &state, line);
			if (state == tube)
				parser_tube(conf, &state, line);
		}
		ft_putendl_fd(line, 1);
		free(line);
		if (state == error)
			return (1);
	}
	free(line);
	if (state != tube || conf->valid != 6)
		return (1);
	return (0);
}