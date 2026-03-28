/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_utils.c                                     :+:      ::::::::   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:00:00 by woosekim          #+#    #+#             */
/*   Updated: 2026/03/28 12:00:00 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_minimum(t_stack *a)
{
	int		min;
	t_node	*node;

	if (!a->top)
		return (0);
	min = a->top->num;
	node = a->top->next;
	while (node)
	{
		if (min > node->num)
			min = node->num;
		node = node->next;
	}
	return (min);
}

int	search_node(t_stack *a, int num)
{
	t_node	*node;
	int		over_min;
	int		found;

	node = a->top;
	over_min = 0;
	found = 0;
	while (node)
	{
		if (node->num > num)
		{
			if (!found || node->num < over_min)
			{
				over_min = node->num;
				found = 1;
			}
		}
		node = node->next;
	}
	if (!found)
		return (search_minimum(a));
	return (over_min);
}

int	rot_cycle(t_stack *common, int num, t_cycle *common_node)
{
	int		rot;
	int		mid;
	t_node	*node;

	rot = 0;
	mid = common->size / 2;
	node = common->top;
	while (rot <= mid && node)
	{
		if (node->num == num)
		{
			common_node->rev_temp = 0;
			common_node->rot_temp = rot;
			return (rot);
		}
		node = node->next;
		rot++;
	}
	rot = 0;
	node = common->bot;
	while (rot < mid && node)
	{
		rot++;
		if (node->num == num)
		{
			common_node->rev_temp = 1;
			common_node->rot_temp = rot;
			return (rot);
		}
		node = node->prev;
	}
	return (0);
}

void	find_min_rot(t_stack *a, t_stack *b, t_cycle *a_node, t_cycle *b_node)
{
	int		min;
	int		min_new;
	t_node	*node;
	t_cycle	a_temp;
	t_cycle	b_temp;

	min = rot_cycle(a, search_node(a, b->top->num), &a_temp) + 0;
	*a_node = a_temp;
	a_node->rev = a_temp.rev_temp;
	a_node->rot = a_temp.rot_temp;
	b_node->rev = 0;
	b_node->rot = 0;
	node = b->top->next;
	while (node)
	{
		min_new = rot_cycle(b, node->num, &b_temp) + \
				rot_cycle(a, search_node(a, node->num), &a_temp);
		if (min > min_new)
		{
			min = min_new;
			*a_node = a_temp;
			a_node->rev = a_temp.rev_temp;
			a_node->rot = a_temp.rot_temp;
			*b_node = b_temp;
			b_node->rev = b_temp.rev_temp;
			b_node->rot = b_temp.rot_temp;
		}
		node = node->next;
	}
}

void	rotate_both(t_stack *a, t_stack *b, t_cycle *a_node, t_cycle *b_node)
{
	if (a_node->rev == 0 && b_node->rev == 0)
	{
		while (a_node->rot > 0 && b_node->rot > 0)
		{
			ps_rr(a, b);
			a_node->rot--;
			b_node->rot--;
		}
	}
	else if (a_node->rev == 1 && b_node->rev == 1)
	{
		while (a_node->rot > 0 && b_node->rot > 0)
		{
			ps_rrr(a, b);
			a_node->rot--;
			b_node->rot--;
		}
	}
}

void	rotate_a(t_stack *a, t_cycle *a_node)
{
	while (a_node->rot > 0)
	{
		if (a_node->rev == 0)
			ps_ra(a);
		else
			ps_rra(a);
		a_node->rot--;
	}
}

void	rotate_b(t_stack *b, t_cycle *b_node)
{
	while (b_node->rot > 0)
	{
		if (b_node->rev == 0)
			ps_rb(b);
		else
			ps_rrb(b);
		b_node->rot--;
	}
}

void	align_a(t_stack *a, int min_num)
{
	t_cycle	a_min;

	rot_cycle(a, min_num, &a_min);
	while (a_min.rot_temp > 0)
	{
		if (a_min.rev_temp == 0)
			ps_ra(a);
		else
			ps_rra(a);
		(a_min.rot_temp)--;
	}
}
