#ifndef PUSH_SWAP_STACK_H
# define PUSH_SWAP_STACK_H

# include "./libft/include/libft.h"
# include "circular_linked_list.h"
# include "push_swap_stack.h"
# include "push_swap_operations.h"

typedef t_list	t_stack; /* 임시. 다른 헤더에 이미 선언되어 있음 */

typedef struct	s_pushswap
{
	t_stack	*stack_a;
	t_stack *stack_b;
	int		*ordered_array;
}	t_pushswap;

t_list	*get_valid_list(char **argv);
int		*get_ordered_array(t_list *plist);
void	free_twoarr(char **arr); /* 임시 */

#endif