# include "push_swap.h"

static void	get_array(t_list *plist, int *arr)
{
	int		i;
	t_data	*pdata;

	i = 0;
	if (list_first(plist, pdata))
	{
		arr[i] = pdata;
		i++;
		while (list_next(plist, pdata))
		{
			list_next(plist, pdata);
			arr[i] = pdata;
			i++;
		}
	}
	arr[i] = 0;
}

static void	sort_array(int *arr)
{
	//
}

int	*get_ordered_array(t_list *plist)
{
	int	*arr;

	arr = malloc((sizeof(int) * list_count(plist)) + 1);
	get_array(plist, arr);
	sort_array(arr);
	return (arr);
}