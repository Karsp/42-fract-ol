/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 00:06:31 by daviles-          #+#    #+#             */
/*   Updated: 2023/04/06 19:22:49 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
//Create a new node using malloc(3). The ’content’ member variable is 
//initialized with the content of the ’content’ parameter. The variable 'next', 
//with NULL.

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *) malloc (sizeof (t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
/*
int	main(void)
{
	t_list	*list;
	void	*content;

	content = "Hlaosa";
	list = ft_lstnew(content);
	printf("%s\n", list->content);
	return (0);
}
*/
