/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:49:16 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/08 16:08:03 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

char	*strtrim(const char *s, const char *set)
{
	char	*new;
	size_t	start;
	size_t	end;

	if (!s || !set)
		return (NULL);
	start = 0;
	while (s[start] && strchr(set, s[start]))
		start++;
	if (s[start])
	{
		end = strlen(s + start) + start;
		while (strchr(set, s[end - 1]))
			end--;
	}
	else
		end = start;
	new = substr(s, start, end - start);
	return (new);
}
