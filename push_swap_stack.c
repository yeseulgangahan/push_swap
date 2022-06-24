# include "push_swap_stack.h"

void	stack_init(stack *pstack)
{
	pstack->plist = malloc(sizeof(list));
	list_init(pstack->plist);
}

int	stack_count(stack *pstack)
{
	return (list_count(pstack->plist));
}

voidstack_push(stack *pstack1, stack *pstack2)
{
	t_data	*pdata;

	if (stack_count(pstack1) == 0)
		return ;
	list_first(pstack1->plist, pdata);
	list_remove(pstack1->plist->cur);
	list_insert_front(pstack2->plist, *pdata);
}

void	stack_swap(stack *pstack)
{
	t_data	*pdata;

	if (stack_count(pstack) < 2)
		return ;
	list_first(pstack->plist, pdata);
	list_next(pstack->plist, pdata);
	pstack->plist->cur->data = pstack->plist->before->data;
	pstack->plist->before->data = pdata;
}

void	stack_rotate(stack *pstack, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pstack->plist->tail = pstack->plist->tail->next;
		i++;
	}
}