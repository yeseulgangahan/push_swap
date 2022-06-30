# include <stdio.h>
# include "push_swap.h"

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

void	test_print_stack_a(t_stack *pstack)
{
	size_t	stack_len;
	size_t	i;
	t_node *cur;

	cur = pstack->tail->next;
	stack_len = stack_count(pstack);

	i = 0;
	while (i < stack_len)
	{
		printf("%d ", cur->data);
		cur = cur->next;
		i++;
	}
	printf("\n");
}