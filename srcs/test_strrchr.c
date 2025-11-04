/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:15:11 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/04 15:23:53 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	random_test_c(char *s1)
{
	int	i;
	int	c;

	i = 0;
	while (i < TEST_N / 2)
	{
		c = rand_range(STRCHR_CHAR_FLOOR, STRCHR_CHAR_CEIL);
		if (ft_strrchr(s1, c) != strrchr(s1, c))
			return (1);
		i++;
	}
	return (0);
}

static int	random_test(int lower, int upper)
{
	int		i;
	char	*s1;
	int		n;
	int		res;

	i = 0;
	while (i < TEST_N / 2)
	{
		n = rand_range(lower, upper);
		s1 = malloc(n + 1);
		if (!s1) 
			malloc_error();
		fill_str(s1, n, STRCHR_CHAR_FLOOR, STRCHR_CHAR_CEIL);
		res = random_test_c(s1);
		free(s1);
		if (res)
			return (1);
		i++;
	}
	return (0);
}

int	test_strrchr(void)
{
	if (random_test(NUL_TEST_FLOOR, NUL_TEST_CEIL)
		|| random_test(SML_TEST_CEIL, SML_TEST_CEIL)
		|| random_test(MED_TEST_CEIL, MED_TEST_CEIL)
		|| random_test(BIG_TEST_CEIL, BIG_TEST_CEIL))
		return (1);
	return (0);
}
