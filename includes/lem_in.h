/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:36:45 by phnguyen          #+#    #+#             */
/*   Updated: 2021/12/24 07:17:01 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define INF_MAX 2147483647

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include "parser.h"

typedef struct s_path
{
	int		dist;
	int 	index;
	t_list	*path;
}	t_path;

void	fordfulkerson(t_config *conf);

#endif