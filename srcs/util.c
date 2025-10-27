/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:36:07 by rapohlen          #+#    #+#             */
/*   Updated: 2025/10/22 19:29:36 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

int	rand_range(int a, int b)
{
	return (rand() % (b - a + 1) + a);
}

void	fill_str(char *s, int len, unsigned char lower, unsigned char upper)
{
	int		i;

	i = 0;
	while (i < len)
	{
		s[i] = (char)rand_range(lower, upper);
		i++;
	}
	s[i] = 0;
}
