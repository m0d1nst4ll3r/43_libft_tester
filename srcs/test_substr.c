/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:14:23 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/07 18:46:16 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static void	manual_test_n(t_tester *dat, char *s, int n, int n2)
{
	dat->ft_res = ft_substr(s, n, n2);
	dat->of_res = substr(s, n, n2);
	if (!dat->ft_res || !dat->of_res)
		malloc_error(dat);
}

static int	manual_test(t_tester *dat)
{
	manual_test_n(dat, "", 0, 0);
	dat->res = strcmp(dat->ft_res, dat->of_res);
	free_null(&(dat->ft_res));
	free_null(&(dat->of_res));
	manual_test_n(dat, "", 0, 10);
	dat->res = dat->res || strcmp(dat->ft_res, dat->of_res);
	free_null(&(dat->ft_res));
	free_null(&(dat->of_res));
	manual_test_n(dat, "123", 3, 0);
	dat->res = dat->res || strcmp(dat->ft_res, dat->of_res);
	free_null(&(dat->ft_res));
	free_null(&(dat->of_res));
	manual_test_n(dat, "123", 3, 10);
	dat->res = dat->res || strcmp(dat->ft_res, dat->of_res);
	free_null(&(dat->ft_res));
	free_null(&(dat->of_res));
	manual_test_n(dat, "123", 1, 10);
	dat->res = dat->res || strcmp(dat->ft_res, dat->of_res);
	free_null(&(dat->ft_res));
	free_null(&(dat->of_res));
	return (dat->res);
}

static int	random_test_n(t_tester *dat)
{
	dat->i2 = 0;
	while (dat->i2 < TEST_N / 10)
	{
		dat->n2 = rand_range(0, dat->n);
		dat->i3 = 0;
		while (dat->i3 < TEST_N / 10)
		{
			dat->n3 = rand_range(0, dat->n);
			dat->ft_res = ft_substr(dat->s1, dat->n2, dat->n3);
			dat->of_res = substr(dat->s1, dat->n2, dat->n3);
			if (!dat->ft_res || !dat->of_res)
				malloc_error(dat);
			dat->res = strcmp(dat->s1, dat->s2);
			free_null(&(dat->ft_res));
			free_null(&(dat->of_res));
			if (dat->res)
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
	while (dat->i < TEST_N / 10)
	{
		dat->n = rand_range(lower, upper);
		fill_str(dat->s1, dat->n, 1, UCHAR_MAX);
		if (random_test_n(dat))
			return (1);
		dat->i++;
	}
	return (0);
}

int	test_substr(t_tester *dat)
{
	if (manual_test(dat)
		|| random_test(dat, NUL_TEST_FLOOR, NUL_TEST_CEIL)
		|| random_test(dat, SML_TEST_FLOOR, SML_TEST_CEIL)
		|| random_test(dat, MED_TEST_FLOOR, MED_TEST_CEIL)
		|| random_test(dat, BIG_TEST_FLOOR, BIG_TEST_CEIL))
		return (1);
	return (0);
}
