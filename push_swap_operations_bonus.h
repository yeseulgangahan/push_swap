/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_bonus.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:04:38 by yehan             #+#    #+#             */
/*   Updated: 2022/07/01 08:13:38 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_OPERATIONS_BONUS_H
# define PUSH_SWAP_OPERATIONS_BONUS_H

# include "./libft/include/push_swap_stack.h"

void	sa_silent(t_stack *pstack);
void	sb_silent(t_stack *pstack);
void	ss_silent(t_stack *pstack1, t_stack *pstack2);
void	pa_silent(t_stack *pstack1, t_stack *pstack2);
void	pb_silent(t_stack *pstack1, t_stack *pstack2);
void	ra_silent(t_stack *pstack);
void	rb_silent(t_stack *pstack);
void	rr_silent(t_stack *pstack1, t_stack *pstack2);
void	rra_silent(t_stack *pstack);
void	rrb_silent(t_stack *pstack);
void	rrr_silent(t_stack *pstack1, t_stack *pstack2);

#endif
