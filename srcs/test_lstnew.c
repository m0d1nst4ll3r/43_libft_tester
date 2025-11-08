/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:03:06 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/08 18:31:00 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static int	manual_test(t_tester *dat)
{
	char	*s;

	s = strdup("Test\n");
	dat->ft_list = ft_lstnew(s);
	dat->res = dat->ft_list->content != s || dat->ft_list->next != NULL;
	lstclear(&(dat->ft_list), list_free_func);
	if (dat->res)
		return (1);
	return (0);
}

int	test_lstnew(t_tester *dat)
{
	if (manual_test(dat))
		return (1);
	return (0);
}
