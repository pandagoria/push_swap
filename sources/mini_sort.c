#include "../push_swap.h"

t_value	init_prm(void)
{
	t_value	prm;

	prm.min = 0;
	prm.min_i = 0;
	return (prm);
}

void	r_sort(s_tack *stck, t_value *prm)
{
	prm->min = find_min(stck->a, stck->len_a);
	while (stck->a[0] != prm->min)
	{
		if (stck->a[1] == prm->min)
		{
			r_ab(stck->a, stck->len_a, 'a');
			break ;
		}
		swap_ab(stck->a, stck->len_a, 'a');
		r_ab(stck->a, stck->len_a, 'a');
	}
}

void	sort_three(s_tack *stck, t_value *prm)
{
	prm->min = find_min(stck->a, stck->len_a);
	if (prm->min == stck->a[2])
	{
		if (stck->a[0] > stck->a[1])
			swap_ab(stck->a, stck->len_a, 'a');
		rr_ab(stck->a, stck->len_a, 'a');
	}
	else if (prm->min == stck->a[1])
	{
		if (stck->a[0] > stck->a[2])
			r_ab(stck->a, stck->len_a, 'a');
		else
			swap_ab(stck->a, stck->len_a, 'a');
	}
	else if (prm->min == stck->a[0])
	{
		swap_ab(stck->a, stck->len_a, 'a');
		r_ab(stck->a, stck->len_a, 'a');
	}
}

void	tostack_b(s_tack *stck, t_value *prm)
{
	int	i;

	i = 0;
	prm->min = find_min(stck->a, stck->len_a);
	while (i < stck->len_a)
	{
		if (stck->a[i] == prm->min)
			prm->min_i = i;
		i++;
	}
	while (stck->a[0] != prm->min)
	{
		if (prm->min_i == 1)
			swap_ab(stck->a, stck->len_a, 'a');
		else if (prm->min_i <= ((stck->len_a - 1) / 2))
			r_ab(stck->a, stck->len_a, 'a');
		else
			rr_ab(stck->a, stck->len_a, 'a');
	}
	write(1, "pb\n", 3);
	push_b(stck);
}

void	mini_sort(s_tack *stck)
{
	t_value	prm;

	prm = init_prm();
	if (is_sorted(stck->a, stck->len_a) == 1)
		return ;
	while (is_sorted(stck->a, stck->len_a) == 0 && stck->len_a > 3)
		tostack_b(stck, &prm);
	while (is_sorted(stck->a, stck->len_a) == 0)
		sort_three(stck, &prm);
	while (stck->len_b != 0)
	{
		write(1, "pa\n", 3);
		push_a(stck);
	}
}
