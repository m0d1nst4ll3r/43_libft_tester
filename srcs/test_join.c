#include "libft_tester.h"

static int	random_test_n(char *s1, int lower, int upper)
{
	int		i;
	int		n;
	int		res;
	char	*s2;
	char	*s3;
	char	*s4;

	i = 0;
	while (i < TEST_N)
	{
		n = rand_range(lower, upper);
		s2 = malloc(n + 1);
		if (!s2)
		{
			free(s1);
			malloc_error();
		}
		fill_str(s2, n, 1, UCHAR_MAX);
		s3 = ft_strjoin(s1, s2);
		s4 = strjoin(s1, s2);
		res = strcmp(s3, s4);
		free(s2);
		free(s3);
		free(s4);
		if (res)
			return (1);
		i++;
	}
	return (0);
}

static int	random_test(void)
{
	int		i;
	int		n;
	int		res;
	char	*s1;

	i = 0;
	while (i < TEST_N)
	{
		n = rand_range(lower, upper);
		s1 = malloc(n + 1);
		if (!s1)
			malloc_error();
		fill_str(s1, n, 1, UCHAR_MAX);
		res = random_test_n(s1, NUL_TEST_FLOOR, NUL_TEST_CEIL)
			|| random_test_n(s1, SML_TEST_FLOOR, SML_TEST_CEIL)
			|| random_test_n(s1, MED_TEST_FLOOR, MED_TEST_CEIL)
			|| random_test_n(s1, BIG_TEST_FLOOR, BIG_TEST_CEIL);
		free(s1);
		if (res)
			return (1);
		i++;
	}
	return (0);
}

int	test_strjoin(void)
{
	if (random_test(NUL_TEST_FLOOR, NUL_TEST_FLOOR) 
			|| random_test(s1, SML_TEST_FLOOR, SML_TEST_CEIL)
			|| random_test(s1, MED_TEST_FLOOR, MED_TEST_CEIL)
			|| random_test(s1, BIG_TEST_FLOOR, BIG_TEST_CEIL))
		return (1);
	return (0);
}
