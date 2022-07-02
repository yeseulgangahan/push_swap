/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_case_solve_stack_a2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 08:15:07 by yehan             #+#    #+#             */
/*   Updated: 2022/07/03 08:17:05 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_321_stack_a(t_pushswap *pushswap)
{
	sa(pushswap->stack_a);
	pb(pushswap->stack_a, pushswap->stack_b);
	sa(pushswap->stack_a);
	pb(pushswap->stack_a, pushswap->stack_b);
	sb(pushswap->stack_b);
	pa(pushswap->stack_b, pushswap->stack_a);
	pa(pushswap->stack_b, pushswap->stack_a);
}

void	sort_132_stack_a(t_pushswap *pushswap)
{
	pb(pushswap->stack_a, pushswap->stack_b);
	sa(pushswap->stack_a);
	pa(pushswap->stack_b, pushswap->stack_a);
}

void	sort_213_stack_a(t_pushswap *pushswap)
{
	sa(pushswap->stack_a);
}

void	sort_231_stack_a(t_pushswap *pushswap)
{
	pb(pushswap->stack_a, pushswap->stack_b);
	sa(pushswap->stack_a);
	pa(pushswap->stack_b, pushswap->stack_a);
	sa(pushswap->stack_a);
}

void	sort_312_stack_a(t_pushswap *pushswap)
{
	pb(pushswap->stack_a, pushswap->stack_b);
	pb(pushswap->stack_a, pushswap->stack_b);
	sb(pushswap->stack_b);
	pa(pushswap->stack_b, pushswap->stack_a);
	sa(pushswap->stack_a);
	pa(pushswap->stack_b, pushswap->stack_a);
}
