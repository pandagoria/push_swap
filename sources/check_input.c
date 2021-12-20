/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:58:00 by hlaunch           #+#    #+#             */
/*   Updated: 2021/12/20 16:58:01 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:57:48 by hlaunch           #+#    #+#             */
/*   Updated: 2021/12/20 16:57:50 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_duplicate(int *stack, int index)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < index)
	{
		while (j < index)
		{
			if (stack[i] == stack[j + 1])
				return (1);
			j++;
		}
		i++;
		j = i;
	}
	return (0);
}

int	check_int(int i, int argc, char	**argv)
{
	while (i < argc)
	{
		if ((argv[i][0] == '-') && (ft_strlen(argv[i]) >= 11))
		{
			if (ft_strlen(argv[i]) > 11 || argv[i][9] > '4'
				|| argv[i][10] > '8')
				return (1);
		}
		else if ((argv[i][0] != '-') && (ft_strlen(argv[i]) >= 10))
		{
			if (argv[i][8] > '4' || argv[i][9] > '7' || ft_strlen(argv[i]) > 10)
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_argv(int argc, char **argv, int index)
{
	int	i;
	int	j;

	i = index;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0 && argv[i][0] != '-')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (check_int(index, argc, argv));
}
