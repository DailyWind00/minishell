/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:50:26 by vsoltys           #+#    #+#             */
/*   Updated: 2023/10/23 15:10:41 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !del)
		return ;
	tmp = *lst;
	tmp2 = *lst;
	while (tmp)
	{
		tmp2 = tmp2->next;
		del(tmp->content);
		free(tmp);
		tmp = tmp2;
	}
	*lst = 0;
}
