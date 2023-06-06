/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:27:21 by daviles-          #+#    #+#             */
/*   Updated: 2023/04/06 19:28:48 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//Iterates through the ’lst’ list and applies the ’f’ function to the contents 
//of each node. Create a list resulting from the correct and successive 
//application of the function 'f' on each node. The ’del’ function is used 
//to remove the contents of a node, if necessary.

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dst;
	t_list	*tmp;
	t_list	*node;

	if (!lst || !del || !f)
		return (NULL);
	dst = NULL;
	tmp = lst;
	while (tmp)
	{
		node = ft_lstnew(f(tmp->content));
		if (node == NULL)
		{
			ft_lstclear(&dst, del);
			return (NULL);
		}
		ft_lstadd_back(&dst, node);
		tmp = tmp->next;
	}
	return (dst);
}
/*
void	*my_toupper(void *str)
{
	int		c;
	char	*st;

	c = 0;
	st = (char *) str;
	while (st[c] != '\0')
	{
		if (st[c] >= 97 && st[c] <= 122)
			st[c] -= 32;
		c++;
	}
	return ((void *)st);
}

static void	del(void *lst)
{
	free(lst);
}

int	main(void)
{
	t_list	*lst1;
	t_list	*lst2;
	t_list	*lst3;
	t_list	*tmp;

	lst1 = ft_lstnew((char *) "Mientras llovia en Macondo");
	lst2 = ft_lstnew((char *) "Fuera de este mundo");
	lst3 = ft_lstnew((char *) "Maravillas de Wonder");
	lst1->next = lst2;
	lst2->next = lst3;
	printf("%s\n", lst1->content);
	tmp = ft_lstmap(lst1, &my_toupper, &del);
	while (tmp)
	{
		printf("%s\n", tmp->content);
		 tmp = tmp->next;
	}
	return (0);	
}
*/
