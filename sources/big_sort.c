/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:57:38 by hlaunch           #+#    #+#             */
/*   Updated: 2021/12/20 16:57:42 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_arr(t_tack *stck, int *arr)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	while (i < stck->len_a)
	{
		j = i++;
		while (j > 0 && arr[j] < arr[j - 1])
		{
			tmp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = tmp;
			j -= 1;
		}
	}
}

int	*sorted_arr(t_tack *stck)
{
	int	*arr;
	int	i;

	i = 0;
	arr = (int *) malloc (sizeof(int) * stck->len_a);
	if (!arr)
		return (NULL);
	while (i < stck->len_a)
	{
		arr[i] = stck->a[i];
		i++;
	}
	sort_arr(stck, arr);
	return (arr);
}

void	sort_radix(t_tack *stck, int i)
{
	if (is_sorted(stck->a, stck->len_a) == 1)
	{
		while (stck->len_b > 0)
		{
			write(1, "pa\n", 3);
			push_a(stck);
		}
		return ;
	}
	if (((stck->a[0] >> i) & 1) == 1)
		r_ab(stck->a, stck->len_a, 'a');
	else
	{
		write(1, "pb\n", 3);
		push_b(stck);
	}
}

void	byte_operations(t_tack *stck)
{
	int	max;
	int	max_bits;
	int	i;
	int	j;

	max = find_max(stck->a, stck->len_a) + 1;
	max_bits = 0;
	i = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < max)
		{
			sort_radix(stck, i);
			j++;
		}
		while (stck->len_b > 0)
		{
			write(1, "pa\n", 3);
			push_a(stck);
		}
		i++;
	}
}

void	big_sort(t_tack *stck)
{
	int	*arr;
	int	i;
	int	j;

	arr = sorted_arr(stck);
	i = 0;
	j = 0;
	while (i < stck->len_a)
	{
		while (j < stck->len_a)
		{
			if (stck->a[i] == arr[j])
			{
				stck->a[i] = j;
				break ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	free(arr);
	byte_operations(stck);
}
