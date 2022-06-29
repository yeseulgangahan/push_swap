#ifndef PUSH_SWAP_STACK_H
# define PUSH_SWAP_STACK_H

# include "./libft/include/circular_linked_list.h"

typedef t_clist	t_stack;

void	stack_init(t_stack *pstack);
int		stack_count(t_stack *pstack);
bool	stack_peek(t_stack *pstack, t_data *pdata);
bool	stack_is_descending_order(t_stack *pstack, size_t len);
bool	stack_is_ascending_order(t_stack *pstack, size_t len);
void	stack_push(t_stack *pstack1, t_stack *pstack2);
void	stack_swap(t_stack *pstack);
void	stack_rotate(t_stack *pstack, int n);

#endif
