/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations3_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:10:05 by yehan             #+#    #+#             */
/*   Updated: 2022/07/06 12:23:05 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_operations_bonus.h"

void	rrr_silent(t_stack *pstack1, t_stack *pstack2)
{
	if (stack_count(pstack1) >= 2)
		stack_rotate(pstack1, stack_count(pstack1) - 1);
	if (stack_count(pstack2) >= 2)
		stack_rotate(pstack2, stack_count(pstack2) - 1);
}
