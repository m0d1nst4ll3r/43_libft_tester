/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:24:27 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/07 18:39:27 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	random_test_n(t_tester *dat)
{
	dat->i2 = 0;
	while (dat->i2 < TEST_N / 2)
	{
		dat->n2 = rand_range(0, dat->n * 2);
		if (ft_strlcpy(dat->s2, dat->s1, dat->n2)
			!= strlcpy(dat->s3, dat->s1, dat->n2)
			|| memcmp(dat->s2, dat->s3, dat->n + 1))
			return (1);
		dat->i2++;
	}
	return (0);
}

static int	random_test(t_tester *dat, int lower, int upper)
{
	dat->i = 0;
	while (dat->i < TEST_N / 2)
	{
		dat->n = rand_range(lower, upper);
		fill_str(dat->s1, dat->n, 1, UCHAR_MAX);
		fill_str(dat->s2, dat->n, 'z', 'z');
		fill_str(dat->s3, dat->n, 'z', 'z');
		if (random_test_n(dat))
			return (1);
		dat->i++;
	}
	return (0);
}

int	test_strlcpy(t_tester *dat)
{
	if (random_test(dat, NUL_TEST_FLOOR, NUL_TEST_CEIL)
		|| random_test(dat, SML_TEST_FLOOR, SML_TEST_CEIL)
		|| random_test(dat, MED_TEST_FLOOR, MED_TEST_CEIL)
		|| random_test(dat, BIG_TEST_FLOOR, BIG_TEST_CEIL))
		return (1);
	return (0);
}
