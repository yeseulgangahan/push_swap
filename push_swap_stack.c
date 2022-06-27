# include <stdlib.h>
# include "push_swap_stack.h"

void	stack_init(t_stack *pstack)
{
	pstack = malloc(sizeof(t_stack));
	clist_init(pstack);
}

int	stack_count(t_stack *pstack)
{
	return (clist_count(pstack));
}

void	stack_push(t_stack *pstack1, t_stack *pstack2)
{
	t_data	*pdata;

	pdata = NULL;
	if (stack_count(pstack1) == 0)
		return ;
	clist_first(pstack1, pdata);
	clist_remove(pstack1);
	clist_insert_front(pstack2, *pdata);
}

void	stack_swap(t_stack *pstack)
{
	t_data	*pdata;

	pdata = NULL;
	if (stack_count(pstack) < 2)
		return ;
	clist_first(pstack, pdata);
	clist_next(pstack, pdata);
	pstack->cur->data = pstack->before->data;
	pstack->before->data = *pdata;
}

void	stack_rotate(t_stack *pstack, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pstack->tail = pstack->tail->next;
		i++;
	}
}
