/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 00:14:24 by daviles-          #+#    #+#             */
/*   Updated: 2023/04/06 19:23:31 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//Add the ’new’ node to the beginning of the ’lst’ list.

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list	**list;
	t_list	*node;
	t_list	*new;

	node = ft_lstnew("Hola");
	new = ft_lstnew("Adios");
	*list = node;
	printf("%s\n", (*list)->content);
	ft_lstadd_front(list, new);
	printf("%s\n", (*list)->content);
	printf("%s\n", (*list)->next->content);
	return (0);
}
*/
