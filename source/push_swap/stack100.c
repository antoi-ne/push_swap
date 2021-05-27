/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:45:00 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/27 12:39:07 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"
#include "carbon/str.h"

static size_t	find_edge(t_stack *st_a, t_stack *st_b, t_llst **insts)
{
	ssize_t	i;
	size_t	min;
	size_t	max;

	min = 0;
	max = 0;
	i = -1;
	while (++i < (ssize_t)st_b->len)
	{
		if (st_b->data[i] < st_b->data[min])
			min = i;
		else if (st_b->data[i] > st_b->data[max])
			max = i;
	}
	if (move_top_difficulty(st_b, min) > move_top_difficulty(st_b, max))
	{
		move_top(st_a, st_b, insts, max);
		inst_save("pa", insts, st_a, st_b);
		return (1);
	}
	move_top(st_a, st_b, insts, min);
	inst_save("pa", insts, st_a, st_b);
	inst_save("ra", insts, st_a, st_b);
	return (0);
}

static void	sort_to_a(t_stack *st_a, t_stack *st_b, t_llst **insts)
{
	size_t	rot;

	rot = 0;
	while (st_b->len > 0)
	{
		rot += find_edge(st_a, st_b, insts);
	}
	while (rot-- > 0)
		inst_save("ra", insts, st_a, st_b);
}

static void	move_chunk_to_b(t_stack *st_a, t_stack *st_b, t_llst **insts,
t_chunks *data)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = st_a->len;
	while (i < len)
	{
		if (st_a->data[st_a->len - 1] >= data->sorted[data->current_min]
			&& st_a->data[st_a->len - 1] <= data->sorted[data->current_max])
			inst_save("pb", insts, st_a, st_b);
		else
			inst_save("ra", insts, st_a, st_b);
		i++;
	}
}

void	ps_stack100(t_stack *st_a, t_stack *st_b, t_llst **insts)
{
	t_chunks	data;

	(void)insts;
	(void)st_b;
	data.sorted = sort_stack(st_a);
	data.size = st_a->size;
	data.chunks = 8;
	data.chunks_size = data.size / (data.chunks - 1);
	data.current = 0;
	while (data.current < data.chunks)
	{
		data.current_max = data.chunks_size * (data.current + 1);
		if (data.current_max > data.size - 1)
			data.current_max = data.size - 1;
		data.current_min = data.chunks_size * data.current;
		move_chunk_to_b(st_a, st_b, insts, &data);
		sort_to_a(st_a, st_b, insts);
		data.current++;
	}
}
