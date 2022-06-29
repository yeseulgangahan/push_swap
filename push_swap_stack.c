# include <stdlib.h>
# include "push_swap_stack.h"
# include "./libft/include/libft.h"

void	stack_init(t_stack *pstack)
{
	pstack = ft_calloc(1, sizeof(t_stack));
	clist_init(pstack);
}

int	stack_count(t_stack *pstack)
{
	return (clist_count(pstack));
}

bool	stack_peek(t_stack *pstack, t_data *pdata)
{
	return (clist_first(pstack, pdata));
}

bool	stack_is_ascending_order(t_stack *pstack, size_t len)
{
	t_data	data;
	size_t	i;

	if (1 < len)
	{
		clist_first(pstack, &data);
		i = 1;
		while (i < len)
		{
			clist_next(pstack, &data);
			if (pstack->before->data > data)
				return (false);
			i++;
		}
	}
	return (true);
}

bool	stack_is_descending_order(t_stack *pstack, size_t len)
{
	t_data	data;
	size_t	i;

	if (1 < len)
	{
		clist_first(pstack, &data);
		i = 1;
		while (i < len)
		{
			clist_next(pstack, &data);
			if (pstack->before->data < data)
				return (false);
			i++;
		}
	}
	return (true);
}

void	stack_push(t_stack *pstack1, t_stack *pstack2)
{
	t_data	data;

	clist_first(pstack1, &data);
	clist_remove(pstack1);
	clist_insert_front(pstack2, data);
}

void	stack_swap(t_stack *pstack)
{
	t_data	data;

	clist_first(pstack, &data);
	clist_next(pstack, &data);
	pstack->cur->data = pstack->before->data;
	pstack->before->data = data;
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
