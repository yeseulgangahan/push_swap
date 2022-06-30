# include "push_swap.h"

/* partition_recursive_stack_b */

static void	sort_123(t_pushswap *pushswap)
{
	sb(pushswap->stack_b);
	pa(pushswap->stack_b, pushswap->stack_a);
	sb(pushswap->stack_b);
	pa(pushswap->stack_b, pushswap->stack_a);
	sa(pushswap->stack_a);
	pa(pushswap->stack_b, pushswap->stack_a);
}
static void	sort_132(t_pushswap *pushswap)
{
	sb(pushswap->stack_b);
	pa(pushswap->stack_b, pushswap->stack_a);
	sb(pushswap->stack_b);
	pa(pushswap->stack_b, pushswap->stack_a);
	pa(pushswap->stack_b, pushswap->stack_a);
}

static void	sort_213(t_pushswap *pushswap)
{
	pa(pushswap->stack_b, pushswap->stack_a);
	sb(pushswap->stack_b);
	pa(pushswap->stack_b, pushswap->stack_a);
	sa(pushswap->stack_a);
	pa(pushswap->stack_b, pushswap->stack_a);
}

static void	sort_231(t_pushswap *pushswap)
{
	pa(pushswap->stack_b, pushswap->stack_a);
	pa(pushswap->stack_b, pushswap->stack_a);
	sa(pushswap->stack_a);
	pa(pushswap->stack_b, pushswap->stack_a);
}

static void	sort_312(t_pushswap *pushswap)
{
	pa(pushswap->stack_b, pushswap->stack_a);
	sb(pushswap->stack_b);
	pa(pushswap->stack_b, pushswap->stack_a);
	pa(pushswap->stack_b, pushswap->stack_a);
}

void	sort_last_3_args(t_pushswap *pushswap)
{
	// ft_putstr_fd("sort_last_3 enter\n", 1);
	// test_print_stack_a(pushswap->stack_a); //
	// test_print_stack_a(pushswap->stack_b); //


	t_data	d1;
	t_data	d2;
	t_data	d3;

	d1 = pushswap->stack_b->tail->next->data;
	d2 = pushswap->stack_b->tail->next->next->data;
	d3 = pushswap->stack_b->tail->next->next->next->data;
	if (d1 < d2 && d2 < d3 && d1 < d3)
		sort_123(pushswap);
	else if (d1 < d2 && d2 > d3 && d1 < d3)
		sort_132(pushswap);
	else if (d1 > d2 && d2 < d3 && d1 < d3)
		sort_213(pushswap);
	else if (d1 < d2 && d2 > d3 && d1 > d3)
		sort_231(pushswap);
	else if (d1 > d2 && d2 < d3 && d1 > d3)
		sort_312(pushswap);
	// test_print_stack_a(pushswap->stack_a); //
	// test_print_stack_a(pushswap->stack_b); //
	// ft_putstr_fd("sort_last_3 out\n", 1);
	
}

static void	base_case_solve(t_pushswap *pushswap, size_t len)
{
	if (len == 2)
	{
		sb(pushswap->stack_b);
		pa(pushswap->stack_b, pushswap->stack_a);
		pa(pushswap->stack_b, pushswap->stack_a);
	}
	else if (len == 3)
		sort_last_3_args(pushswap);
}

static bool	is_rb_data_only(t_pushswap *pushswap, size_t pivot1, size_t range)
{
	t_data	data;

	while (range)
	{
		stack_next(pushswap->stack_a, &data);
		if (pushswap->ordered_arr[pivot1] <= data)
			break;
		range--;
	}
	if (range == 0)
		return (true);
	else
		return (false);
}

static size_t	partition(t_pushswap *pushswap, size_t pivot1, size_t pivot2, size_t len)
{
	t_data	data;
	size_t	rb_cnt;

	rb_cnt = 0;
	while (len)
	{
		stack_peek(pushswap->stack_b, &data);
		if (pushswap->ordered_arr[pivot2] <= data)
			pa(pushswap->stack_b, pushswap->stack_a);
		else if (pushswap->ordered_arr[pivot1] <= data)
		{
			pa(pushswap->stack_b, pushswap->stack_a);
			ra(pushswap->stack_a);
		}
		else
		{
			if (is_rb_data_only(pushswap, pivot1, len - 1) == true)
				break ;
			rb(pushswap->stack_b);
			rb_cnt++;
		}
		len--;
	}
	return (rb_cnt);
}

static void	move_range_to_top(t_pushswap *pushswap, size_t range_stack_a, size_t range_stack_b)
{
	while (range_stack_a != 0 && range_stack_b != 0)
	{
		rrr(pushswap->stack_a, pushswap->stack_b);
		range_stack_a--;
		range_stack_b--;
	}
	while (range_stack_a != 0)
	{
		rra(pushswap->stack_a);
		range_stack_a--;
	}
	while (range_stack_b != 0)
	{
		rrb(pushswap->stack_b);
		range_stack_b--;
	}
}

void	partition_recursive_stack_b(t_pushswap *pushswap, size_t left, size_t right)
{
	size_t	pivot1;
	size_t	pivot2;
	size_t	len;
	size_t	rb_cnt;

	// ft_putstr_fd("stack_b enter\n", 1); //
	len = right - left + 1;
	if (stack_is_descending_order(pushswap->stack_b, len) == true)
	{
		while (len)
		{
			pa(pushswap->stack_b, pushswap->stack_a);
			len--;
		}
	}
	else if (len == 2 || len == 3)
		base_case_solve(pushswap, len);
	else
	{
		pivot1 = left + (len / 3);
		pivot2 = left + (len / 3 * 2);
		rb_cnt = partition(pushswap, pivot1, pivot2, len);
		partition_recursive_stack_a(pushswap, pivot2, right);
		move_range_to_top(pushswap, pivot2 - pivot1, rb_cnt);
		partition_recursive_stack_a(pushswap, pivot1, pivot2 - 1);
		partition_recursive_stack_b(pushswap, left, pivot1 - 1);
	}
}
