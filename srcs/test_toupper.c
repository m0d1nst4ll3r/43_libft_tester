/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_toupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:48:30 by rapohlen          #+#    #+#             */
/*   Updated: 2025/10/23 17:01:30 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	random_test()
{
	int		i;
	int		n;

	i = 0;
	while (i < TEST_N * 100)
	{
		n = rand_range(ISFUNC_FLOOR, ISFUNC_CEIL);
		if (ft_toupper(n) != toupper(n))
			return (1);
		i++;
	}
	return (0);
}

int	test_toupper(void)
{
	if (random_test())
		return (1);
	return (0);
}
