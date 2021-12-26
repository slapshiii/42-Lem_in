/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:16:43 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/26 17:33:43 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*format_output(int n, char *name)
{
	char	*res;
	char	*num;
	size_t	len[2];

	num = ft_itoa(n);
	len[0] = ft_strlen(num);
	len[1] = ft_strlen(name);
	res = (char *)malloc(sizeof(char) * (len[0] + len[1] + 3));
	if (res)
	{
		res[0] = 'L';
		ft_memcpy(&res[1], num, len[0]);
		res[len[0] + 1] = '-';
		ft_memcpy(&res[len[0] + 2], name, len[1] + 1);
	}
	free(num);
	return (res);
}

void	print_tun_state(int *end, t_tunnel *t, t_config *conf)
{
	int		d;
	char	*buf;

	d = 0;
	while (d < t->dist)
	{
		if (t->current - d < t->nb_ants
			&& t->current - d >= 0)
		{
			if (!*end)
				ft_putchar_fd(' ', 1);
			*end = 0;
			buf = format_output((t->current - d) * conf->nb_paths
					+ t->index + 1, t->room_name[d]);
			ft_putstr_fd(buf, 1);
			free(buf);
		}
		++d;
	}
	++t->current;
}

void	print_soluce(t_config *conf)
{
	int		i;
	int		finished;

	i = 0;
	finished = 0;
	while (!finished)
	{
		finished = 1;
		i = 0;
		while (i < conf->nb_paths)
		{
			print_tun_state(&finished, &(conf->solver->ar_tuns[i]), conf);
			++i;
		}
		if (!finished)
			ft_putchar_fd('\n', 1);
	}
}

int	solver(t_config *conf)
{
	if (conf->nb_paths < 1)
		return (1);
	conf->solver = init_solver(conf);
	if (!conf->solver)
		return (1);
	print_soluce(conf);
	return (0);
}
