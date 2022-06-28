# include "push_swap.h"

static void	sort_3_args(t_stack *pstack)
{
	t_data	a1;
	t_data	a2;
	t_data	a3;

	a1 = pstack->tail->next->data;
	a2 = pstack->tail->next->next->data;
	a3 = pstack->tail->data;
	if (a1 < a2 && a2 > a3 && a3 > a1)
	{
		ra(pstack);
		sa(pstack);
		rra(pstack);
	}
	else if (a1 > a2 && a2 < a3 && a3 > a1)
		sa(pstack);
	else if (a1 < a2 && a2 > a3 && a3 < a1)
		rra(pstack);
	else if (a1 > a2 && a2 < a3 && a3 < a1)
		ra(pstack);
	else
	{
		ra(pstack);
		sa(pstack);
	}
}

static void	min_data_to_top(t_stack *pstack, size_t len, size_t index)
{
	size_t	i;

	i = 0;
	if (index <= len / 2)
	{
		while (i < index)
		{
			ra(pstack);
			i++;
		}
	}
	else if (index > len / 2)
	{
		while (i < len - index)
		{
			rra(pstack);
			i++;
		}
	}
}

static void	min_data_pop(t_pushswap *pushswap, size_t len, size_t index)
{
	t_data	target_data;
	t_data	data;
	size_t	i;

	target_data = pushswap->ordered_arr[index];
	clist_first(pushswap->stack_a, &data);
	if (target_data != data)
	{
		i = 1;
		while (i < len)
		{
			clist_next(pushswap->stack_a, &data);
			if (target_data == data)
			{
				min_data_to_top(pushswap->stack_a, len, i);
				break ;
			}
			i++;
		}
	}
	pb(pushswap->stack_a, pushswap->stack_b);
}

void	sort_less_args(t_pushswap *pushswap, size_t len)
{
	if (stack_is_ascending_order(pushswap->stack_a, len) == true)
		return ;
	if (len == 2)
		sa(pushswap->stack_a);
	else if (len == 3)
		sort_3_args(pushswap->stack_a);
	else if (len == 4)
	{
		min_data_pop(pushswap, len, 0);
		if (stack_is_ascending_order(pushswap->stack_a, 3) == false)
			sort_3_args(pushswap->stack_a);
		pa(pushswap->stack_b, pushswap->stack_a);
	}
	else if (len == 5)
	{
		min_data_pop(pushswap, len, 0);
		min_data_pop(pushswap, len - 1, 1);
		if (stack_is_ascending_order(pushswap->stack_a, 3) == false)
			sort_3_args(pushswap->stack_a);
		pa(pushswap->stack_b, pushswap->stack_a);
		pa(pushswap->stack_b, pushswap->stack_a);
	}
}