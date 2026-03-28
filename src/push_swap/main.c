/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:00:00 by woosekim          #+#    #+#             */
/*   Updated: 2026/03/28 12:00:00 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	check_argv(ac, av);
	a = init_stack();
	b = init_stack();
	if (!a || !b)
		exit_error();
	fill_stack_a(a, ac, av);
	if (a->size <= 1)
	{
		clear_stack(a);
		clear_stack(b);
		return (0);
	}
	if (a->size <= 5)
		op_five_under(a, b);
	else
		op_main(a, b);
	clear_stack(a);
	clear_stack(b);
	return (0);
}
