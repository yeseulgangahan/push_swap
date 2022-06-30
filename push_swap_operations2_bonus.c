/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations2_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:03:43 by yehan             #+#    #+#             */
/*   Updated: 2022/07/01 08:13:24 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_operations_bonus.h"

void	ra_silent(t_stack *pstack)
{
	stack_rotate(pstack, 1);
}

void	rb_silent(t_stack *pstack)
{
	stack_rotate(pstack, 1);
}

void	rr_silent(t_stack *pstack1, t_stack *pstack2)
{
	stack_rotate(pstack1, 1);
	stack_rotate(pstack2, 1);
}

void	rra_silent(t_stack *pstack)
{
	stack_rotate(pstack, stack_count(pstack) - 1);
}

void	rrb_silent(t_stack *pstack)
{
	stack_rotate(pstack, stack_count(pstack) - 1);
}
