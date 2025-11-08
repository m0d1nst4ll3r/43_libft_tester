/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_striteri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:10:01 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/08 16:47:06 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

// Stupid function that does nothing smart, because striteri is useless
static void	striteri_tester(unsigned int i, char *c)
{
	if (i % 2)
		*c = 'l';
	else
		*c = 'o';
}

static int	check_iteri_string(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((i % 2 && s[i] != 'l')
			|| (!(i % 2) && s[i] != 'o'))
			return (1);
		i++;
	}
	return (0);
}

static int	random_test(t_tester *dat, int lower, int upper)
{
	dat->i = 0;
	while (dat->i < TEST_N / 20)
	{
		dat->n = rand_range(lower, upper);
		fill_str(dat->s1, dat->n, 1, UCHAR_MAX);
		ft_striteri(dat->s1, striteri_tester);
		if (check_iteri_string(dat->s1))
			return (1);
		dat->i++;
	}
	return (0);
}

int	test_striteri(t_tester *dat)
{
	if (random_test(dat, NUL_TEST_FLOOR, NUL_TEST_CEIL)
		|| random_test(dat, SML_TEST_CEIL, SML_TEST_CEIL)
		|| random_test(dat, MED_TEST_CEIL, MED_TEST_CEIL)
		|| random_test(dat, BIG_TEST_CEIL, BIG_TEST_CEIL))
		return (1);
	return (0);
}
