/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:12:39 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/27 12:40:36 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "shared.h"
# include "carbon/llst.h"
# include <sys/types.h>

t_llst	*sh_reader(void);

void	sh_interpreter(t_llst *insts, t_stack *st_a, t_stack *st_b);

int		sh_inspector(t_stack *st_a, t_stack *st_b);

#endif
