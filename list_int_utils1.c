/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_int_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:11:42 by joestrad          #+#    #+#             */
/*   Updated: 2023/01/24 14:04:51 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief 				This function creates a new integer list with a value
 * 						and an index given
 * 
 * @param value 		Value of the node to be inserted
 * @param index 		Index of the value if the values were sorted
 * @return t_lst_int* 	The new list just created
 */
t_lst_int	*ft_lst_int_new(int *value, int *index)
{
	t_lst_int	*node;

	node = (t_lst_int *)malloc(sizeof(t_lst_int));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

/**
 * @brief 			This function prints the values of the elements of the list
 * 
 * @param lst 		The list which values are to be printed
 */
void	ft_lst_int_print_v(t_lst_int *lst)
{
	while (lst)
	{
		ft_putnbr_fd(*lst->value, 1);
		lst = lst->next;
		ft_putchar_fd(' ', 1);
	}
	ft_putstr_fd("\n", 1);
}

/**
 * @brief 			This function prints the index of the elements of the list
 * 
 * @param lst 		The list which index of the values are to be printed
 */
void	ft_lst_int_print_i(t_lst_int *lst)
{
	while (lst)
	{
		ft_putnbr_fd(*lst->index, 1);
		lst = lst->next;
		ft_putchar_fd(' ', 1);
	}
	ft_putstr_fd("\n", 1);
}

/**
 * @brief 			This function checks if a number is in the list or not
 * 
 * @param nbr 		The number to check if it is in the list
 * @param lst 		The list to where check
 * @return int 		The return value: 1 if the number is in the list, 0 if not
 */
int	ft_num_is_in_lst_int(int nbr, t_lst_int *lst)
{
	t_lst_int	*node;

	node = lst;
	while (node)
	{
		if (nbr == *node->value)
			return (1);
		node = node->next;
	}
	return (0);
}

/**
 * @brief 		This function adds a node to the end of a list of integers
 * 
 * @param lst 	The list in where we want to add the node
 * @param new 	The node to be inserted
 */
void	ft_lst_int_add_back(t_lst_int **lst, t_lst_int *new)
{
	t_lst_int	*node;

	node = *lst;
	if (node == NULL)
		*lst = new;
	else
	{
		while (node->next != NULL)
			node = node->next;
		new->prev = node;
		node->next = new;
	}
}
