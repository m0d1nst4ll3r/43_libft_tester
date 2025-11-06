#include "libft_tester.h"

static int	manual_test(void)
{
	char	*s1;
	char	*s2;
	int		res;

	s1 = ft_itoa(2147483647);
	s2 = itoa(2147483647);
	res = strcmp(s1, s2);
	free(s1);
	free(s2);
	s1 = ft_itoa(-2147483648);
	s2 = itoa(-2147483648);
	res = res || strcmp(s1, s2);
	free(s1);
	free(s2);
	s1 = ft_itoa(0);
	s2 = itoa(0);
	res = res || strcmp(s1, s2);
	free(s1);
	free(s2);
	return (res);
}

static int	random_test(void)
{
	int		n;
	int		i;
	char	*s1;
	char	*s2;
}

int	test_itoa(void)
{
	if (manual_test()
			|| random_test())
		return (1);
	return (0);
}
