/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:06:07 by yehan             #+#    #+#             */
/*   Updated: 2022/06/30 13:35:16 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_stack.h"
#include "./libft/include/libft.h"

void	stack_init(t_stack *pstack)
{
	pstack = ft_calloc(1, sizeof(t_stack));
	clist_init(pstack);
}

int	stack_count(t_stack *pstack)
{
	return (clist_count(pstack));
}

int	stack_peek(t_stack *pstack, t_data *pdata)
{
	return (clist_first(pstack, pdata));
}

int	stack_next(t_stack *pstack, t_data *pdata)
{
	return (clist_next(pstack, pdata));
}
