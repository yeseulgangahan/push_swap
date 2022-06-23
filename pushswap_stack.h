#ifndef PUSHSWAP_STACK_H
# define PUSHSWAP_STACK_H

# include "circular_linked_list.h"

typedef struct s_liststack
{
	list	*plist;
}	t_liststack;

typedef t_liststack	stack;

void	stack_init(stack *pstack);
bool	stack_isempty(stack *pstack);
void	stack_push();