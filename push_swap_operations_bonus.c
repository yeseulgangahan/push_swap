/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:10:46 by yehan             #+#    #+#             */
/*   Updated: 2022/07/01 08:13:20 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_operations_bonus.h"

void	sa_silent(t_stack *pstack)
{
	if (stack_count(pstack) >= 2)
	{
		stack_swap(pstack);
	}
}

void	sb_silent(t_stack *pstack)
{
	if (stack_count(pstack) >= 2)
	{
		stack_swap(pstack);
	}
}

void	ss_silent(t_stack *pstack1, t_stack *pstack2)
{
	if (stack_count(pstack1) >= 2)
		stack_swap(pstack1);
	if (stack_count(pstack2) >= 2)
		stack_swap(pstack2);
}

void	pa_silent(t_stack *pstack1, t_stack *pstack2)
{
	if (stack_count(pstack1) != 0)
	{
		stack_push(pstack1, pstack2);
	}
}

void	pb_silent(t_stack *pstack1, t_stack *pstack2)
{
	if (stack_count(pstack1) != 0)
	{
		stack_push(pstack1, pstack2);
	}
}
