/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 13:57:40 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 09:18:01 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include <stdio.h>

int		ps_sort(t_stack *st_a, t_stack *st_b, t_llst **insts)
{
	size_t	n;
	size_t	prt;

	n = st_a->len;
	prt = stack_prtlast(st_a);
	if (prt)
		n = n - prt - 1;
	if (n < 1 || n > 3)
		return (1);
	if (n == 2 || n == 3)
		if (st_a->data[st_a->len - 1] > st_a->data[st_a->len - 2])
			inst_save("sa", insts, st_a, st_b);
	if (n == 3)
	{
		if (st_a->data[st_a->len - 3] < st_a->data[st_a->len - 2])
		{
			inst_save("pb", insts, st_a, st_b);
			inst_save("sa", insts, st_a, st_b);
			inst_save("pa", insts, st_a, st_b);
			if (st_a->data[st_a->len - 1] > st_a->data[st_a->len - 2])
				inst_save("sa", insts, st_a, st_b);
		}
	}
	return (0);
}
