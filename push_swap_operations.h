/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:04:38 by yehan             #+#    #+#             */
/*   Updated: 2022/06/30 13:35:54 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_OPERATIONS_H
# define PUSH_SWAP_OPERATIONS_H

# include "push_swap_stack.h"

void	sa(t_stack *pstack);
void	sb(t_stack *pstack);
void	pa(t_stack *pstack1, t_stack *pstack2);
void	pb(t_stack *pstack1, t_stack *pstack2);
void	ra(t_stack *pstack);
void	rb(t_stack *pstack);
void	rr(t_stack *pstack1, t_stack *pstack2);
void	rra(t_stack *pstack);
void	rrb(t_stack *pstack);
void	rrr(t_stack *pstack1, t_stack *pstack2);

#endif
