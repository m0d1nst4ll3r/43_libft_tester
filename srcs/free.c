/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:48:13 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/08 15:48:17 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

void	free_null(char **p)
{
	free(*p);
	*p = NULL;
}

void	free_tab(char ***tab)
{
	int	i;

	i = 0;
	while (*tab && (*tab)[i])
	{
		free((*tab)[i]);
		i++;
	}
	free(*tab);
	*tab = NULL;
}

void	free_all(t_tester *dat)
{
	free(dat->s1);
	free(dat->s2);
	free(dat->s3);
	free(dat->ft_res);
	free(dat->of_res);
	free_tab(&(dat->ft_res_tab));
	free_tab(&(dat->of_res_tab));
	lstclear(&(dat->ft_list), dummy);
	lstclear(&(dat->of_list), dummy);
}
