/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:35:52 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/08 15:50:00 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	random_test_n(t_tester *dat)
{
	dat->i2 = 0;
	while (dat->i2 < TEST_N / 5)
	{
		dat->n2 = rand_range(1, UCHAR_MAX);
		dat->ft_res_tab = ft_split(dat->s1, dat->n2);
		dat->of_res_tab = strsplit(dat->s1, dat->n2);
		dat->res = strscmp(dat->ft_res_tab, dat->of_res_tab);
		free_tab(&(dat->ft_res_tab));
		free_tab(&(dat->of_res_tab));
		if (dat->res)
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
		fill_str(dat->s1, dat->n, 1, UCHAR_MAX);
		if (random_test_n(dat))
			return (1);
		dat->i++;
	}
	return (0);
}

int	test_split(t_tester *dat)
{
	if (random_test(dat, NUL_TEST_FLOOR, NUL_TEST_CEIL)
		|| random_test(dat, SML_TEST_FLOOR, SML_TEST_CEIL)
		|| random_test(dat, MED_TEST_FLOOR, MED_TEST_CEIL)
		|| random_test(dat, BIG_TEST_FLOOR, BIG_TEST_CEIL))
		return (1);
	return (0);
}
