/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:15:11 by rapohlen          #+#    #+#             */
/*   Updated: 2025/10/23 16:42:24 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	random_test_little_n(char *big, char *little, int len_big)
{
	int	i;
	int	n;

	i = 0;
	while (i < TEST_N / 20)
	{
		n = rand_range(0, len_big);
		if (ft_strnstr(big, little, n)
			!= strnstr(big, little, n))
			return (1);
		i++;
	}
	return (0);
}

static int	random_test_little(char *big, int len_big, int l1, int l2)
{
	int		len_little;
	char	*little;
	int		i;

	i = 0;
	while (i < TEST_N / 20)
	{
		len_little = rand_range(l1, l2);
		little = malloc(len_little + 1);
		if (!little)
		{
			free(big);
			malloc_error();
		}
		fill_str(little, len_little, STRSTR_CHAR_FLOOR, STRSTR_CHAR_CEIL);
		if (random_test_little_n(big, little, len_big))
				return (1);
		free(little);
		i++;
	}
	return (0);
}

static int	random_test(int b1, int b2)
{
	char	*big;
	int		i;
	int		len_big;

	i = 0;
	while (i < TEST_N / 20)
	{
		len_big = rand_range(b1, b2);
		big = malloc(len_big + 1);
		if (!big)
			malloc_error();
		fill_str(big, len_big, STRSTR_CHAR_FLOOR, STRSTR_CHAR_CEIL);
		if (random_test_little(big, len_big, NUL_TEST_FLOOR, NUL_TEST_CEIL)
			|| random_test_little(big, len_big, SML_TEST_FLOOR, SML_TEST_CEIL)
			|| random_test_little(big, len_big, MED_TEST_FLOOR, MED_TEST_CEIL)
			|| random_test_little(big, len_big, BIG_TEST_FLOOR, BIG_TEST_CEIL))
			return (1);
		free(big);
		i++;
	}
	return (0);
}

int	test_strnstr(void)
{
	if (random_test(NUL_TEST_FLOOR, NUL_TEST_CEIL)
		|| random_test(SML_TEST_CEIL, SML_TEST_CEIL)
		|| random_test(MED_TEST_CEIL, MED_TEST_CEIL)
		|| random_test(BIG_TEST_CEIL, BIG_TEST_CEIL))
		return (1);
	return (0);
}
