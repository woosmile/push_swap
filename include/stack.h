/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:00:00 by woosekim          #+#    #+#             */
/*   Updated: 2026/03/28 12:00:00 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_node
{
	int				num;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bot;
}	t_stack;

/* Stack Management */
t_stack	*init_stack(void);
void	clear_stack(t_stack *stack);
t_node	*new_node(int num);
void	fill_stack_a(t_stack *a, int ac, char **av);

/* Core Operations (Silent) */
void	core_sa(t_stack *a);
void	core_sb(t_stack *b);
void	core_ss(t_stack *a, t_stack *b);

void	core_pa(t_stack *a, t_stack *b);
void	core_pb(t_stack *a, t_stack *b);

void	core_ra(t_stack *a);
void	core_rb(t_stack *b);
void	core_rr(t_stack *a, t_stack *b);

void	core_rra(t_stack *a);
void	core_rrb(t_stack *b);
void	core_rrr(t_stack *a, t_stack *b);

#endif
