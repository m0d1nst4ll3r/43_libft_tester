/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:36:07 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/08 13:48:43 by rapohlen         ###   ########.fr       */
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

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	strscmp(char **tab1, char **tab2)
{
	int	i;

	i = 0;
	while (tab1[i] && tab2[i] && !strcmp(tab1[i], tab2[i]))
		i++;
	if (tab1[i] || tab2[i])
		return (1);
	return (0);
}
