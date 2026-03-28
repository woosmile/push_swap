/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:00:00 by woosekim          #+#    #+#             */
/*   Updated: 2026/03/28 12:00:00 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "utils.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	stack->bot = NULL;
	return (stack);
}

void	clear_stack(t_stack *stack)
{
	t_node	*temp;
	t_node	*current;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	free(stack);
}

t_node	*new_node(int num)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->num = num;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	fill_stack_a(t_stack *a, int ac, char **av)
{
	t_node	*new;
	int		*num_arr;
	int		idx;
	int		count;

	num_arr = argv_to_number(ac, av, 1, &count);
	idx = 0;
	while (idx < count)
	{
		new = new_node(num_arr[idx]);
		if (!a->top)
		{
			a->top = new;
			a->bot = new;
		}
		else
		{
			a->bot->next = new;
			new->prev = a->bot;
			a->bot = new;
		}
		a->size++;
		idx++;
	}
	free(num_arr);
}
