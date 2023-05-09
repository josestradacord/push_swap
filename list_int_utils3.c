/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_int_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:47:21 by joestrad          #+#    #+#             */
/*   Updated: 2023/02/09 14:51:35 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief 				This function searches a node in an unordered integer's
 * 						list to	locate the parameter's position in that list,
 *						the search is done from the begining of the list (or top
 *						of the stack)
 * 
 * @param stack 		The stack to search in
 * @param value 		The value of the index (or position) in the list
 * @return int 			The number of necesary movements that are necesary to
 * 						do in the list to get the value on the top of the list,
 * 						these movements are rotations
 */
int	ft_search_from_top(t_lst_int *stack, int value)
{
	t_lst_int	*node;
	int			res;

	node = stack;
	res = 0;
	if (!node)
		return (res);
	else
	{
		while (node)
		{
			if (*(node->index) != value)
				res++;
			else
				return (res);
			node = node->next;
		}
		return (res);
	}
}

/**
 * @brief 				This function searches a node in an unordered integer's
 * 						list to	locate the parameter's position in that list,
 *						the search is done from	end of the list (or top of 
 *						the stack)
 *
 * @param stack 		The stack to search in
 * @param value 		The value of the index (or position) in the list
 * @return int  		The number of necesary movements that are necesary to
 * 						do in the list to get the value on the top of the
 * 						list, these movements are reverse rotations
 */
int	ft_search_from_bottom(t_lst_int *stack, int value)
{
	t_lst_int	*node;
	int			res;
	int			size;

	node = stack;
	res = 0;
	if (!node)
		return (res);
	else
	{	
		size = ft_lst_int_size(stack);
		return (size - ft_search_from_top(stack, value));
	}
}

/**
 * @brief 			This functions rotate the stack if it isn´t ordered
 * 
 * @param stack 	The stact to rotate
 * @return int 		The numbers of rotatios needed to get the stack sorted
 */
int	ft_n_rotate(t_lst_int **stack)
{
	int	n_rots;
	int	first;
	int	last;

	n_rots = 0;
	first = ft_get_first_index(*stack);
	last = ft_get_last_index(*stack);
	while (first > last)
	{
		n_rots++;
		ft_rotate(stack);
		first = ft_get_first_index(*stack);
		last = ft_get_last_index(*stack);
	}
	return (n_rots);
}

/**
 * @brief 				This function searches a node in an ordered integer's
 * 						list to	locate the parameter's position in that list,
 *						so the list stays ordered, the search is done from the
 *						begining of the list (or top of the stack)
 * 
 * @param stack 		The stack to search in
 * @param value 		The value to place in the list
 * @return int 			The number of necesary movements that are necesary to
 * 						do in the list to place the value on the top of the list,
 * 						that place has to be the one that keeps the list ordered,
 * 						these movements are rotations
 */
int	ft_place_from_top(t_lst_int *stack, int value)
{
	t_lst_int	*node;
	int			res;
	int			rot2sort;

	node = stack;
	res = 0;
	if (!node)
		return (res);
	else
	{
		rot2sort = ft_n_rotate(&stack);
		node = stack;
		res = rot2sort;
		while (node)
		{
			if (*(node->index) > value)
				break ;
			else
				res++;
			node = node->next;
		}
		while (rot2sort--)
			ft_revrotate(&stack);
		return (res);
	}
}

/**
 * @brief 				This function searches a node in an ordered integer's
 * 						list to	locate the parameter's position in that list,
 *						so the list stays ordered, the search is done from the
 *						end of the list (or bottom of the stack)
 * 
 * @param stack 		The stack to search in
 * @param value 		The value to place in the list
 * @return int 			The number of necesary movements that are necesary to
 * 						do in the list to place the value on the top of the list,
 * 						that place has to be the one that keeps the list ordered,
 * 						these movements are  reverse rotations
 */
int	ft_place_from_bottom(t_lst_int *stack, int value)
{
	t_lst_int	*node;
	int			res;
	int			size;

	node = stack;
	res = 0;
	if (!node)
		return (res);
	else
	{
		size = ft_lst_int_size(stack);
		return (size - ft_place_from_top(stack, value));
	}
}
