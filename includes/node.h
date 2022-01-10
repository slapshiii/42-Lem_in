/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 03:06:06 by phnguyen          #+#    #+#             */
/*   Updated: 2022/01/06 16:13:18 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

# include "libft.h"

typedef enum pos
{
	p_room = 0,
	p_start,
	p_end
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
	int		visited;
	int		index;
	int		weight;
	int		parent;
}	t_node;

t_node	*new_node(char *name, t_pos pos, t_coord coord, int index);
void	del_node(void *node);
void	print_node(void *node);
void	reset_node(void *node);

int		node_by_name(void *node_value, void *value);

#endif
