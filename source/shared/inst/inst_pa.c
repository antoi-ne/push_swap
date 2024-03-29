/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_pa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:59:42 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/04 13:14:47 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	inst_pa(t_stack *st_a, t_stack *st_b)
{
	if (st_b->len < 1)
		return ;
	st_a->data[st_a->len] = st_b->data[st_b->len - 1];
	st_b->data[st_b->len - 1] = 0;
	st_b->len -= 1;
	st_a->len += 1;
}
