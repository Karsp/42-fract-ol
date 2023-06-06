/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 12:31:44 by daviles-          #+#    #+#             */
/*   Updated: 2023/04/06 19:24:58 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//Add the ’new’ node to the end of the ’lst’ list.

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (new != 0)
	{
		if (*lst == 0)
		{
			*lst = new;
			(*lst)->next = NULL;
		}
		else
			ft_lstlast(*lst)->next = new;
	}
}
/*
int	main(void)
{
	t_list	**lst;
	t_list	*lst
	t_list	*lst2;
	t_list	*lst3;
	t_list	*lst4;

	lst1 = ft_lstnew("Rota y recompuesta");
	lst2 = ft_lstnew("Amanece que no es poco");
	lst3 = ft_lstnew("¡Pum para arriba!");
	lst4 = ft_lstnew("A vivir que son dos dias...");
	lst1->next = NULL;
	*lst = NULL;
	ft_lstadd_back(lst, lst1);
	printf("%s\n", ft_lstlast(*lst)->content);
	ft_lstadd_back(lst, lst2);
	printf("%s\n", ft_lstlast(*lst)->content);
	ft_lstadd_back(lst, lst3);
	printf("%s\n", ft_lstlast(*lst)->content);
	ft_lstadd_back(lst, lst4);
	printf("%s\n", ft_lstlast(*lst)->content);
	printf("%d\n", ft_lstsize(*lst));
	while (*lst)
	{
			printf("AAA%s\n", (*lst)->content);
		*lst = (*lst)->next;
	}
	return (0);
}
*/
