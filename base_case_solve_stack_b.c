/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_case_solve_stack_b.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 07:47:36 by yehan             #+#    #+#             */
/*   Updated: 2022/07/03 07:55:03 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_last_3_data(t_pushswap *pushswap)
{
	t_data	d1;
	t_data	d2;
	t_data	d3;

	d1 = pushswap->stack_b->tail->next->data;
	d2 = pushswap->stack_b->tail->next->next->data;
	d3 = pushswap->stack_b->tail->next->next->next->data;
	if (d1 < d2 && d2 < d3 && d1 < d3)
		sort_123_stack_b(pushswap);
	else if (d1 < d2 && d2 > d3 && d1 < d3)
		sort_132_stack_b(pushswap);
	else if (d1 > d2 && d2 < d3 && d1 < d3)
		sort_213_stack_b(pushswap);
	else if (d1 < d2 && d2 > d3 && d1 > d3)
		sort_231_stack_b(pushswap);
	else if (d1 > d2 && d2 < d3 && d1 > d3)
		sort_312_stack_b(pushswap);
}

void	base_case_solve_stack_b(t_pushswap *pushswap, size_t len)
{
	if (len == 2)
	{
		sb(pushswap->stack_b);
		pa(pushswap->stack_b, pushswap->stack_a);
		pa(pushswap->stack_b, pushswap->stack_a);
	}
	else if (len == 3)
		sort_last_3_data(pushswap);
}
