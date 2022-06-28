# include "push_swap.h"

static void	pushswap_init(t_pushswap *pushswap, char **args)
{
	pushswap->stack_a = ft_calloc(1, sizeof(t_clist));
	clist_init(pushswap->stack_a);
	get_valid_stack_a(pushswap->stack_a, args);
	pushswap->stack_b = ft_calloc(1, sizeof(t_clist));
	clist_init(pushswap->stack_b);
	pushswap->ordered_arr = get_ordered_arr((t_clist *)pushswap->stack_a);
}

int	main(int argc, char **argv)
{
	t_pushswap	pushswap;
	size_t		len;

	if (argc == 1)
		ft_pstr_exit("Error\n: no args..");
	pushswap_init(&pushswap, argv);
	// test_print_arr(pushswap.ordered_arr); //
	len = stack_count(pushswap.stack_a);
	if (len <= 5)
	{
		sort_small_args(&pushswap, len);
		// test_print_stack_a(pushswap.stack_a); //
		return (0);
	}
	partition_recursive_stack_a(&pushswap, 0, stack_count(pushswap.stack_a) - 1);
	// printf("\n"); //
	// test_print_stack_a(pushswap.stack_a); //
	return (0);
}
