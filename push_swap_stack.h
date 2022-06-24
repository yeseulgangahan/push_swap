#ifndef PUSH_SWAP_STACK_H
# define PUSH_SWAP_STACK_H

# include "circular_linked_list.h"

typedef struct s_liststack
{
	t_list	*plist;
}	t_liststack;

typedef t_liststack	stack;

/* 우리 스택을 다룰 때의 규칙들. 최대한 규칙을 반영하여 구현한다. */

void	stack_init(stack *pstack);
int		stack_count(stack *pstack);
void	stack_push(stack *pstack1, stack *pstack2);
void	stack_swap(stack *pstack);
void	stack_rotate(stack *pstack, int n);

#endif