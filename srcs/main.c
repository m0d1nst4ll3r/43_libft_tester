/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:10:17 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/08 18:27:09 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

static void	test_bonus(t_tester *dat)
{
	printf("[%sBONUS%s]\n", KMAG, KRES);
	printf("[%s] ft_lstnew\n", tester(dat, test_lstnew));
	(void)dat;
}

static void	test_part1(t_tester *dat)
{
	printf("[%sPART1%s]\n", KMAG, KRES);
	printf("[%s] ft_isascii\n", tester(dat, test_isascii));
	printf("[%s] ft_isalpha\n", tester(dat, test_isalpha));
	printf("[%s] ft_isalnum\n", tester(dat, test_isalnum));
	printf("[%s] ft_isdigit\n", tester(dat, test_isdigit));
	printf("[%s] ft_isprint\n", tester(dat, test_isprint));
	printf("[%s] ft_tolower\n", tester(dat, test_tolower));
	printf("[%s] ft_toupper\n", tester(dat, test_toupper));
	printf("[%s] ft_atoi\n", tester(dat, test_atoi));
	printf("[%s] ft_strnstr\n", tester(dat, test_strnstr));
	printf("[%s] ft_bzero\n", tester(dat, test_bzero));
	printf("[%s] ft_memset\n", tester(dat, test_memset));
	printf("[%s] ft_memchr\n", tester(dat, test_memchr));
	printf("[%s] ft_strchr\n", tester(dat, test_strchr));
	printf("[%s] ft_strrchr\n", tester(dat, test_strrchr));
	printf("[%s] ft_memcpy\n", tester(dat, test_memcpy));
	printf("[%s] ft_strlcpy\n", tester(dat, test_strlcpy));
	printf("[%s] ft_strlen\n", tester(dat, test_strlen));
	printf("[%s] ft_memcmp\n", tester(dat, test_memcmp));
	printf("[%s] ft_strncmp\n", tester(dat, test_strncmp));
	printf("[%s] ft_memmove\n", tester(dat, test_memmove));
	printf("[%s] ft_strdup\n", tester(dat, test_strdup));
	printf("[%s] ft_strlcat\n", tester(dat, test_strlcat));
	printf("[%s] ft_calloc\n", tester(dat, test_calloc));
}

static void	test_part2(t_tester *dat)
{
	printf("[%sPART2%s]\n", KMAG, KRES);
	printf("[%s] ft_itoa\n", tester(dat, test_itoa));
	printf("[%s] ft_substr\n", tester(dat, test_substr));
	printf("[%s] ft_split\n", tester(dat, test_split));
	printf("[%s] ft_strjoin\n", tester(dat, test_strjoin));
	printf("[%s] ft_strtrim\n", tester(dat, test_strtrim));
	printf("[%s] ft_striteri\n", tester(dat, test_striteri));
	printf("[%s] ft_strmapi\n", tester(dat, test_strmapi));
}

int	main(void)
{
	t_tester	dat;

	srand(time(NULL));
	init_null(&dat);
	init_malloc(&dat);
	test_part1(&dat);
	test_part2(&dat);
	if (BONUS)
		test_bonus(&dat);
	free_all(&dat);
}
