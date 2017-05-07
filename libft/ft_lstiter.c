/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:38:16 by gbrochar          #+#    #+#             */
/*   Updated: 2015/12/04 16:41:19 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*start;
	t_list	*tmp;

	start = lst;
	while (lst->next)
	{
		tmp = lst;
		f(lst);
		lst = tmp->next;
	}
	f(lst);
	lst = start;
}
