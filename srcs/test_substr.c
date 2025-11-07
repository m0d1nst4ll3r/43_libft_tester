/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:14:23 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/06 12:34:20 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	manual_test(void)
{
	char	*s1;
	char	*s2;
	int		res;

	s1 = ft_substr("", 0, 0);
	s2 = substr("", 0, 0);
	res = strcmp(s1, s2);
	free(s1);
	free(s2);
	s1 = ft_substr("", 0, 10);
	s2 = substr("", 0, 10);
	res = res || strcmp(s1, s2);
	free(s1);
	free(s2);
	s1 = ft_substr("123", 3, 0);
	s2 = substr("123", 3, 0);
	res = res || strcmp(s1, s2);
	free(s1);
	free(s2);
	s1 = ft_substr("123", 3, 10);
	s2 = substr("123", 3, 10);
	res = res || strcmp(s1, s2);
	free(s1);
	free(s2);
	s1 = ft_substr("123", 1, 10);
	s2 = substr("123", 1, 10);
	res = res || strcmp(s1, s2);
	free(s1);
	free(s2);
	return (res);
}

static int	random_test_n2(char *s, int n, int n2)
{
	char	*s1;
	char	*s2;
	int		i;
	int		n3;
	int		res;

	i = 0;
	while (i < TEST_N / 10)
	{
		n3 = rand_range(0, n);
		s1 = ft_substr(s, n2, n3);
		s2 = substr(s, n2, n3);
		if (!s1 || !s2)
		{
			free(s1);
			free(s2);
			malloc_error();
		}
		res = strcmp(s1, s2);
		free(s1);
		free(s2);
		if (res)
			return (1);
		i++;
	}
	return (0);
}

static int	random_test_n(char *s, int n)
{
	int	i;
	int	n2;

	i = 0;
	while (i < TEST_N / 10)
	{
		n2 = rand_range(0, n);
		if (random_test_n2(s, n, n2))
			return (1);
		i++;
	}
	return (0);
}

static int	random_test(int lower, int upper)
{
	char	*s;
	int		n;
	int		i;
	int		res;

	i = 0;
	while (i < TEST_N / 10)
	{
		n = rand_range(lower, upper);
		s = malloc(n + 1);
		if (!s)
			malloc_error();
		fill_str(s, n, 1, UCHAR_MAX);
		res = random_test_n(s, n);
		free(s);
		if (res)
			return (1);
		i++;
	}
	return (0);
}

int	test_substr(void)
{
	if (manual_test()
		|| random_test(NUL_TEST_FLOOR, NUL_TEST_CEIL)
		|| random_test(SML_TEST_FLOOR, SML_TEST_CEIL)
		|| random_test(MED_TEST_FLOOR, MED_TEST_CEIL)
		|| random_test(BIG_TEST_FLOOR, BIG_TEST_CEIL))
		return (1);
	return (0);
}
