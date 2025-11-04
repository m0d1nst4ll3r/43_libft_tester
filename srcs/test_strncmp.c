/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:27:58 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/04 17:20:19 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	manual_test(void)
{
	if (ft_strncmp("1", "2", 1) >= 0)
		return (1);
	if (ft_strncmp("12", "13", 1))
		return (1);
	return (0);
}

static int	random_test_n(char *s1, char *s2, int n)
{
	int	i;
	int	n2;
	int	res1;
	int	res2;

	i = 0;
	while (i < TEST_N / 2)
	{
		n2 = rand_range(0, n * 2);
		res1 = ft_strncmp(s1, s2, n2);
		res2 = strncmp(s1, s2, n2);
		if (ft_strncmp(s1, s1, n2)
			|| !((res1 == res2)
				|| (res1 < 0 && res2 < 0)
				|| (res1 > 0 && res2 > 0)))
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
	while (i < TEST_N / 10)
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
		fill_str(s1, n, STRCHR_CHAR_FLOOR, STRCHR_CHAR_CEIL);
		fill_str(s2, n, STRCHR_CHAR_FLOOR, STRCHR_CHAR_CEIL);
		res = random_test_n(s1, s2, n);
		free(s1);
		free(s2);
		if (res)
			return (1);
		i++;
	}
	return (0);
}

int	test_strncmp(void)
{
	if (manual_test()
		|| random_test(NUL_TEST_FLOOR, NUL_TEST_CEIL)
		|| random_test(SML_TEST_FLOOR, SML_TEST_CEIL)
		|| random_test(MED_TEST_FLOOR, MED_TEST_CEIL)
		|| random_test(BIG_TEST_FLOOR, BIG_TEST_CEIL))
		return (1);
	return (0);
}
