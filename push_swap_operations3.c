/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:15:35 by yehan             #+#    #+#             */
/*   Updated: 2022/06/30 17:09:53 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/include/libft.h"
#include "push_swap_operations.h"

void	rrr(t_stack *pstack1, t_stack *pstack2)
{
	stack_rotate(pstack1, stack_count(pstack1) - 1);
	stack_rotate(pstack2, stack_count(pstack2) - 1);
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
