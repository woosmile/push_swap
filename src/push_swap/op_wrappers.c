/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_wrappers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:00:00 by woosekim          #+#    #+#             */
/*   Updated: 2026/03/28 12:00:00 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sa(t_stack *a)
{
	core_sa(a);
	write(1, "sa\n", 3);
}

void	ps_sb(t_stack *b)
{
	core_sb(b);
	write(1, "sb\n", 3);
}

void	ps_ss(t_stack *a, t_stack *b)
{
	core_ss(a, b);
	write(1, "ss\n", 3);
}

void	ps_pa(t_stack *a, t_stack *b)
{
	core_pa(a, b);
	write(1, "pa\n", 3);
}

void	ps_pb(t_stack *a, t_stack *b)
{
	core_pb(a, b);
	write(1, "pb\n", 3);
}

void	ps_ra(t_stack *a)
{
	core_ra(a);
	write(1, "ra\n", 3);
}

void	ps_rb(t_stack *b)
{
	core_rb(b);
	write(1, "rb\n", 3);
}

void	ps_rr(t_stack *a, t_stack *b)
{
	core_rr(a, b);
	write(1, "rr\n", 3);
}

void	ps_rra(t_stack *a)
{
	core_rra(a);
	write(1, "rra\n", 4);
}

void	ps_rrb(t_stack *b)
{
	core_rrb(b);
	write(1, "rrb\n", 4);
}

void	ps_rrr(t_stack *a, t_stack *b)
{
	core_rrr(a, b);
	write(1, "rrr\n", 4);
}
