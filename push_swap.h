/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:57:24 by hlaunch           #+#    #+#             */
/*   Updated: 2021/12/20 16:57:26 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct t_tack
{
	int	*a;
	int	len_a;
	int	*b;
	int	len_b;
}	t_tack;

int		check_argv(int argc, char **argv, int index);
int		check_duplicate(int *stack, int index);
int		is_sorted(int *stck, int len);
int		find_max(int *stck, int len);
int		find_min(int *stck, int len);
void	mini_sort(t_tack *stck);
void	big_sort(t_tack *stck);
void	push_b(t_tack *stck);
void	push_a(t_tack *stck);
void	rr_ab(int *stck, int len, char stack);
void	r_ab(int *stck, int len, char stack);
void	swap_ab(int *stck, int len, char stack);

#endif
