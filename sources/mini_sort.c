/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:58:10 by hlaunch           #+#    #+#             */
/*   Updated: 2021/12/20 16:58:13 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_tack *stck)
{
	int	min;

	min = find_min(stck->a, stck->len_a);
	if (min == stck->a[2])
	{
		if (stck->a[0] > stck->a[1])
			swap_ab(stck->a, stck->len_a, 'a');
		rr_ab(stck->a, stck->len_a, 'a');
	}
	else if (min == stck->a[1])
	{
		if (stck->a[0] > stck->a[2])
			r_ab(stck->a, stck->len_a, 'a');
		else
			swap_ab(stck->a, stck->len_a, 'a');
	}
	else if (min == stck->a[0])
	{
		swap_ab(stck->a, stck->len_a, 'a');
		r_ab(stck->a, stck->len_a, 'a');
	}
}

void	tostack_b(t_tack *stck)
{
	int	i;
	int	min;
	int	min_i;

	i = 0;
	min = find_min(stck->a, stck->len_a);
	while (i < stck->len_a)
	{
		if (stck->a[i] == min)
			min_i = i;
		i++;
	}
	while (stck->a[0] != min)
	{
		if (min_i == 1)
			swap_ab(stck->a, stck->len_a, 'a');
		else if (min_i <= ((stck->len_a - 1) / 2))
			r_ab(stck->a, stck->len_a, 'a');
		else
			rr_ab(stck->a, stck->len_a, 'a');
	}
	write(1, "pb\n", 3);
	push_b(stck);
}

void	mini_sort(t_tack *stck)
{
	if (is_sorted(stck->a, stck->len_a) == 1)
		return ;
	if (stck->len_a == 2)
	{
		swap_ab(stck->a, stck->len_a, 'a');
		return ;
	}
	while (is_sorted(stck->a, stck->len_a) == 0 && stck->len_a > 3)
		tostack_b(stck);
	while (is_sorted(stck->a, stck->len_a) == 0)
		sort_three(stck);
	while (stck->len_b != 0)
	{
		write(1, "pa\n", 3);
		push_a(stck);
	}
}
