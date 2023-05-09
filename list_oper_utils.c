/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_oper_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:58:58 by joestrad          #+#    #+#             */
/*   Updated: 2023/02/14 17:59:50 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * @brief 				This function creates a new node of a operations' list
 * 
 * @param oper 			The operation to add
 * @return t_lst_oper* 	A pointer to the just created node
 */
t_lst_oper	*ft_lst_oper_new(char *oper)
{
	t_lst_oper	*node;

	node = (t_lst_oper *)malloc(sizeof(t_lst_oper));
	if (!node)
		return (NULL);
	node->inst = oper;
	node->next = NULL;
	return (node);
}

/**
 * @brief 		This function adds a node to the end of a list of operations
 * 
 * @param lst 	The list in where we want to add the node
 * @param new 	The node to be inserted
 */
void	ft_lst_oper_add_back(t_lst_oper **lst, t_lst_oper *new)
{
	t_lst_oper	*node;

	node = *lst;
	if (node == NULL)
		*lst = new;
	else
	{
		while (node->next != NULL)
			node = node->next;
		node->next = new;
	}
}

/**
 * @brief 		This function returns the size of a list of operations
 * 
 * @param lst 	The list which size we want to know
 * @return int 	The size of the list, the number of elements
 */
int	ft_lst_oper_size(t_lst_oper *lst)
{
	int			size;
	t_lst_oper	*node;

	size = 0;
	node = lst;
	while (node != NULL)
	{
		size++;
		node = node->next;
	}
	return (size);
}

/**
 * @brief 			This function removes a node of a list of operations
 * 
 * @param lst 		A pointer to the node which we want to remove
 * @param del 		A pointer to the remove function
 */
void	ft_lst_oper_delone(t_lst_oper *lst, void (*del)(void *))
{
	del(lst->inst);
	free(lst);
}

/**
 * @brief 			This function clears (removes of elements) of the
 * 					given list
 * 
 * @param lst 		The list to be cleared
 * @param del 		A pointer to the remove function
 */
void	ft_lst_oper_clear(t_lst_oper **lst, void (*del)(void *))
{
	t_lst_oper	*node;

	while (*lst != NULL)
	{
		node = (*lst)->next;
		ft_lst_oper_delone(*lst, del);
		*lst = node;
	}
	*lst = NULL;
}
