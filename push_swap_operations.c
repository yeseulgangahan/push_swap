/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:03:47 by yehan             #+#    #+#             */
/*   Updated: 2022/06/30 13:36:02 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/include/libft.h"
#include "push_swap_operations.h"

void	sa(t_stack *pstack)
{
	stack_swap(pstack);
	ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void	sb(t_stack *pstack)
{
	stack_swap(pstack);
	ft_putstr_fd("sb\n", STDOUT_FILENO);
}

void	pa(t_stack *pstack1, t_stack *pstack2)
{
	stack_push(pstack1, pstack2);
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}

void	pb(t_stack *pstack1, t_stack *pstack2)
{
	stack_push(pstack1, pstack2);
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}

void	ra(t_stack *pstack)
{
	stack_rotate(pstack, 1);
	ft_putstr_fd("ra\n", STDOUT_FILENO);
}
