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

t_data	stack_peek(t_stack *pstack)
{
	return (pstack->tail->next->data);
}

bool	stack_is_ascending_order(t_stack *pstack, size_t len)
{
	t_data	*pdata;
	size_t	i;

	if (len > 1)
	{
		clist_first(pstack, pdata);
		i = 0;
		while (i < len)
		{
			clist_next(pstack, pdata);
			if (pstack->before->data > pdata)
				return (false);
			i++;
		}
	}
	return (true);
}

bool	stack_is_descending_order(t_stack *pstack, size_t len)
{
	t_data	*pdata;
	size_t	i;

	if (len > 1)
	{
		clist_first(pstack, pdata);
		i = 0;
		while (i < len)
		{
			clist_next(pstack, pdata);
			if (pstack->before->data < pdata)
				return (false);
			i++;
		}
	}
	return (true);
}

void	stack_push(t_stack *pstack1, t_stack *pstack2)
{
	t_data	*pdata;

	pdata = NULL;
	if (clist_count(pstack1) == 0)
		return ;
	clist_first(pstack1, pdata);
	clist_remove(pstack1);
	clist_insert_front(pstack2, *pdata);
}

void	stack_swap(t_stack *pstack)
{
	t_data	*pdata;

	pdata = NULL;
	if (clist_count(pstack) < 2)
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
