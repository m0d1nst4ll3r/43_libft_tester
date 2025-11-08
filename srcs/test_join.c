/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:01:38 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/08 17:50:52 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	random_test_n(t_tester *dat, int lower, int upper)
{
	dat->i2 = 0;
	while (dat->i2 < TEST_N / 10)
	{
		dat->n = rand_range(lower, upper);
		fill_str(dat->s2, dat->n, 1, UCHAR_MAX);
		dat->ft_res = ft_strjoin(dat->s1, dat->s2);
		dat->of_res = strjoin(dat->s1, dat->s2);
		if (!dat->ft_res || !dat->of_res)
			malloc_error(dat);
		dat->res = strcmp(dat->ft_res, dat->of_res);
		free_null(&(dat->ft_res));
		free_null(&(dat->of_res));
		if (dat->res)
			return (1);
		dat->i2++;
	}
	return (0);
}

static int	random_test(t_tester *dat, int lower, int upper)
{
	dat->i = 0;
	while (dat->i < TEST_N / 10)
	{
		dat->n = rand_range(lower, upper);
		fill_str(dat->s1, dat->n, 1, UCHAR_MAX);
		if (random_test_n(dat, NUL_TEST_FLOOR, NUL_TEST_CEIL)
			|| random_test_n(dat, SML_TEST_FLOOR, SML_TEST_CEIL)
			|| random_test_n(dat, MED_TEST_FLOOR, MED_TEST_CEIL)
			|| random_test_n(dat, BIG_TEST_FLOOR, BIG_TEST_CEIL))
			return (1);
		dat->i++;
	}
	return (0);
}

int	test_strjoin(t_tester *dat)
{
	if (random_test(dat, NUL_TEST_FLOOR, NUL_TEST_FLOOR) 
			|| random_test(dat, SML_TEST_FLOOR, SML_TEST_CEIL)
			|| random_test(dat, MED_TEST_FLOOR, MED_TEST_CEIL)
			|| random_test(dat, BIG_TEST_FLOOR, BIG_TEST_CEIL))
		return (1);
	return (0);
}
