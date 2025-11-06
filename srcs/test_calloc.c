/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:16:40 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/05 19:20:03 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	manual_test(void)
{
	void	*p;
	void	*p2;
	int		res;

	res = 0;
	p = ft_calloc(0, 1);
	res = res || p == NULL;
	free(p);
	p = ft_calloc(1, 0);
	res = res || p == NULL;
	free(p);
	p = ft_calloc(SIZE_MAX, 2);
	res = res || p != NULL;
	free(p);
	p = ft_calloc(2, SIZE_MAX);
	res = res || p != NULL;
	free(p);
	p = ft_calloc(10, 10);
	p2 = calloc(10, 10);
	res = res || memcmp(p, p2, 100);
	free(p);
	return (res);
}

int	test_calloc(void)
{
	if (manual_test())
		return (1);
	return (0);
}
