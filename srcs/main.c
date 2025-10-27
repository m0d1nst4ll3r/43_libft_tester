/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:10:17 by rapohlen          #+#    #+#             */
/*   Updated: 2025/10/23 17:20:45 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

int	main(void)
{
	printf("[%s] ft_isascii.c\n", tester(test_isascii));
	printf("[%s] ft_isalpha.c\n", tester(test_isalpha));
	printf("[%s] ft_isalnum.c\n", tester(test_isalnum));
	printf("[%s] ft_isdigit.c\n", tester(test_isdigit));
	printf("[%s] ft_isprint.c\n", tester(test_isprint));
	printf("[%s] ft_tolower.c\n", tester(test_tolower));
	printf("[%s] ft_toupper.c\n", tester(test_toupper));
	printf("[%s] ft_atoi.c\n", tester(test_atoi));
	printf("[%s] ft_strnstr.c\n", tester(test_strnstr));
}
