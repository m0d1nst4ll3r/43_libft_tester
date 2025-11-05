/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:46:37 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/05 15:00:56 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	manual_test(void)
{
	char	*s1;
	char	s2[100];
	char	s3[100];
	int		i;
	int		res1;
	int		res2;

	s1 = "abc";
	i = 0;
	while (i < 10)
	{
		strcpy(s2, s1);
		strcpy(s3, s1);
		res1 = ft_strlcat(s2, s1, i);
		res2 = strlcat(s3, s1, i);
		if (res1 != res2 || strcmp(s2, s3))
			return (1);
		i++;
	}
	return (0);
}

int	test_strlcat(void)
{
	if (manual_test())
		return (1);
	return (0);
}
