/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:33:07 by gbrochar          #+#    #+#             */
/*   Updated: 2015/12/02 16:17:18 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst_begin;
	t_list	*lst_new;

	lst_begin = ft_lstnew((f(lst))->content, (f(lst))->content_size);
	lst_new = lst_begin;
	lst = lst->next;
	while (lst->next)
	{
		lst_new->next = ft_lstnew((f(lst))->content, (f(lst))->content_size);
		lst_new = lst_new->next;
		lst = lst->next;
	}
	lst_new->next = ft_lstnew((f(lst))->content, (f(lst))->content_size);
	return (lst_begin);
}
