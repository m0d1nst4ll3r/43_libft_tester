/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:24:27 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/07 18:06:51 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	random_test(t_tester *dat, int lower, int upper)
{
	dat->i = 0;
	while (dat->i < TEST_N)
	{
		dat->n = rand_range(lower, upper);
		fill_str(dat->s1, dat->n, 0, UCHAR_MAX);
		ft_memcpy(dat->s2, dat->s1, dat->n);
		if (memcmp(dat->s1, dat->s2, dat->n))
			return (1);
		dat->i++;
	}
	return (0);
}

int	test_memcpy(t_tester *dat)
{
	if (random_test(dat, NUL_TEST_FLOOR, NUL_TEST_CEIL)
		|| random_test(dat, SML_TEST_FLOOR, SML_TEST_CEIL)
		|| random_test(dat, MED_TEST_FLOOR, MED_TEST_CEIL)
		|| random_test(dat, BIG_TEST_FLOOR, BIG_TEST_CEIL))
		return (1);
	return (0);
}
