/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:16:40 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/07 18:44:58 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	manual_test(t_tester *dat)
{
	dat->ft_res = ft_calloc(0, 1);
	dat->res = dat->ft_res == NULL;
	free_null(&(dat->ft_res));
	dat->ft_res = ft_calloc(1, 0);
	dat->res = dat->res || dat->ft_res == NULL;
	free_null(&(dat->ft_res));
	dat->ft_res = ft_calloc(SIZE_MAX, 2);
	dat->res = dat->res || dat->ft_res != NULL;
	free_null(&(dat->ft_res));
	dat->ft_res = ft_calloc(2, SIZE_MAX);
	dat->res = dat->res || dat->ft_res != NULL;
	free_null(&(dat->ft_res));
	dat->ft_res = ft_calloc(10, 10);
	dat->of_res = ft_calloc(10, 10);
	if (!dat->ft_res || !dat->of_res)
		malloc_error(dat);
	dat->res = dat->res || memcmp(dat->ft_res, dat->of_res, 100);
	free_null(&(dat->ft_res));
	free_null(&(dat->of_res));
	return (dat->res);
}

int	test_calloc(t_tester *dat)
{
	if (manual_test(dat))
		return (1);
	return (0);
}
