/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:00:27 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/13 13:58:06 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initial_stack(t_node *head, t_stack *a, t_stack *b)
{
	int		size;
	t_node	*head_temp;

	size = 0;
	head_temp = head;
	a->top = head;
	while (head_temp->next != 0)
		head_temp = head_temp->next;
	a->bot = head_temp;
	head_temp = head;
	while (head_temp != 0)
	{
		size++;
		head_temp = head_temp->next;
	}
	a->size = size;
	b->size = 0;
}

void	clear_stack(t_stack a, t_stack b)
{
	t_node	*temp;

	while (a.size > 0)
	{
		temp = a.top->next;
		free(a.top);
		a.top = temp;
		a.size--;
	}
	while (b.size > 0)
	{
		temp = b.top->next;
		free(b.top);
		b.top = temp;
		b.size--;
	}
}

int	main(int ac, char **av)
{
	t_node	*head;
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		return (0);
	check_argv(ac, av);
	head = connect_arg_value(ac, av, 0, 0);
	if (head->next == 0)
	{
		free(head);
		return (0);
	}
	initial_stack(head, &a, &b);
	if (a.size <= 5)
		op_five_under(&a, &b);
	else
		op_main(&a, &b);
	clear_stack(a, b);
	return (0);
}
