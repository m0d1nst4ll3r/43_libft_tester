/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tester.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:07:18 by rapohlen          #+#    #+#             */
/*   Updated: 2025/10/23 17:36:13 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TESTER_H
# define LIBFT_TESTER_H

# define OK_STR				"\x1B[32mOK\033[0m"
# define KO_STR				"\x1B[31mKO\033[0m"

// # of tests to run for each loop
# define TEST_N				100

// global
# define NUL_TEST_FLOOR		0
# define NUL_TEST_CEIL		0
# define SML_TEST_FLOOR		0
# define SML_TEST_CEIL		10
# define MED_TEST_FLOOR		500
# define MED_TEST_CEIL		1000
# define BIG_TEST_FLOOR		10000
# define BIG_TEST_CEIL		100000

// ft_strstr
# define STRSTR_CHAR_FLOOR	'a'
# define STRSTR_CHAR_CEIL	'd'

// ft_is[...]
# define ISFUNC_FLOOR		-1
# define ISFUNC_CEIL		255

// ft_atoi
# define ATOI_FLOOR			0
# define ATOI_CEIL			100

# include "libft.h"

# include <stdlib.h>
# include <bsd/string.h>
# include <stdio.h>
# include <ctype.h>

// tester
char	*tester(int (*f)(void));

// util
int		rand_range(int a, int b);
void	fill_str(char *s, int len, unsigned char lower, unsigned char upper);

// error
void	malloc_error(void);

// tester funcs
int		test_isascii(void);
int		test_isalnum(void);
int		test_isalpha(void);
int		test_isdigit(void);
int		test_isprint(void);
int		test_tolower(void);
int		test_toupper(void);
int		test_atoi(void);
int		test_strnstr(void);

#endif
