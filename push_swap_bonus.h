/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:09:32 by yehan             #+#    #+#             */
/*   Updated: 2022/06/30 19:35:41 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "./libft/include/libft.h"
# include "./libft/include/circular_linked_list.h"
# include "./libft/include/push_swap_stack.h"
# include "push_swap_operations_bonus.h"

# define TRUE 1
# define FALSE 0

typedef struct s_pushswap
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_pushswap;

void	get_valid_stack_a_bonus(t_stack *pstack, char **args);

#endif
