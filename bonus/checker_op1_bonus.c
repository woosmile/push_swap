/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:16:04 by woosekim          #+#    #+#             */
/*   Updated: 2023/03/30 16:34:12 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	do_sa(t_stack *a)
{
	t_node	*temp;

	if (a->size > 1)
	{
		temp = a->top;
		a->top = a->top->next;
		a->top->prev = 0;
		if (a->size > 2)
			a->top->next->prev = temp;
		temp->next = a->top->next;
		temp->prev = a->top;
		a->top->next = temp;
		if (a->size == 2)
			a->bot = temp;
	}
}

void	do_sb(t_stack *b)
{
	t_node	*temp;

	if (b->size > 1)
	{
		temp = b->top;
		b->top = b->top->next;
		b->top->prev = 0;
		if (b->size > 2)
			b->top->next->prev = temp;
		temp->next = b->top->next;
		temp->prev = b->top;
		b->top->next = temp;
		if (b->size == 2)
			b->bot = temp;
	}
}

void	do_ss(t_stack *a, t_stack *b)
{
	do_sa(a);
	do_sb(b);
}
