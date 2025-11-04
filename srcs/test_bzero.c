/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:41:41 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/04 11:52:32 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	random_test(int lower, int upper)
{
	char	*s1;
	char	*s2;
	int		n;
	int		i;
	int		res;

	i = 0;
	while (i < TEST_N)
	{
		n = rand_range(lower, upper);
		s1 = malloc(n);
		s2 = malloc(n);
		if (!s1 || !s2)
		{
			free(s1);
			free(s2);
			malloc_error();
		}
		ft_bzero(s1, n);
		bzero(s2, n);
		res = memcmp(s1, s2, n);
		free(s1);
		free(s2);
		if (!res)
			return (1);
		i++;
	}
	return (0);
}

int	test_bzero(void)
{
	if (!random_test(NUL_TEST_FLOOR, NUL_TEST_CEIL)
		|| !random_test(SML_TEST_FLOOR, SML_TEST_CEIL)
		|| !random_test(MED_TEST_FLOOR, MED_TEST_CEIL)
		|| !random_test(BIG_TEST_FLOOR, BIG_TEST_CEIL))
		return (1);
	return (0);
}
