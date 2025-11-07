/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:12:12 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/07 19:31:49 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

int	lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

t_list	*lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (new);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	lstadd_front(t_list **list, t_list *new)
{
	new->next = *list;
	*list = new;
}

void	lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
	else
		lstlast(*lst)->next = new;
}
