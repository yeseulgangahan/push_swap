# include "push_swap.h"

static void	sort_3_args(t_stack *pstack)
{
	t_data	d1;
	t_data	d2;
	t_data	d3;

	d1 = pstack->tail->next->data;
	d2 = pstack->tail->next->next->data;
	d3 = pstack->tail->data;
	if (d1 < d2 && d2 > d3 && d3 > d1)
	{
		sa(pstack);
		ra(pstack);
	}
	else if (d1 > d2 && d2 < d3 && d3 > d1)
		sa(pstack);
	else if (d1 < d2 && d2 > d3 && d3 < d1)
		rra(pstack);
	else if (d1 > d2 && d2 < d3 && d3 < d1)
		ra(pstack);
	else
	{
		ra(pstack);
		sa(pstack);
	}
}

static void	move_min_data_to_top(t_stack *pstack, size_t len, size_t index)
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
				move_min_data_to_top(pushswap->stack_a, len, i);
				break ;
			}
			i++;
		}
	}
	pb(pushswap->stack_a, pushswap->stack_b);
}

void	sort_less_args(t_pushswap *pushswap, size_t len)
{
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