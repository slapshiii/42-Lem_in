/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:16:43 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/26 21:37:40 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	printer(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		ft_putstr_fd((char *)tmp->content, 1);
		if (tmp->next)
			ft_putchar_fd(' ', 1);
		tmp = tmp->next;
	}
	if (ft_lstsize(lst))
		ft_putchar_fd('\n', 1);
}

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

/*
**	num -> x x-1 x-2
*/
void	print_tun_state(int *gone, t_tunnel *t, t_config *conf)
{
	int		room_index;
	char	*buf;

	room_index = t->dist - 1;
	if (conf->solver->ants_remaining < conf->nb_ants && t->nb_ants > 0)
	{
		++conf->solver->ants_remaining;
		t->room_occupant[0] = conf->solver->ants_remaining;
		--t->nb_ants;
	}
	while (room_index >= 0)
	{
		if (t->room_occupant[room_index] != -1)
		{
			*gone = 0;
			buf = format_output(t->room_occupant[room_index],
					t->room_name[room_index]);
			ft_lstadd_back(&conf->out, ft_lstnew(buf));
		}
		--room_index;
	}
	ft_memmove(&t->room_occupant[1], &t->room_occupant[0],
		(t->dist - 1) * sizeof(int));
	t->room_occupant[0] = -1;
}

void	print_soluce(t_config *conf)
{
	int		i;
	int		gone;

	i = 0;
	gone = 0;
	while (gone == 0)
	{
		i = 0;
		gone = 1;
		while (i < conf->nb_paths)
		{
			print_tun_state(&gone, &(conf->solver->ar_tuns[i]), conf);
			++i;
		}
		printer(conf->out);
		ft_lstclear(&conf->out, free);
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
