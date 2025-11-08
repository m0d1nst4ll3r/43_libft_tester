/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:51:20 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/08 13:51:43 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

void	init_null(t_tester *dat)
{
	dat->s1 = NULL;
	dat->s2 = NULL;
	dat->s3 = NULL;
	dat->ft_res = NULL;
	dat->of_res = NULL;
	dat->ft_res_tab = NULL;
	dat->of_res_tab = NULL;
	dat->ft_list = NULL;
	dat->of_list = NULL;
}

// Init s1, s2, s3 by the max value they can take
void	init_malloc(t_tester *dat)
{
	dat->s1 = malloc(BIG_TEST_CEIL + 1);
	dat->s2 = malloc(BIG_TEST_CEIL + 1);
	dat->s3 = malloc(BIG_TEST_CEIL + 1);
	if (!dat->s1 || !dat->s2 || !dat->s3)
		malloc_error(dat);
}

