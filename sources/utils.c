/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:58:52 by hlaunch           #+#    #+#             */
/*   Updated: 2021/12/20 16:58:53 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min(int *stck, int len)
{
	int	i;
	int	min;

	i = 0;
	min = stck[i];
	while (i < len)
	{
		if (stck[i] < min)
			min = stck[i];
		i++;
	}
	return (min);
}

int	find_max(int *stck, int len)
{
	int	i;
	int	max;

	i = 0;
	max = stck[i];
	while (i < len)
	{
		if (stck[i] > max)
			max = stck[i];
		i++;
	}
	return (max);
}

int	is_sorted(int *stck, int len)
{
	int	i;

	i = 0;
	if (len < 2)
		return (1);
	while (i < len - 1)
	{
		if (stck[i] > stck[i + 1])
			return (0);
		i++;
	}
	return (1);
}
