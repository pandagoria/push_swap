#include "push_swap.h"

void	swap_ab(int *stck, int len, char stack)
{
	int	tmp_0;
	int	tmp_1;

	if (len < 2)
		return ;
	tmp_0 = stck[0];
	tmp_1 = stck[1];
	stck[0] = tmp_1;
	stck[1] = tmp_0;
	if (stack == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	r_ab(int *stck, int len, char stack)
{
	int	tmp;
	int	i;

	if (len < 2)
		return ;
	tmp = stck[0];
	i = 0;
	while (i < len - 1)
	{
		stck[i] = stck[i + 1];
		i++;
	}
	stck[i] = tmp;
	if (stack == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	rr_ab(int *stck, int len, char stack)
{
	int	tmp;
	int	i;

	if (len < 2)
		return ;
	tmp = stck[len - 1];
	i = len - 1;
	while (i > 0)
	{
		stck[i] = stck[i - 1];
		i--;
	}
	stck[i] = tmp;
	if (stack == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}
