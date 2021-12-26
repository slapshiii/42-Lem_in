/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 04:07:30 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/26 18:55:43 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	parser_nb_ants(t_config *conf, t_state *state, char *str)
{
	int	res;

	if (!ft_isnumber(str))
		*state = error;
	else
	{
		res = ft_atoi(str);
		if (res < 1)
			*state = error;
		else
			*state = room;
		conf->nb_ants = res;
	}
}

static void	parser_room(t_config *conf, t_state *state, char *str)
{
	char	**tab;

	tab = ft_split(str, WS);
	*state = addroom(conf, state, tab);
	ft_deletesplit(tab);
}

/*
**	does not search for separator in the first char
**	if a node name is empty, an error is shown in addedge
*/
static void	parser_tube(t_config *conf, t_state *state, char *str)
{
	char	*tab[2];
	char	*sep;

	sep = ft_strchr(str + 1, '-');
	if (sep == NULL)
		return ;
	tab[1] = ft_strdup(sep + 1);
	tab[0] = ft_strndup(str, (size_t)(sep - str));
	*state = addedge(conf, tab);
	free(tab[0]);
	free(tab[1]);
	ft_bzero(tab, sizeof(char *) * 2);
}

/*
**	return 1 if not comment
**	return 0 otherwise
*/
static int	parser_comment(t_config *conf, t_state *state, char *str)
{
	if (str[0] && str[0] == '#')
	{
		if (ft_strncmp("##", str, 2) == 0 && conf->nb_ants == 0)
			*state = error;
		else if (ft_strcmp(str, "##start") == 0)
		{
			if ((conf->valid & 0b010) == 0)
				*state = r_start;
			else
				*state = error;
			conf->valid |= 1 << 1;
		}
		else if (ft_strcmp(str, "##end") == 0)
		{
			if ((conf->valid & 0b100) == 0)
				*state = r_end;
			else
				*state = error;
			conf->valid |= 1 << 2;
		}
		return (0);
	}
	return (1);
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
		if (parser_comment(conf, &state, line))
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
	ft_putchar_fd('\n', 1);
	free(line);
	if (state != tube || conf->valid != 0b110 || conf->nb_ants == 0)
		return (1);
	return (0);
}
