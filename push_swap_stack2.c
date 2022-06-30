/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:06:04 by yehan             #+#    #+#             */
/*   Updated: 2022/06/30 13:32:40 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap_stack.h"
#include "./libft/include/libft.h"

int	stack_is_ascending_order(t_stack *pstack, size_t len)
{
	t_data	data;
	size_t	i;

	if (1 < len)
	{
		clist_first(pstack, &data);
		i = 1;
		while (i < len)
		{
			clist_next(pstack, &data);
			if (pstack->before->data > data)
				return (FALSE);
			i++;
		}
	}
	return (TRUE);
}

int	stack_is_descending_order(t_stack *pstack, size_t len)
{
	t_data	data;
	size_t	i;

	if (1 < len)
	{
		clist_first(pstack, &data);
		i = 1;
		while (i < len)
		{
			clist_next(pstack, &data);
			if (pstack->before->data < data)
				return (FALSE);
			i++;
		}
	}
	return (TRUE);
}

void	stack_push(t_stack *pstack1, t_stack *pstack2)
{
	t_data	data;

	clist_first(pstack1, &data);
	clist_remove(pstack1);
	clist_insert_front(pstack2, data);
}

void	stack_swap(t_stack *pstack)
{
	t_data	data;

	clist_first(pstack, &data);
	clist_next(pstack, &data);
	pstack->cur->data = pstack->before->data;
	pstack->before->data = data;
}

void	stack_rotate(t_stack *pstack, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pstack->tail = pstack->tail->next;
		i++;
	}
}
