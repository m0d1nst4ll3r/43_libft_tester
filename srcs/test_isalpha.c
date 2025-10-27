/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:56:10 by rapohlen          #+#    #+#             */
/*   Updated: 2025/10/23 16:38:31 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	random_test(int floor, int ceil)
{
	int	i;
	int	n;

	i = 0;
	while (i < TEST_N * 100)
	{
		n = rand_range(floor, ceil);
		if ((ft_isalpha(n) && 1) != (isalpha(n) && 1))
			return (1);
		i++;
	}
	return (0);
}

int	test_isalpha(void)
{
	if (random_test(ISFUNC_FLOOR, ISFUNC_CEIL))
		return (1);
	return (0);
}
