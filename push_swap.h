/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:09:32 by yehan             #+#    #+#             */
/*   Updated: 2022/07/01 08:03:25 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/include/libft.h"
# include "./libft/include/circular_linked_list.h"
# include "./libft/include/push_swap_stack.h"
# include "push_swap_operations.h"

# define TRUE 1
# define FALSE 0

typedef struct s_pushswap
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_data	*ordered_arr;
	int		is_initial;
}	t_pushswap;

void	get_valid_stack_a(t_stack *pstack, char **args);
t_data	*get_ordered_arr(t_clist *plist);

void	partition_recur_stack_a(t_pushswap *pushswap,
			size_t left, size_t right);
void	partition_recur_stack_b(t_pushswap *pushswap,
			size_t left, size_t right);

void	sort_last_3_data(t_pushswap *pushswap);
void	sort_123(t_pushswap *pushswap);
void	sort_132(t_pushswap *pushswap);
void	sort_213(t_pushswap *pushswap);
void	sort_231(t_pushswap *pushswap);
void	sort_312(t_pushswap *pushswap);

void	sort_small_problem(t_pushswap *pushswap, size_t len);

#endif
