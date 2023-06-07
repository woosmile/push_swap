/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:00:24 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/10 21:29:05 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef enum e_cmd
{
	SA = 1,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_cmd;

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

long	ft_atol(const char *str);
char	*ft_strjoin(char *s1, char *s2);

void	check_argv(int ac, char **av);

void	free_av_arr(char **av_arr, int av_arr_idx);
int		*argv_to_number(int ac, char **av, int av_idx, int *num_arr_count);
t_node	*connect_arg_value(int ac, char **av, t_node *head, t_node *head_temp);

t_cmd	check_operation(char *op_temp, size_t op_len);
void	op_main(char *op, t_stack *a, t_stack *b);

void	do_sa(t_stack *a);
void	do_sb(t_stack *b);
void	do_ss(t_stack *a, t_stack *b);

void	do_pa(t_stack *a, t_stack *b);
void	do_pb(t_stack *a, t_stack *b);

void	do_ra(t_stack *a);
void	do_rb(t_stack *b);
void	do_rr(t_stack *a, t_stack *b);

void	do_rra(t_stack *a);
void	do_rrb(t_stack *b);
void	do_rrr(t_stack *a, t_stack *b);

#endif