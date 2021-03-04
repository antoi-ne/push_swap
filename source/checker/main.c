/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:13:53 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/04 16:05:03 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "shared.h"
#include "carbon.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_stack	*st_a;
	t_stack	*st_b;
	t_llst	*insts;
	t_llst	*node;

	if (argc < 2)
		return (1);
	st_a = stack_parse(argc, argv);
	if (!st_a)
		return (print_error());
	st_b = stack_new(st_a->size);
	if (!st_b)
		return (print_error());
	return (0);
	insts = sh_reader();
	if (!insts)
		return (print_error());
	node = insts;
	while (node)
	{
		printf("inst: %s\n", node->data);
		node = node->next;
	}
}
