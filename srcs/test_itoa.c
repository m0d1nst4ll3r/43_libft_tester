#include "libft_tester.h"

static void	manual_test_n(t_tester *dat, int n)
{
	dat->ft_res = ft_itoa(n);
	dat->of_res = itoa(n);
	if (!dat->ft_res || !dat->of_res)
		malloc_error(dat);
}

static int	manual_test(t_tester *dat)
{
	manual_test_n(dat, 2147483647);
	dat->res = strcmp(dat->ft_res, dat->of_res);
	free_null(&(dat->ft_res));
	free_null(&(dat->of_res));
	manual_test_n(dat, -2147483648);
	dat->res = dat->res || strcmp(dat->ft_res, dat->of_res);
	free_null(&(dat->ft_res));
	free_null(&(dat->of_res));
	manual_test_n(dat, 0);
	dat->res = dat->res || strcmp(dat->ft_res, dat->of_res);
	free_null(&(dat->ft_res));
	free_null(&(dat->of_res));
	manual_test_n(dat, 10);
	dat->res = dat->res || strcmp(dat->ft_res, dat->of_res);
	free_null(&(dat->ft_res));
	free_null(&(dat->of_res));
	manual_test_n(dat, -10);
	dat->res = dat->res || strcmp(dat->ft_res, dat->of_res);
	free_null(&(dat->ft_res));
	free_null(&(dat->of_res));
	return (dat->res);
}

static int	random_test(t_tester *dat, int lower, int upper)
{
	dat->i = 0;
	while (dat->i < TEST_N * 100)
	{
		dat->n = rand_range(lower, upper);
		dat->ft_res = ft_itoa(dat->n);
		dat->of_res = itoa(dat->n);
		if (!dat->ft_res || !dat->of_res)
			malloc_error(dat);
		dat->res = strcmp(dat->s1, dat->s2);
		free_null(&(dat->ft_res));
		free_null(&(dat->of_res));
		if (dat->res)
			return (1);
		dat->i++;
	}
	return (0);
}

int	test_itoa(t_tester *dat)
{
	if (manual_test(dat)
		|| random_test(dat, 0, INT_MAX)
		|| random_test(dat, INT_MIN, -1))
		return (1);
	return (0);
}
