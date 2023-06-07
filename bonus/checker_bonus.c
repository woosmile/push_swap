/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:00:27 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/09 19:43:13 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	op_comb(char **op, ssize_t read_len)
{
	char	buffer[2];
	char	*op_temp;

	op_temp = ft_strdup("");
	*op = ft_strdup("");
	read_len = read(0, buffer, 1);
	while (read_len != 0)
	{
		buffer[read_len] = 0;
		op_temp = ft_strjoin(op_temp, buffer);
		if (buffer[0] == '\n')
		{
			if (!check_operation(op_temp, ft_strlen(op_temp)))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			*op = ft_strjoin(*op, op_temp);
			free(op_temp);
			op_temp = ft_strdup("");
		}
		read_len = read(0, buffer, 1);
	}
	free(op_temp);
}

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

void	check_align(t_stack a, t_stack b)
{
	int	align;

	align = 1;
	if (b.size == 0)
	{
		while (a.top->next != 0)
		{
			if (a.top->num > a.top->next->num)
			{
				align = 0;
				break ;
			}
			else
				a.top = a.top->next;
		}
	}
	else
		align = 0;
	if (align)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
	char	*op;
	t_node	*head;
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		return (0);
	check_argv(ac, av);
	op_comb(&op, 0);
	head = connect_arg_value(ac, av, 0, 0);
	initial_stack(head, &a, &b);
	op_main(op, &a, &b);
	check_align(a, b);
	clear_stack(a, b);
	return (0);
}
