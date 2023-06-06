/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:15:36 by daviles-          #+#    #+#             */
/*   Updated: 2023/04/06 19:27:28 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//iterates the ’lst’ list and applies the ’f’ function on the content of 
//each node.

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
/*
void ft_putstr(void *st)
{
	int i;
	char *str;

	i = 0;
	str = (char *) st;
	while (str[i])
		printf("%c\n", str[i++]);
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

	ft_lstiter(head, &ft_putstr);
	//printlist(head);
}
*/
