/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:15:11 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/10 13:46:34 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	random_test_n(t_tester *dat, int lower, int upper)
{
	dat->i2 = 0;
	while (dat->i2 < TEST_N / 2)
	{
		dat->n2 = rand_range(lower, upper);
		if (ft_strrchr(dat->s1, dat->n2) != strrchr(dat->s1, dat->n2))
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
		fill_str(dat->s1, dat->n, STRCHR_CHAR_FLOOR, STRCHR_CHAR_CEIL);
		if (random_test_n(dat, INT_MIN, -1)
			|| random_test_n(dat, 0, INT_MAX))
			return (1);
		dat->i++;
	}
	return (0);
}

int	test_strrchr(t_tester *dat)
{
	if (random_test(dat, NUL_TEST_FLOOR, NUL_TEST_CEIL)
		|| random_test(dat, SML_TEST_CEIL, SML_TEST_CEIL)
		|| random_test(dat, MED_TEST_CEIL, MED_TEST_CEIL)
		|| random_test(dat, BIG_TEST_CEIL, BIG_TEST_CEIL))
		return (1);
	return (0);
}
