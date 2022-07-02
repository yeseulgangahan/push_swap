/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_case_solve_stack_b2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 07:47:25 by yehan             #+#    #+#             */
/*   Updated: 2022/07/03 08:18:37 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_123_stack_b(t_pushswap *pushswap)
{
	sb(pushswap->stack_b);
	pa(pushswap->stack_b, pushswap->stack_a);
	sb(pushswap->stack_b);
	pa(pushswap->stack_b, pushswap->stack_a);
	sa(pushswap->stack_a);
	pa(pushswap->stack_b, pushswap->stack_a);
}

void	sort_132_stack_b(t_pushswap *pushswap)
{
	sb(pushswap->stack_b);
	pa(pushswap->stack_b, pushswap->stack_a);
	sb(pushswap->stack_b);
	pa(pushswap->stack_b, pushswap->stack_a);
	pa(pushswap->stack_b, pushswap->stack_a);
}

void	sort_213_stack_b(t_pushswap *pushswap)
{
	pa(pushswap->stack_b, pushswap->stack_a);
	sb(pushswap->stack_b);
	pa(pushswap->stack_b, pushswap->stack_a);
	sa(pushswap->stack_a);
	pa(pushswap->stack_b, pushswap->stack_a);
}

void	sort_231_stack_b(t_pushswap *pushswap)
{
	pa(pushswap->stack_b, pushswap->stack_a);
	pa(pushswap->stack_b, pushswap->stack_a);
	sa(pushswap->stack_a);
	pa(pushswap->stack_b, pushswap->stack_a);
}

void	sort_312_stack_b(t_pushswap *pushswap)
{
	pa(pushswap->stack_b, pushswap->stack_a);
	sb(pushswap->stack_b);
	pa(pushswap->stack_b, pushswap->stack_a);
	pa(pushswap->stack_b, pushswap->stack_a);
}
