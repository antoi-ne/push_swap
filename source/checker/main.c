/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:13:53 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/04 12:19:54 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "shared.h"
#include "carbon.h"

int		main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (1);
	stack = stack_parse(argc, argv);
	if (!stack)
		return (print_error());
	stack_print(stack);
	return (0);
}
