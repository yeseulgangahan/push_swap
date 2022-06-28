#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/include/libft.h"
# include "./libft/include/circular_linked_list.h"
# include "push_swap_stack.h"
# include "push_swap_operations.h"

# define A	0
# define B	1

typedef struct	s_pushswap
{
	t_stack	*stack_a;
	t_stack *stack_b;
	t_data	*ordered_arr;
}	t_pushswap;

t_clist	*get_valid_list(char **args);
int		*get_ordered_arr(t_clist *plist);

void	partition_recursive_stack_a(t_pushswap *pushswap, size_t left, size_t right);
void	partition_recursive_stack_b(t_pushswap *pushswap, size_t left, size_t right);

void	sort_last_two(t_stack *pstack, int stack);

#endif
