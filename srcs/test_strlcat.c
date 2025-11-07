/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:46:37 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/07 15:27:56 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	manual_test(t_tester *dat)
{
	char	*s;

	s = "abc";
	while (dat->i < 10)
	{
		strcpy(dat->s1, s);
		strcpy(dat->s2, s);
		dat->res = ft_strlcat(dat->s1, s, dat->i);
		dat->res2 = strlcat(dat->s2, s, dat->i);
		if (dat->res != dat->res2 || strcmp(dat->s1, dat->s2))
			return (1);
		dat->i++;
	}
	return (0);
}

int	test_strlcat(t_tester *dat)
{
	if (manual_test(dat))
		return (1);
	return (0);
}
