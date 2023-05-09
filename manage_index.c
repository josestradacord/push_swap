/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:55:17 by joestrad          #+#    #+#             */
/*   Updated: 2023/02/10 16:27:05 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief 			This function counts the number of elements of the given
 * 					list stack that are minors than the value given 
 * 
 * @param value 	The value to compare
 * @param stack 	The stack to check
 * @return int 		The number of elements of the list that are minors than the
 * 					given value
 */
int	ft_count_minors(int *value, t_lst_int **stack)
{
	t_lst_int	*node;
	int			minors;

	node = *stack;
	minors = 0;
	while (node)
	{
		if (*node->value < *value)
			minors++;
		node = node->next;
	}
	return (minors);
}

/**
 * @brief 			This function updates the index of each value of the given
 * 					list with the result of the ft_count_minors() function and
 * 					adds 1 to the result to start from the position 1 for the
 * 					index 
 * 
 * @param stack 	The stack that we want to update the index of its elements
 */
void	ft_update_index(t_lst_int **stack)
{
	t_lst_int	*node;

	node = *stack;
	while (node)
	{
		*node->index = ft_count_minors(node->value, stack) + 1;
		node = node->next;
	}
}

/**
 * @brief 			This function returns the first index of the stack
 * 
 * @param stack 	The stack
 * @return int 		The returned index
 */
int	ft_get_first_index(t_lst_int *stack)
{
	return (*stack->index);
}

/**
 * @brief 			This function returns the second index of the stack (the
 * 					medium index in a stack of three elements)
 * 
 * @param stack 	The stack
 * @return int 		The returned index
 */
int	ft_get_medium_index(t_lst_int *stack)
{
	return (*stack->next->index);
}

/**
 * @brief 			This function returns the last index of the stack
 * 
 * @param stack 	The stack
 * @return int 		The returned index
 */
int	ft_get_last_index(t_lst_int *stack)
{
	t_lst_int	*last;

	last = stack;
	while (last->next)
		last = last->next;
	return (*last->index);
}
