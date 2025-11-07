/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:56:10 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/07 18:18:09 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	random_test(t_tester *dat, int lower, int upper)
{
	dat->i = 0;
	while (dat->i < TEST_N * 100)
	{
		dat->n = rand_range(lower, upper);
		if ((ft_isascii(dat->n) && 1) != (isascii(dat->n) && 1))
			return (1);
		dat->i++;
	}
	return (0);
}

int	test_isascii(t_tester *dat)
{
	if (random_test(dat, ISFUNC_FLOOR, ISFUNC_CEIL))
		return (1);
	return (0);
}
