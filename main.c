# include "push_swap.h"

void	pushswap_init(t_pushswap *pushswap, char **argv)
{
	pushswap->stack_a =  (t_stack *)get_valid_list(argv);
	pushswap->stack_b = NULL;
	pushswap->ordered_array = get_ordered_array((t_clist *)pushswap->stack_a);
}

int	main(int argc, char **argv)
{
	t_pushswap	pushswap;

	if (argc < 2)
	{
		printf("invalid args");
		return (1);
	}
	pushswap_init(&pushswap, argv);
	return (0);
}
