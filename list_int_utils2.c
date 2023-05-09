/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_int_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:06:37 by joestrad          #+#    #+#             */
/*   Updated: 2023/01/25 12:05:29 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief 			This function removes a node of a list of integers
 * 
 * @param lst 		A pointer to the node which we want to remove
 * @param del 		A pointer to the remove function
 */
void	ft_lst_int_delone(t_lst_int *lst, void (*del)(void *))
{
	del(lst->value);
	del(lst->index);
	free(lst);
}

/**
 * @brief 			This function clears (removes of elements) of the
 * 					given list
 * 
 * @param lst 		The list to be cleared
 * @param del 		A pointer to the remove function
 */
void	ft_lst_int_clear(t_lst_int **lst, void (*del)(void *))
{
	t_lst_int	*node;

	while (*lst != NULL)
	{
		node = (*lst)->next;
		ft_lst_int_delone(*lst, del);
		*lst = node;
	}
	*lst = NULL;
}

/**
 * @brief 			This function adds a node, new, at the front of the
 * 					list lst and moves the pointer of the beggining of the
 * 					list to the new beggining, the node new
 * 
 * @param lst 		The list in which we want to add the node
 * @param new 		The node to be added to
 */
void	ft_lst_int_add_front(t_lst_int **lst, t_lst_int *new)
{
	new->next = *lst;
	(*lst)->prev = new;
	*lst = new;
}

/**
 * @brief 		This function returns the size of a list of integers
 * 
 * @param lst 	The list which size we want to know
 * @return int 	The size of the list, the number of elements
 */
int	ft_lst_int_size(t_lst_int *lst)
{
	int			size;
	t_lst_int	*node;

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
 * @brief 				This function returns the last element (or node) of a
 * 						list of integers (without changing the list)
 * 
 * @param lst 			The list of integers from which we want to return the
 * 						last of its elements
 * @return t_lst_int* 	A pointer to the node of the last element of the list
 */
t_lst_int	*ft_lst_int_last(t_lst_int *lst)
{
	t_lst_int	*node;

	node = lst;
	if (node == NULL)
		return (node);
	while (node->next != NULL)
		node = node->next;
	return (node);
}
