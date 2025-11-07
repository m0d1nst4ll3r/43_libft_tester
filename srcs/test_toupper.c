/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_toupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:48:30 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/07 16:45:13 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	random_test(t_tester *dat)
{
	dat->i = 0;
	while (dat->i < TEST_N * 100)
	{
		dat->n = rand_range(ISFUNC_FLOOR, ISFUNC_CEIL);
		if (ft_toupper(dat->n) != toupper(dat->n))
			return (1);
		dat->i++;
	}
	return (0);
}

int	test_toupper(t_tester *dat)
{
	if (random_test(dat))
		return (1);
	return (0);
}
