/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strmapi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:48:38 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/08 17:41:20 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

// Another stupid function that also doesn't do anything smart
//	because strmapi is useless
static char	strmapi_tester(unsigned int i, char c)
{
	if (i % 2)
		return ('l');
	if (c % 2)
		return ('i');
	return ('o');
}

static int	check_mapi_string(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (i % 2 && s1[i] != 'l')
			return (1);
		else if (!(i % 2))
		{
			if ((s2[i] % 2 && s1[i] != 'i')
				|| (!(s2[i] % 2) && s1[i] != 'o'))
				return (1);
		}
		i++;
	}
	return (0);
}

static int	random_test(t_tester *dat, int lower, int upper)
{
	dat->i = 0;
	while (dat->i < TEST_N)
	{
		dat->n = rand_range(lower, upper);
		fill_str(dat->s1, dat->n, 1, UCHAR_MAX);
		dat->ft_res = ft_strmapi(dat->s1, strmapi_tester);
		dat->res = check_mapi_string(dat->ft_res, dat->s1);
		free_null(&(dat->ft_res));
		if (dat->res)
			return (1);
		dat->i++;
	}
	return (0);
}

int	test_strmapi(t_tester *dat)
{
	if (random_test(dat, NUL_TEST_FLOOR, NUL_TEST_CEIL)
		|| random_test(dat, SML_TEST_CEIL, SML_TEST_CEIL)
		|| random_test(dat, MED_TEST_CEIL, MED_TEST_CEIL)
		|| random_test(dat, BIG_TEST_CEIL, BIG_TEST_CEIL))
		return (1);
	return (0);
}
