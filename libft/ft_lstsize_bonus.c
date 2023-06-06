/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 00:54:45 by daviles-          #+#    #+#             */
/*   Updated: 2023/04/06 19:24:04 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//Counts the number of nodes in a list.

int	ft_lstsize(t_list *lst)
{
	int	c;

	c = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		c++;
	}
	return (c);
}
/*
int	main(void)
{
	t_list	**lst;
	t_list	*lst1;
	t_list	*lst2;
	t_list	*lst3;

	lst1 = ft_lstnew("Rota y recompuesta");
	lst2 = ft_lstnew("Amanece que no es poco");
	lst3 = ft_lstnew("¡Pum para arriba!");
	lst3->next = NULL;
	lst2->next = lst3;
	lst1->next = lst2;
	*lst = lst1;
	printf("%d\n", ft_lstsize(*lst));
	return (0);
}
*/
