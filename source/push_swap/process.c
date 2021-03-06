/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:50:51 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/06 15:04:02 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include <stdio.h>

int		ps_process(t_stack *st_a, t_stack *st_b)
{
	t_llst	*partitions;
	size_t	i;

	i = 0;
	partitions = NULL;
	while (st_a->len > 3)
	{
		if (ps_split(st_a, st_b))
			return (1);
		stack_prtadd(st_b, st_b->len);
	}
	stacks_print(st_a, st_b);
	return (0);
}
