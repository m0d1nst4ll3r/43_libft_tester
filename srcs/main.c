/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:10:17 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/04 16:06:31 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static void	test_bonus(void)
{
	printf("[%sBONUS%s]\n", KMAG, KRES);
}

int	main(void)
{
	printf("[%sPART1%s]\n", KMAG, KRES);
	printf("[%s] ft_isascii\n", tester(test_isascii));
	printf("[%s] ft_isalpha\n", tester(test_isalpha));
	printf("[%s] ft_isalnum\n", tester(test_isalnum));
	printf("[%s] ft_isdigit\n", tester(test_isdigit));
	printf("[%s] ft_isprint\n", tester(test_isprint));
	printf("[%s] ft_tolower\n", tester(test_tolower));
	printf("[%s] ft_toupper\n", tester(test_toupper));
	printf("[%s] ft_atoi\n", tester(test_atoi));
	printf("[%s] ft_strnstr\n", tester(test_strnstr));
	printf("[%s] ft_bzero\n", tester(test_bzero));
	printf("[%s] ft_memset\n", tester(test_memset));
	printf("[%s] ft_memchr\n", tester(test_memchr));
	printf("[%s] ft_strchr\n", tester(test_strchr));
	printf("[%s] ft_strrchr\n", tester(test_strrchr));
	printf("[%s] ft_memcpy\n", tester(test_memcpy));
	printf("[%s] ft_strlcpy\n", tester(test_strlcpy));
	printf("[%sPART2%s]\n", KMAG, KRES);
	if (BONUS)
		test_bonus();
}
