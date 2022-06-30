/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:03:47 by yehan             #+#    #+#             */
/*   Updated: 2022/07/01 08:12:43 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_operations.h"

void	sa(t_stack *pstack)
{
	if (stack_count(pstack) >= 2)
	{
		stack_swap(pstack);
		ft_putstr_fd("sa\n", STDOUT_FILENO);
	}
}

void	sb(t_stack *pstack)
{
	if (stack_count(pstack) >= 2)
	{
		stack_swap(pstack);
		ft_putstr_fd("sb\n", STDOUT_FILENO);
	}
}

void	ss(t_stack *pstack1, t_stack *pstack2)
{
	if (stack_count(pstack1) >= 2)
		stack_swap(pstack1);
	if (stack_count(pstack2) >= 2)
		stack_swap(pstack2);
	if (stack_count(pstack1) >= 2 && stack_count(pstack1) >= 2)
		ft_putstr_fd("sb\n", STDOUT_FILENO);
}

void	pa(t_stack *pstack1, t_stack *pstack2)
{
	if (stack_count(pstack1) != 0)
	{
		stack_push(pstack1, pstack2);
		ft_putstr_fd("pa\n", STDOUT_FILENO);
	}
}

void	pb(t_stack *pstack1, t_stack *pstack2)
{
	if (stack_count(pstack1) != 0)
	{
		stack_push(pstack1, pstack2);
		ft_putstr_fd("pb\n", STDOUT_FILENO);
	}
}
