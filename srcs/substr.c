/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:42:16 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/07 19:27:34 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

char	*substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && i < start)
		i++;
	if (i < start)
		return (NULL);
	new = malloc(strlen(s + start) + 1);
	if (!new)
		return (new);
	i = 0;
	while (s[start + i] && i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = 0;
	return (new);
}
