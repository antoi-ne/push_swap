/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:12:59 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/06 11:27:34 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "shared.h"
#include <stddef.h>
#include <stdint.h>

int		ps_median(t_stack *st, size_t start, size_t end, int64_t *med);

int		ps_split(t_stack *st_a, t_stack *st_b);

#endif
