# include "push_swap.h"

static void	get_arr(t_clist *plist, int *arr)
{
	int		i;
	t_data	data;
	int		list_len;

	i = 0;
	if (clist_first(plist, &data) == true)
	{
		arr[i] = data;
		i++;
		list_len = clist_count(plist);
		while (i < list_len)
		{
			clist_next(plist, &data);
			arr[i] = data;
			i++;
		}
	}
	arr[i] = 0;
}

static void	sort_arr(int *arr)
{
	int i = 0;
	while (i < 10)
	{
		arr[i] = i;
		i++;
	}
}

int	*get_ordered_arr(t_clist *plist)
{
	int	*arr;

	arr = malloc((sizeof(int) * clist_count(plist)) + 1);
	get_arr(plist, arr);
	sort_arr(arr);
	return (arr);
}
