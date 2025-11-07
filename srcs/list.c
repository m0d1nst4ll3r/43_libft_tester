/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:08:31 by rapohlen          #+#    #+#             */
/*   Updated: 2025/11/07 19:32:00 by rapohlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

void	lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;

	if (!f || !del)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		newnode = lstnew(f(lst->content));
		if (!newnode)
		{
			lstclear(&newlst, del);
			break ;
		}
		lstadd_back(&newlst, newnode);
		lst = lst->next;
	}
	return (newlst);
}

void	lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del)
		return ;
	del(lst->content);
	free(lst);
}

void	lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (!del)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		lstdelone(*lst, del);
		*lst = next;
	}
	*lst = NULL;
}
