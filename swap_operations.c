/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:49:14 by joestrad          #+#    #+#             */
/*   Updated: 2023/02/13 11:26:46 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief 			This function swaps the two first elements of a given stack
 * 
 * @param stack 	The stack to swap the first two elements
 */
void	ft_swap(t_lst_int *stack)
{
	int	val_aux;
	int	ind_aux;

	if (ft_lst_int_size(stack) > 1)
	{
		val_aux = *stack->value;
		*stack->value = *stack->next->value;
		*stack->next->value = val_aux;
		ind_aux = *stack->index;
		*stack->index = *stack->next->index;
		*stack->next->index = ind_aux;
	}
}

/**
 * @brief 			This function does the swap operation in both stacks
 * 
 * @param stack_a 	One of the stack to swap elements
 * @param stack_b 	The other stack
 */
void	ft_dblswap(t_lst_int *stack_a, t_lst_int *stack_b)
{
	if ((ft_lst_int_size(stack_a) > 1) && ft_lst_int_size(stack_b) > 1)
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
	}
}

/**
 * @brief 			This function calls the ft_swap() function to do the swap
 * 					of the first two elements of the stack a, and writes the
 * 					name of the operation (sa) in the standard output
 * 
 * @param stack 	The stack a
 */
void	ft_make_swap_a(t_lst_int *stack)
{
	ft_swap(stack);
	ft_putstr_fd("sa\n", 1);
}

/**
 * @brief 			This function calls the ft_swap() function to do the swap
 * 					of the first two elements of the stack b, and writes the
 * 					name of the operation (sb) in the standard output
 * 
 * @param stack 	The stack a
 */
void	ft_make_swap_b(t_lst_int *stack)
{
	ft_swap(stack);
	ft_putstr_fd("sb\n", 1);
}

/**
 * @brief 			This function calls the ft_dblswap() function to do the
 * 					swap operation of both the stacks (a and b) and writes 
 * 					the name of the operation (ss) in the standard output
 * 
 * @param stack_a 	The stack a
 * @param stack_b 	The stack b
 */
void	ft_make_dbl_swap(t_lst_int *stack_a, t_lst_int *stack_b)
{
	ft_dblswap(stack_a, stack_b);
	ft_putstr_fd("ss\n", 1);
}
