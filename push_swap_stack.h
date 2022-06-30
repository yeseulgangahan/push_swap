/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:12:31 by yehan             #+#    #+#             */
/*   Updated: 2022/06/30 13:40:49 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_STACK_H
# define PUSH_SWAP_STACK_H

# include <stddef.h>
# include "./libft/include/circular_linked_list.h"

# define TRUE 1
# define FALSE 0

typedef t_clist	t_stack;

void	stack_init(t_stack *pstack);
int		stack_count(t_stack *pstack);
int		stack_peek(t_stack *pstack, t_data *pdata);
int		stack_next(t_stack *pstack, t_data *pdata);
int		stack_is_descending_order(t_stack *pstack, size_t len);
int		stack_is_ascending_order(t_stack *pstack, size_t len);
void	stack_push(t_stack *pstack1, t_stack *pstack2);
void	stack_swap(t_stack *pstack);
void	stack_rotate(t_stack *pstack, int n);

#endif
