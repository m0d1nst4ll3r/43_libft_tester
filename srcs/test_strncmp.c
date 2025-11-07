/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:27:58 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/07 18:40:37 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	manual_test(void)
{
	if (ft_strncmp("1", "2", 1) >= 0
		|| ft_strncmp("12", "13", 1))
		return (1);
	return (0);
}

static int	random_test_n(t_tester *dat)
{
	dat->i2 = 0;
	while (dat->i2 < TEST_N / 2)
	{
		dat->n2 = rand_range(0, dat->n * 2);
		dat->res = ft_strncmp(dat->s1, dat->s2, dat->n2);
		dat->res2 = strncmp(dat->s1, dat->s2, dat->n2);
		if (ft_strncmp(dat->s1, dat->s1, dat->n2)
			|| ft_strncmp(dat->s2, dat->s2, dat->n2)
			|| !((dat->res == dat->res2)
				|| (dat->res < 0 && dat->res2 < 0)
				|| (dat->res > 0 && dat->res2 > 0)))
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
		fill_str(dat->s1, dat->n, STRCHR_CHAR_FLOOR, STRCHR_CHAR_CEIL);
		fill_str(dat->s2, dat->n, STRCHR_CHAR_FLOOR, STRCHR_CHAR_CEIL);
		if (random_test_n(dat))
			return (1);
		dat->i++;
	}
	return (0);
}

int	test_strncmp(t_tester *dat)
{
	if (manual_test()
		|| random_test(dat, NUL_TEST_FLOOR, NUL_TEST_CEIL)
		|| random_test(dat, SML_TEST_FLOOR, SML_TEST_CEIL)
		|| random_test(dat, MED_TEST_FLOOR, MED_TEST_CEIL)
		|| random_test(dat, BIG_TEST_FLOOR, BIG_TEST_CEIL))
		return (1);
	return (0);
}
