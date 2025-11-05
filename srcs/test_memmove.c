/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:19:34 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/05 11:34:27 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	random_test_n(char *s1, char *s2, int n)
{
	int	i;
	int	start1;
	int	start2;
	int	len;

	i = 0;
	while (i < TEST_N / 5)
	{
		start1 = rand_range(0, n);
		start2 = rand_range(0, n);
		len = rand_range(0, min(n - start1, n - start2));
		ft_memmove(s1 + start1, s1 + start2, len);
		memmove(s2 + start1, s2 + start2, len);
		if (memcmp(s1, s2, n))
			return (1);
		i++;
	}
	return (0);
}

static int	random_test(int lower, int upper)
{
	int		i;
	int		n;
	char	*s1;
	char	*s2;
	int		res;

	i = 0;
	while (i < TEST_N / 5)
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
		memcpy(s2, s1, n);
		res = random_test_n(s1, s2, n);
		free(s1);
		free(s2);
		if (res)
			return (1);
		i++;
	}
	return (0);
}

int	test_memmove(void)
{
	if (random_test(NUL_TEST_FLOOR, NUL_TEST_CEIL)
		|| random_test(SML_TEST_FLOOR, SML_TEST_CEIL)
		|| random_test(MED_TEST_FLOOR, MED_TEST_CEIL)
		|| random_test(BIG_TEST_FLOOR, BIG_TEST_CEIL))
		return (1);
	return (0);
}
