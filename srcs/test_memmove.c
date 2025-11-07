/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:19:34 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/07 18:06:19 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

// n2	start1
// n3	start2
// n4	len
static int	random_test_n(t_tester *dat)
{
	dat->i2 = 0;
	while (dat->i2 < TEST_N / 5)
	{
		dat->n2 = rand_range(0, dat->n);
		dat->n3 = rand_range(0, dat->n);
		dat->n4 = rand_range(0, min(dat->n - dat->n2, dat->n - dat->n3));
		ft_memmove(dat->s1 + dat->n2, dat->s1 + dat->n3, dat->n4);
		memmove(dat->s2 + dat->n2, dat->s2 + dat->n3, dat->n4);
		if (memcmp(dat->s1, dat->s2, dat->n))
			return (1);
		dat->i2++;
	}
	return (0);
}

static int	random_test(t_tester *dat, int lower, int upper)
{
	dat->i = 0;
	while (dat->i < TEST_N / 5)
	{
		dat->n = rand_range(lower, upper);
		fill_str(dat->s1, dat->n, 0, UCHAR_MAX);
		memcpy(dat->s2, dat->s1, dat->n);
		if (random_test_n(dat))
			return (1);
		dat->i++;
	}
	return (0);
}

int	test_memmove(t_tester *dat)
{
	if (random_test(dat, NUL_TEST_FLOOR, NUL_TEST_CEIL)
		|| random_test(dat, SML_TEST_FLOOR, SML_TEST_CEIL)
		|| random_test(dat, MED_TEST_FLOOR, MED_TEST_CEIL)
		|| random_test(dat, BIG_TEST_FLOOR, BIG_TEST_CEIL))
		return (1);
	return (0);
}
