/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:22:02 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/04 16:25:57 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	random_test(int lower, int upper)
{
	int		i;
	char	*s;
	int		n;
	int		res;

	i = 0;
	while (i < TEST_N / 2)
	{
		n = rand_range(lower, upper);
		s = malloc(n + 1);
		if (!s)
			malloc_error();
		fill_str(s, n, 1, 1);
		res = (ft_strlen(s) != strlen(s));
		free(s);
		if (res)
			return (1);
		i++;
	}
	return (0);
}

int	test_strlen(void)
{
	if (random_test(NUL_TEST_FLOOR, NUL_TEST_CEIL)
		|| random_test(SML_TEST_FLOOR, SML_TEST_CEIL)
		|| random_test(MED_TEST_FLOOR, MED_TEST_CEIL)
		|| random_test(BIG_TEST_FLOOR, BIG_TEST_CEIL))
		return (1);
	return (0);
}
