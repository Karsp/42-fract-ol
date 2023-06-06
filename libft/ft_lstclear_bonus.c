/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:45:51 by daviles-          #+#    #+#             */
/*   Updated: 2023/04/06 19:26:43 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//Removes and frees the given ’lst’ node and all consecutive nodes of that 
//node, using the ’del’ function and free(3). At the end, the pointer to the 
//list must be NULL.

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (*lst)
	{
		while ((*lst)->next)
		{
			tmp = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = tmp;
		}
		ft_lstdelone(*lst, del);
		*lst = NULL;
	}
}
/*
static void del(void *lst)
{
    free(lst);
}

void	printlist(t_list *head)
{
	if (!head)
		return ;
	printf("%s\n", (char *) head->content);
	printlist(head->next);
}

int	main(void)
{
	t_list *head;
	t_list *n1;
	t_list *n2;

	head = ft_lstnew((char *) "a");
	n1 = ft_lstnew((char *) "b");
	n2 = ft_lstnew((char *) "c");

	head->next = n1;
	n1->next = n2;
	printlist(head);
	ft_lstclear(&head, del);
	printlist(head);
}
*/
