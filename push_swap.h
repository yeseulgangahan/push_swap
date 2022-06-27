#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/include/libft.h"
# include "./libft/include/circular_linked_list.h"
# include "push_swap_stack.h"
# include "push_swap_operations.h"

typedef struct	s_pushswap
{
	t_stack	*stack_a;
	t_stack *stack_b;
	int		*ordered_array;
}	t_pushswap;

t_clist	*get_valid_list(char **args);
int		*get_ordered_array(t_clist *plist);

#endif
