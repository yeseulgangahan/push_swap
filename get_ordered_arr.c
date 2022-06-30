/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ordered_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 08:19:36 by yehan             #+#    #+#             */
/*   Updated: 2022/06/30 10:43:10 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_arr(t_clist *plist, t_data *arr, size_t len)
{
	size_t	i;
	t_data	data;

	i = 0;
	clist_first(plist, &data);
	arr[i] = data;
	i++;
	while (i < len)
	{
		clist_next(plist, &data);
		arr[i] = data;
		i++;
	}
}

static void	selection_sort(t_data *arr, size_t len)
{
	size_t	i;
	size_t	j;
	t_data	min_index;
	t_data	temp;

	if (len == 1)
		return ;
	i = 0;
	while (i < len - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < len)
		{
			if (arr[min_index] > arr[j])
				min_index = j ;
			j++;
		}
		temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
		i++;
	}
}

t_data	*get_ordered_arr(t_clist *plist)
{
	size_t	len;
	t_data	*arr;

	len = clist_count(plist);
	arr = ft_calloc(len + 1, sizeof(t_data));
	get_arr(plist, arr, len);
	selection_sort(arr, len);
	return (arr);
}
