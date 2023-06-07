/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op_main_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:48:13 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/09 19:55:03 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_cmd	check_operation(char *op_temp, size_t op_len)
{
	if (!ft_strncmp(op_temp, "sa\n", op_len))
		return (SA);
	else if (!ft_strncmp(op_temp, "sb\n", op_len))
		return (SB);
	else if (!ft_strncmp(op_temp, "ss\n", op_len))
		return (SS);
	else if (!ft_strncmp(op_temp, "pa\n", op_len))
		return (PA);
	else if (!ft_strncmp(op_temp, "pb\n", op_len))
		return (PB);
	else if (!ft_strncmp(op_temp, "ra\n", op_len))
		return (RA);
	else if (!ft_strncmp(op_temp, "rb\n", op_len))
		return (RB);
	else if (!ft_strncmp(op_temp, "rr\n", op_len))
		return (RR);
	else if (!ft_strncmp(op_temp, "rra\n", op_len))
		return (RRA);
	else if (!ft_strncmp(op_temp, "rrb\n", op_len))
		return (RRB);
	else if (!ft_strncmp(op_temp, "rrr\n", op_len))
		return (RRR);
	else
		return (0);
}

void	op_distributor(t_cmd cmd, t_stack *a, t_stack *b)
{
	if (cmd == SA)
		do_sa(a);
	else if (cmd == SB)
		do_sb(b);
	else if (cmd == SS)
		do_ss(a, b);
	else if (cmd == PA)
		do_pa(a, b);
	else if (cmd == PB)
		do_pb(a, b);
	else if (cmd == RA)
		do_ra(a);
	else if (cmd == RB)
		do_rb(b);
	else if (cmd == RR)
		do_rr(a, b);
	else if (cmd == RRA)
		do_rra(a);
	else if (cmd == RRB)
		do_rrb(b);
	else if (cmd == RRR)
		do_rrr(a, b);
}

void	op_main(char *op, t_stack *a, t_stack *b)
{
	char	**op_arr;
	int		op_idx;
	t_cmd	cmd;

	op_idx = 0;
	op_arr = ft_split(op, '\n');
	free(op);
	while (op_arr[op_idx] != 0)
	{
		cmd = check_operation(op_arr[op_idx], ft_strlen(op_arr[op_idx]));
		op_distributor(cmd, a, b);
		free(op_arr[op_idx]);
		op_idx++;
	}
	free(op_arr[op_idx]);
	free(op_arr);
}
