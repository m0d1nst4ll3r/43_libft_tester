/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:13:07 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/07 18:38:34 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	manual_test(void)
{
	if (ft_atoi("  100\xff") != atoi("  100\xff")
		|| ft_atoi("2147483647a") != atoi("2147483647a")
		|| ft_atoi("-2147483648a") != atoi("-2147483648a")
		|| ft_atoi("--1") != atoi("--1")
		|| ft_atoi("\t\n\v\f\r\n0a") != atoi("\t\n\v\f\r\n0a"))
		return (1);
	return (0);
}

static int	random_test(t_tester *dat)
{
	dat->i = 0;
	while (dat->i < TEST_N * 1000)
	{
		dat->n = rand_range(ATOI_FLOOR, ATOI_CEIL);
		fill_str(dat->s1, dat->n, 0, UCHAR_MAX);
		if (ft_atoi(dat->s1) != atoi(dat->s1))
			return (1);
		dat->i++;
	}
	return (0);
}

int	test_atoi(t_tester *dat)
{
	if (manual_test() || random_test(dat))
		return (1);
	return (0);
}
