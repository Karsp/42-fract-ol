/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 12:09:51 by daviles-          #+#    #+#             */
/*   Updated: 2023/04/06 19:24:30 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//Returns the last node in the list.

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
int	main(void)
{
	t_list	**lst;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = ft_lstnew("En un café, se vieron por casualidad");
	node2 = ft_lstnew("Cansados en el alma de tanto andar");
	node3 = ft_lstnew("Ella tenia un clavel, en la mano.");
	*lst = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	printf("%s\n", (*lst)->content);
	printf("%s\n", ft_lstlast(*lst)->content);
	return (0);
}
*/
