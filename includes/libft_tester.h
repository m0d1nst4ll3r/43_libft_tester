/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tester.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:07:18 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/08 18:34:09 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TESTER_H
# define LIBFT_TESTER_H

# ifndef BONUS
#  define BONUS				1
# endif

# define KRED				"\x1B[31m"
# define KGRN				"\x1B[32m"
# define KMAG				"\x1B[35m"
# define KRES				"\033[0m"

# define OK_STR				KGRN "OK" KRES
# define KO_STR				KRED "KO" KRES

// # of tests to run for each loop
// More = more thorough, but slower, esp for valgrind
# define TEST_N				40

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

# include <time.h>
# include <bsd/string.h>
# include <string.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <ctype.h>
// For termux
# include <strings.h>

# include "libft.h"

// s1, s2, s3		sent to tested functions
// res, res2		used to sum up multiple tests mostly in manual tests
// n, n2, n3, n4	either sent to tested func or used for s1, s2...
// i, i2, i3		used as iterators in test funcs
// ft_res, tab		return of the tested funcs
// of_res, tab		return of the official funcs
// ft_list			list made with tested funcs
// of_list			list made with official funcs
typedef struct	s_tester
{
	char	*s1;
	char	*s2;
	char	*s3;
	int		res;
	int		res2;
	int		n;
	int		n2;
	int		n3;
	int		n4;
	int		i;
	int		i2;
	int		i3;
	char	*ft_res;
	char	*of_res;
	char	**ft_res_tab;
	char	**of_res_tab;
	t_list	*ft_list;
	t_list	*of_list;
}t_tester;

// tester
char	*tester(t_tester *dat, int (*f)(t_tester *dat));

// util
int		rand_range(int a, int b);
void	fill_str(char *s, int len, unsigned char lower, unsigned char upper);
int		min(int a, int b);
int		strscmp(char **tab1, char **tab2);
void	list_free_func(void *p);

// init
void	init_malloc(t_tester *dat);
void	init_null(t_tester *dat);

// free
void	free_null(char **p);
void	free_tab(char ***tab);
void	free_all(t_tester *dat);

// recoded functions
char	*itoa(int n);
char	**strsplit(const char *s, char c);
char	*substr(const char *s, unsigned int start, size_t len);
char	*strjoin(const char *s1, const char *s2);
char	*strtrim(const char *s1, const char *s2);

// list recoded funcs
void	lstiter(t_list *lst, void (*f)(void *));
t_list	*lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	lstdelone(t_list *lst, void (*del)(void *));
void	lstclear(t_list **lst, void (*del)(void *));
int		lstsize(t_list *lst);
t_list	*lstnew(void *content);
t_list	*lstlast(t_list *lst);
void	lstadd_front(t_list **list, t_list *new);
void	lstadd_back(t_list **lst, t_list *new);
// more to come

// error
void	malloc_error(t_tester *dat);

// tester funcs
int		test_isascii(t_tester *dat);
int		test_isalnum(t_tester *dat);
int		test_isalpha(t_tester *dat);
int		test_isdigit(t_tester *dat);
int		test_isprint(t_tester *dat);
int		test_tolower(t_tester *dat);
int		test_toupper(t_tester *dat);
int		test_atoi(t_tester *dat);
int		test_strnstr(t_tester *dat);
int		test_bzero(t_tester *dat);
int		test_memset(t_tester *dat);
int		test_memchr(t_tester *dat);
int		test_strchr(t_tester *dat);
int		test_strrchr(t_tester *dat);
int		test_memcpy(t_tester *dat);
int		test_strlcpy(t_tester *dat);
int		test_strlen(t_tester *dat);
int		test_memcmp(t_tester *dat);
int		test_strncmp(t_tester *dat);
int		test_memmove(t_tester *dat);
int		test_strdup(t_tester *dat);
int		test_strlcat(t_tester *dat);
int		test_calloc(t_tester *dat);
int		test_itoa(t_tester *dat);
int		test_strjoin(t_tester *dat);
int		test_substr(t_tester *dat);
int		test_split(t_tester *dat);
int		test_strtrim(t_tester *dat);
int		test_striteri(t_tester *dat);
int		test_strmapi(t_tester *dat);
int		test_lstnew(t_tester *dat);

#endif
