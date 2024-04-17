/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:37:33 by vsoltys           #+#    #+#             */
/*   Updated: 2024/03/29 17:16:37 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env	*ft_lstnew_name(char *content)
{
	t_env	*lst;

	lst = (t_env *)malloc(sizeof(t_env));
	if (!lst)
		return (NULL);
	lst->name = ft_strdup(content);
	lst->value = NULL;
	lst->next = NULL;
	return (lst);
}

void	ft_envadd_back(t_env **lst, t_env *new)
{
	t_env	*ptr;

	if (lst && *lst)
	{
		ptr = *lst;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
		new->previous = ptr;
	}
	else if (lst)
		*lst = new;
}

t_env	*ft_envlast(t_env *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	free_env(t_env *env_list)
{
	t_env	*temp;

	while (env_list != NULL)
	{
		temp = env_list;
		free(temp->name);
		free(temp->value);
		env_list = env_list->next;
		free(temp);
	}
}
