/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:52:17 by hlaunch           #+#    #+#             */
/*   Updated: 2021/10/15 14:52:20 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t	nmemb, size_t	size)
{
	void	*res;

	res = (void *) malloc(nmemb * size);
	if (res)
	{
		ft_bzero(res, nmemb * size);
		return (res);
	}
	return (0);
}
