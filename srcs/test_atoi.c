/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:13:07 by rapohlen          #+#    #+#             */
/*   Updated: 2025/10/23 17:31:40 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	manual_test(void)
{
	char	*s;

	s = "  100\xff";
	if (ft_atoi(s) != atoi(s))
		return (1);
	s = "2147483647a";
	if (ft_atoi(s) != atoi(s))
		return (1);
	s = "-2147483648a";
	if (ft_atoi(s) != atoi(s))
		return (1);
	s = "--1";
	if (ft_atoi(s) != atoi(s))
		return (1);
	s = "\t\n\v\f\r\n0a";
	if (ft_atoi(s) != atoi(s))
		return (1);
	return (0);
}

static int	random_test(void)
{
	int		i;
	char	*s;
	int		size;

	i = 0;
	while (i < TEST_N * 1000)
	{
		size = rand_range(ATOI_FLOOR, ATOI_CEIL);
		s = malloc(size + 1);
		if (!s)
			malloc_error();
		fill_str(s, size, 0, UCHAR_MAX);
		if (ft_atoi(s) != atoi(s))
			return (1);
		free(s);
		i++;
	}
	return (0);
}

int	test_atoi(void)
{
	if (manual_test() || random_test())
		return (1);
	return (0);
}
