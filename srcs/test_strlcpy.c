/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:24:27 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/04 16:15:31 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	random_test_n(char *s1, char *s2, char *s3, int n)
{
	int	i;
	int	n2;

	i = 0;
	while (i < TEST_N / 2)
	{
		n2 = rand_range(0, n * 2);
		if (ft_strlcpy(s2, s1, n2) != strlcpy(s3, s1, n2) || memcmp(s2, s3, n + 1))
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
	char	*s3;
	int		res;

	i = 0;
	while (i < TEST_N / 2)
	{
		n = rand_range(lower, upper);
		s1 = malloc(n + 1);
		s2 = malloc(n + 1);
		s3 = malloc(n + 1);
		if (!s1 || !s2 || !s3)
		{
			free(s1);
			free(s2);
			free(s3);
			malloc_error();
		}
		fill_str(s1, n, 1, UCHAR_MAX);
		fill_str(s2, n, 'z', 'z');
		fill_str(s3, n, 'z', 'z');
		res = random_test_n(s1, s2, s3, n);
		free(s1);
		free(s2);
		free(s3);
		if (res)
			return (1);
		i++;
	}
	return (0);
}

int	test_strlcpy(void)
{
	if (random_test(NUL_TEST_FLOOR, NUL_TEST_CEIL)
		|| random_test(SML_TEST_FLOOR, SML_TEST_CEIL)
		|| random_test(MED_TEST_FLOOR, MED_TEST_CEIL)
		|| random_test(BIG_TEST_FLOOR, BIG_TEST_CEIL))
		return (1);
	return (0);
}
