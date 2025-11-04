/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:24:27 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/04 15:54:36 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	random_test(int lower, int upper)
{
	int		i;
	int		n;
	char	*s1;
	char	*s2;
	int		res;

	i = 0;
	while (i < TEST_N)
	{
		n = rand_range(lower, upper);
		s1 = malloc(n + 1);
		s2 = malloc(n + 1);
		if (!s1 || !s2)
		{
			free(s1);
			free(s2);
			malloc_error();
		}
		fill_str(s1, n, 0, UCHAR_MAX);
		ft_memcpy(s2, s1, n);
		res = memcmp(s1, s2, n);
		free(s1);
		free(s2);
		if (res)
			return (1);
		i++;
	}
	return (0);
}

int	test_memcpy(void)
{
	if (random_test(NUL_TEST_FLOOR, NUL_TEST_CEIL)
		|| random_test(SML_TEST_FLOOR, SML_TEST_CEIL)
		|| random_test(MED_TEST_FLOOR, MED_TEST_CEIL)
		|| random_test(BIG_TEST_FLOOR, BIG_TEST_CEIL))
		return (1);
	return (0);
}
