/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:10:16 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/08 15:20:31 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

char	*tester(t_tester *dat, int (*f)(t_tester *dat))
{
	if (f(dat))
		return (KO_STR);
	return (OK_STR);
}
