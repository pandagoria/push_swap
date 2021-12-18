#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct	t_value
{
	int	min;
	int	min_i;

} t_value;

typedef struct	s_tack
{
	int	*a;
	int	len_a;
	int	*b;
	int	len_b;
} s_tack;

void	swap_ab(int *stck, int len, char stack);
int		*ft_intdup(int *s1, int len);
void	push_a(s_tack *stck);
void	push_b(s_tack *stck);
void	r_ab(int *stck, int len, char stack);
void	rr_ab(int *stck, int len, char stack);
int		*sorted_arr(s_tack *stck);
void	radix_sort(s_tack *stck);
void	min_sort(s_tack *stck);
void	tostack_b(s_tack *stck, t_value *prm);
int		check_duplicate(int *stack, int index);
int		check_int(int i, int argc, char	**argv);
int		check_argv(int argc, char **argv, int index);
int		find_min(int *stck, int len);
int		find_max(int *stck, int len);
int		is_sorted(int *stck, int len);
int		rev_sorted(int *stck, int len);

#endif
