/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:15:11 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/07 17:06:04 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	random_test_n(t_tester *dat, int lower, int upper)
{
	dat->i2 = 0;
	while (dat->i2 < TEST_N / 20)
	{
		dat->n2 = rand_range(lower, upper);
		fill_str(dat->s2, dat->n2, STRSTR_CHAR_FLOOR, STRSTR_CHAR_CEIL);
		dat->i3 = 0;
		while (dat->i3 < TEST_N / 20)
		{
			dat->n3 = rand_range(0, dat->n);
			if (ft_strnstr(dat->s1, dat->s2, dat->n3)
					!= strnstr(dat->s1, dat->s2, dat->n3))
				return (1);
			dat->i3++;
		}
		dat->i2++;
	}
	return (0);
}

static int	random_test(t_tester *dat, int lower, int upper)
{
	dat->i = 0;
	while (dat->i < TEST_N / 20)
	{
		dat->n = rand_range(lower, upper);
		fill_str(dat->s1, dat->n, STRSTR_CHAR_FLOOR, STRSTR_CHAR_CEIL);
		if (random_test_n(dat, NUL_TEST_FLOOR, NUL_TEST_CEIL)
			|| random_test_n(dat, SML_TEST_FLOOR, SML_TEST_CEIL)
			|| random_test_n(dat, MED_TEST_FLOOR, MED_TEST_CEIL)
			|| random_test_n(dat, BIG_TEST_FLOOR, BIG_TEST_CEIL))
			return (1);
		dat->i++;
	}
	return (0);
}

int	test_strnstr(t_tester *dat)
{
	if (random_test(dat, NUL_TEST_FLOOR, NUL_TEST_CEIL)
		|| random_test(dat, SML_TEST_CEIL, SML_TEST_CEIL)
		|| random_test(dat, MED_TEST_CEIL, MED_TEST_CEIL)
		|| random_test(dat, BIG_TEST_CEIL, BIG_TEST_CEIL))
		return (1);
	return (0);
}
