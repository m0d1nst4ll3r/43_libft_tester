/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tester.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:07:18 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/04 16:05:51 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TESTER_H
# define LIBFT_TESTER_H

# ifndef BONUS
#  define BONUS				0
# endif

# define KRED				"\x1B[31m"
# define KGRN				"\x1B[32m"
# define KMAG				"\x1B[35m"
# define KRES				"\033[0m"

# define OK_STR				KGRN "\x1B[32mOK\033[0m" KRES
# define KO_STR				KRED "\x1B[31mKO\033[0m" KRES

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
# define BYTE_MIN			0
# define BYTE_MAX			UCHAR_MAX

// ft_strnstr, ft_strchr
# define STRSTR_CHAR_FLOOR	'a'
# define STRSTR_CHAR_CEIL	'd'

// ft_strchr, ft_strrchr
# define STRCHR_CHAR_FLOOR	'a'
# define STRCHR_CHAR_CEIL	'z'

// ft_memchr
# define MEMCHR_CHAR_FLOOR	0
# define MEMCHR_CHAR_CEIL	10

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
int		test_bzero(void);
int		test_memset(void);
int		test_memchr(void);
int		test_strchr(void);
int		test_strrchr(void);
int		test_memcpy(void);
int		test_strlcpy(void);

#endif
