/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 03:06:06 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/16 03:10:49 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

# include "libft.h"

typedef enum pos
{
	start = 0,
	end,
	room
}	t_pos;

typedef struct coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct node
{
	char	*name;
	t_pos	pos;
	t_coord	coord;
	t_list	*edge;
}	t_node;


#endif