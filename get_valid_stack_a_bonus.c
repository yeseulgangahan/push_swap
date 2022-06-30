/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_valid_stack_a_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:42:19 by yehan             #+#    #+#             */
/*   Updated: 2022/06/30 19:21:52 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_atoi_strict(const char *str)
{
	int					neg;
	int					num;
	unsigned long long	temp_num;

	if (*str == '\0')
		ft_pstr_exit("Error");
	neg = 1;
	if (*str == '-')
		neg = -1;
	if (*str == '+' || *str == '-')
		str++;
	num = 0;
	while ('0' <= *str && *str <= '9')
	{
		temp_num = num * 10 + (*str - '0');
		if (neg == -1 && temp_num > -(unsigned long long)INT_MIN)
			ft_pstr_exit("Error");
		if (neg == 1 && temp_num > (unsigned long long)INT_MAX)
			ft_pstr_exit("Error");
		num = temp_num;
		str++;
	}
	if (*str != '\0')
		ft_pstr_exit("Error");
	return (neg * num);
}

static int	is_unique_number(t_clist *plist, int num)
{
	int		i;
	int		list_len;
	t_data	data;

	if (clist_first(plist, &data))
	{
		if (data == num)
			return (FALSE);
		i = 1;
		list_len = clist_count(plist);
		while (i < list_len)
		{
			clist_next(plist, &data);
			if (data == num)
				return (FALSE);
			i++;
		}
	}
	return (TRUE);
}

static int	get_valid_number(t_clist *list, char *str)
{
	int	num;

	num = ft_atoi_strict(str);
	if (is_unique_number(list, num) == FALSE)
		ft_pstr_exit("Error");
	return (num);
}

void	get_valid_stack_a_bonus(t_stack *pstack, char **args)
{
	int		i;
	int		j;
	char	**temp;

	i = 1;
	while (args[i])
	{
		if (ft_strchr(args[i], ' ') == NULL)
			clist_insert_back(pstack, get_valid_number(pstack, args[i]));
		else
		{
			temp = ft_split(args[i], ' ');
			j = 0;
			while (temp[j])
			{
				clist_insert_back(pstack, get_valid_number(pstack, temp[j]));
				j++;
			}
			ft_free_twoarr(temp);
		}
		i++;
	}
}
