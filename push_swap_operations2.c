/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:03:43 by yehan             #+#    #+#             */
/*   Updated: 2022/06/30 13:35:43 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/include/libft.h"
#include "push_swap_operations.h"

void	rb(t_stack *pstack)
{
	stack_rotate(pstack, 1);
	ft_putstr_fd("rb\n", STDOUT_FILENO);
}

void	rr(t_stack *pstack1, t_stack *pstack2)
{
	stack_rotate(pstack1, 1);
	stack_rotate(pstack2, 1);
	ft_putstr_fd("rr\n", STDOUT_FILENO);
}

void	rra(t_stack *pstack)
{
	stack_rotate(pstack, stack_count(pstack) - 1);
	ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	rrb(t_stack *pstack)
{
	stack_rotate(pstack, stack_count(pstack) - 1);
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	rrr(t_stack *pstack1, t_stack *pstack2)
{
	stack_rotate(pstack1, stack_count(pstack1) - 1);
	stack_rotate(pstack2, stack_count(pstack2) - 1);
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
