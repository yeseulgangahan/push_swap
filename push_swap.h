/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:09:32 by yehan             #+#    #+#             */
/*   Updated: 2022/07/03 08:14:39 by yehan            ###   ########seoul.kr  */
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

void	base_case_solve_stack_a(t_pushswap *pushswap, size_t len);
void	sort_321_stack_a(t_pushswap *pushswap);
void	sort_132_stack_a(t_pushswap *pushswap);
void	sort_213_stack_a(t_pushswap *pushswap);
void	sort_231_stack_a(t_pushswap *pushswap);
void	sort_312_stack_a(t_pushswap *pushswap);

void	base_case_solve_stack_b(t_pushswap *pushswap, size_t len);
void	sort_123_stack_b(t_pushswap *pushswap);
void	sort_132_stack_b(t_pushswap *pushswap);
void	sort_213_stack_b(t_pushswap *pushswap);
void	sort_231_stack_b(t_pushswap *pushswap);
void	sort_312_stack_b(t_pushswap *pushswap);

void	sort_small_problem(t_pushswap *pushswap, size_t len);

#endif
