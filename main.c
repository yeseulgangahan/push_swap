# include "push_swap.h"

static void	pushswap_init(t_pushswap *pushswap, char **argv)
{
	pushswap->stack_a =  (t_stack *)get_valid_list(argv);
	pushswap->stack_b = NULL;
	pushswap->ordered_arr = get_ordered_arr((t_clist *)pushswap->stack_a);
}

# include <stdio.h>
void	test_print_arr(t_data *arr)
{
	int i;
	i = 0;
	while (arr[i])
	{
		printf("%d ", arr[i]);
		i++;
	}
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
	test_print_arr(pushswap.ordered_arr);
	return (0);
}
