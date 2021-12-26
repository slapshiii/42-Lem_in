/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:16:43 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/26 14:48:08 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define CUR_PATH conf->solver->ar_tuns[i]

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

void	print_solver(t_config *conf)
{
	int	i;
	int	d;

	i = 0;
	while (i < conf->nb_paths)
	{
		d = 0;
		printf("T%d ants:%d path: ", (conf->solver->ar_tuns[i]).index,
			(conf->solver->ar_tuns[i]).nb_ants);
		while (d < (conf->solver->ar_tuns[i]).dist)
		{
			printf("%s ", (conf->solver->ar_tuns[i]).room_name[d]);
			++d;
		}
		printf("\n");
		++i;
	}
}

void	print_soluce(t_config *conf)
{
	int		i;
	int		finished;
	int		d;
	char	*buf;

	i = 0;
	finished = 0;
	while (!finished)
	{
		finished = 1;
		i = 0;
		while (i < conf->nb_paths)
		{
			d = 0;
			while (d < CUR_PATH.dist)
			{
				if (CUR_PATH.current - d < CUR_PATH.nb_ants
					&& CUR_PATH.current - d >= 0)
				{
					if (!finished)
						ft_putchar_fd(' ', 1);
					finished = 0;
					buf = format_output((CUR_PATH.current - d)* conf->nb_paths +
						CUR_PATH.index + 1, CUR_PATH.room_name[d]);
					ft_putstr_fd(buf, 1);
					free(buf);
				}
				++d;
			}
			++CUR_PATH.current;
			++i;
		}
		if (!finished)
			ft_putchar_fd('\n', 1);
	}
}

int 	solver(t_config *conf)
{
    conf->solver = init_solver(conf);
	if (!conf->solver)
		return (1);
	//print_solver(conf);
	print_soluce(conf);
	return (0);
}