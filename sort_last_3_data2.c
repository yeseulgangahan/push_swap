/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_last_3_data2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:14:58 by yehan             #+#    #+#             */
/*   Updated: 2022/06/30 11:15:24 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_123(t_pushswap *pushswap)
{
	sb(pushswap->stack_b);
	pa(pushswap->stack_b, pushswap->stack_a);
	sb(pushswap->stack_b);
	pa(pushswap->stack_b, pushswap->stack_a);
	sa(pushswap->stack_a);
	pa(pushswap->stack_b, pushswap->stack_a);
}

void	sort_132(t_pushswap *pushswap)
{
	sb(pushswap->stack_b);
	pa(pushswap->stack_b, pushswap->stack_a);
	sb(pushswap->stack_b);
	pa(pushswap->stack_b, pushswap->stack_a);
	pa(pushswap->stack_b, pushswap->stack_a);
}

void	sort_213(t_pushswap *pushswap)
{
	pa(pushswap->stack_b, pushswap->stack_a);
	sb(pushswap->stack_b);
	pa(pushswap->stack_b, pushswap->stack_a);
	sa(pushswap->stack_a);
	pa(pushswap->stack_b, pushswap->stack_a);
}

void	sort_231(t_pushswap *pushswap)
{
	pa(pushswap->stack_b, pushswap->stack_a);
	pa(pushswap->stack_b, pushswap->stack_a);
	sa(pushswap->stack_a);
	pa(pushswap->stack_b, pushswap->stack_a);
}

void	sort_312(t_pushswap *pushswap)
{
	pa(pushswap->stack_b, pushswap->stack_a);
	sb(pushswap->stack_b);
	pa(pushswap->stack_b, pushswap->stack_a);
	pa(pushswap->stack_b, pushswap->stack_a);
}
