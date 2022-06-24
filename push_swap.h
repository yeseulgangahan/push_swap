#ifndef PUSH_SWAP_STACK_H
# define PUSH_SWAP_STACK_H

# include "../libft/include/libft.h"
# include "circular_linked_list.h"
# include "push_swap_stack.h"
# include "push_swap_operations.h"

t_list	*get_valid_list(char **argv);
int		*get_ordered_array(t_list *plist);

#endif