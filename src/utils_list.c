/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:05:55 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/14 05:11:54 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*new_node(void *data)
{
	t_list	*res;

	res = (t_list*)malloc(sizeof(t_list));
	if (!res)
		exit(1);
	res->data = data;
	res->next = NULL;
	return (res);
}

t_list	*push_front(t_list **list, void *data)
{
	t_list	*new;

	new = new_node(data);
	new->next = *list;
	*list = new;
	return new;
}
