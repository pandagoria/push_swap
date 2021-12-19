#include "../push_swap.h"

int	*ft_intdup(int *s1, int len)
{
	int	*dup;
	int	i;

	dup = (int *) malloc(len * sizeof(int));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	return (dup);
}

int	*push_copy_second(int *new_two, int *len, int *stck)
{
	if (*len > 1)
	{
		free((void *) stck);
		*len -= 1;
		stck = ft_intdup(new_two, *len);
	}
	else if (*len <= 1)
	{
		free((void *) stck);
		*len = 0;
	}
	return (stck);
}

int	*push_copy_first(int *new_one, int *stck, int len)
{
	int	i;

	i = 1;
	while (i - 1 < len)
	{
		new_one[i] = stck[i - 1];
		i++;
	}
	return (new_one);
}

void	push_a(s_tack *stck)
{
	int	*new_one;
	int	*new_two;
	int	i;

	if (!stck->b)
		return ;
	new_one = (int *) malloc (sizeof(int) * (stck->len_a + 1));
	if (stck->len_b > 1)
		new_two = (int *) malloc (sizeof(int) * stck->len_b - 1);
	new_one[0] = stck->b[0];
	new_one = push_copy_first(new_one, stck->a, stck->len_a);
	i = 0;
	while (i < (stck->len_b - 1) && stck->len_b > 1)
	{
		new_two[i] = stck->b[i + 1];
		i++;
	}
	if (stck->len_a > 0)
		free(stck->a);
	stck->len_a += 1;
	stck->a = ft_intdup(new_one, stck->len_a);
	stck->b = push_copy_second(new_two, &stck->len_b, stck->b);
}

void	push_b(s_tack *stck)
{
	int	*new_one;
	int	*new_two;
	int	i;

	if (!stck->a)
		return ;
	new_one = (int *) malloc (sizeof(int) * (stck->len_b + 1));
	if (stck->len_a > 1)
		new_two = (int *) malloc (sizeof(int) * stck->len_a - 1);
	new_one[0] = stck->a[0];
	new_one = push_copy_first(new_one, stck->b, stck->len_b);
	i = 0;
	while (i < (stck->len_a - 1) && stck->len_a > 1)
	{
		new_two[i] = stck->a[i + 1];
		i++;
	}
	if (stck->len_b > 0)
		free(stck->b);
	stck->len_b += 1;
	stck->b = ft_intdup(new_one, stck->len_b);
	stck->a = push_copy_second(new_two, &stck->len_a, stck->a);
}
