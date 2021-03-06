/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:57:11 by hlaunch           #+#    #+#             */
/*   Updated: 2021/12/20 16:57:18 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

int	size_matrix(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_mat(char **mat, int i)
{
	while (i--)
		free(mat[i]);
	free(mat);
}

t_tack	init_stack(char	**str, int len, int i)
{
	t_tack	stck;

	stck.b = NULL;
	stck.len_b = 0;
	stck.a = (int *) malloc ((len) * sizeof(int));
	stck.len_a = 0;
	while (stck.len_a < len)
	{
		stck.a[stck.len_a] = ft_atoi(str[i]);
		stck.len_a++;
		i++;
	}
	if (check_duplicate(stck.a, stck.len_a - 1) == 1)
	{
		free(stck.a);
		write(2, "Error\n", 6);
		exit(1);
	}
	return (stck);
}

t_tack	one_arg_input(char **argv)
{
	char	**new_arg;
	int		len;
	t_tack	stck;

	new_arg = ft_split(argv[1], ' ');
	len = size_matrix(new_arg);
	if (check_argv(len, new_arg, 0) == 0)
		stck = init_stack(new_arg, len, 0);
	else
	{
		free_mat(new_arg, len);
		write(2, "Error\n", 6);
		exit(1);
	}
	free_mat(new_arg, len);
	return (stck);
}

int	main(int argc, char	**argv)
{
	t_tack	stck;

	if (argc == 1 || !argv[1][0])
		return (0);
	if (argc == 2 && ft_strchr(argv[1], ' '))
		stck = one_arg_input(argv);
	else if (argc > 2)
	{
		if (check_argv(argc, argv, 1) == 0)
			stck = init_stack(argv, argc - 1, 1);
		else
		{
			write(2, "Error\n", 6);
			exit(1);
		}
	}
	if (stck.len_a >= 60)
		big_sort(&stck);
	else
		mini_sort(&stck);
	free(stck.a);
	if (stck.len_b > 0)
		free(stck.b);
	return (0);
}
