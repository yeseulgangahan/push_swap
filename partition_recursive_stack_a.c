# include "push_swap.h"

static void	base_case_solve(t_pushswap *pushswap, size_t len)
{
	if (len == 2 && stack_is_ascending_order(pushswap->stack_a, len) == false)
		sa(pushswap->stack_a);
}

static void	chuck_move_to_top(t_pushswap *pushswap, size_t pivot1, size_t pivot2, size_t right)
{
	size_t	chuck_len_stack_a;
	size_t	chuck_len_stack_b;

	chuck_len_stack_a = right - pivot2 + 1;
	chuck_len_stack_b = pivot2 - pivot1;
	while (chuck_len_stack_b != 0)
	{
		rrr(pushswap->stack_a, pushswap->stack_b);
		chuck_len_stack_a--;
		chuck_len_stack_b--;
	}
	while (chuck_len_stack_a != 0)
	{
		rra(pushswap->stack_a);
		chuck_len_stack_a--;
	}
}

static void	partition(t_pushswap *pushswap, size_t pivot1, size_t pivot2, size_t len)
{
	while (len--)
	{
		if (pushswap->ordered_arr[pivot2] <= stack_peek(pushswap->stack_a))
			ra(pushswap->stack_a);
		else if (pushswap->ordered_arr[pivot1] <= stack_peek(pushswap->stack_a))
		{
			pb(pushswap->stack_a, pushswap->stack_b);
			rb(pushswap->stack_b);
		}
		else
			pb(pushswap->stack_a, pushswap->stack_b);
	}
}

void	partition_recursive_stack_a(t_pushswap *pushswap, size_t left, size_t right)
{
	size_t	pivot1;
	size_t	pivot2;
	size_t	len;

	len = right - left + 1;
	if (len <= 2)
		base_case_solve(pushswap, len);
	else
	{
		pivot1 = left + (len / 3);
		pivot2 = left + (len / 3 * 2);

		partition(pushswap, pivot1, pivot2, len);
		chuck_move_to_top(pushswap, pivot1, pivot2, right);

		partition_recursive_stack_a(pushswap, pivot2, right);
		partition_recursive_stack_b(pushswap, pivot1, pivot2 - 1);
		partition_recursive_stack_b(pushswap, left, pivot1 - 1);
	}
}
