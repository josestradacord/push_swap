/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:23:09 by joestrad          #+#    #+#             */
/*   Updated: 2023/02/13 11:17:37 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief 			This function rotate the given stack, so the first
 * 					element becomes the last, the second becomes the first, ...
 * 					and so on, if the stack has more than one element
 * 
 * @param stack 	The stack to rotate
 */
void	ft_rotate(t_lst_int **stack)
{
	t_lst_int	*first;
	t_lst_int	*last;

	if (ft_lst_int_size(*stack) > 1)
	{
		first = *stack;
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = first;
		(*stack)->prev = last;
		first->next->prev = NULL;
		*stack = first->next;
		first->next = NULL;
	}
}

/**
 * @brief 			This function does the rotate operation in both stacks
 * 
 * @param stack_a 	One of the stacks to rotate
 * @param stack_b 	The other stack to rotate
 */
void	ft_dblrotate(t_lst_int **stack_a, t_lst_int **stack_b)
{
	if ((ft_lst_int_size(*stack_a) > 1) && ft_lst_int_size(*stack_b) > 1)
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
}

/**
 * @brief 			This function reverse rotate the given stack, so the last
 * 					element becomes the first, the first becomes the second, ...
 * 					and so on, if the stack has more than one element
 * 
 * @param stack 
 */
void	ft_revrotate(t_lst_int **stack)
{
	t_lst_int	*first;
	t_lst_int	*penultimate;

	if (ft_lst_int_size(*stack) > 1)
	{
		first = *stack;
		penultimate = *stack;
		while (penultimate->next->next)
			penultimate = penultimate->next;
		*stack = penultimate->next;
		penultimate->next = NULL;
		(*stack)->prev = NULL;
		(*stack)->next = first;
		first->prev = *stack;
	}
}

/**
 * @brief 			This function does the reverse rotate in both stacks
 * 
 * @param stack_a 	One of the stacks to reverse rotate
 * @param stack_b 	The other stack to reverse rotate
 */
void	ft_dblrevrotate(t_lst_int **stack_a, t_lst_int **stack_b)
{
	if ((ft_lst_int_size(*stack_a) > 1) && ft_lst_int_size(*stack_b) > 1)
	{
		ft_revrotate(stack_a);
		ft_revrotate(stack_b);
	}
}

/**
 * @brief 			This function calls the ft_rotate() function to do the
 * 					rotate of the stack a and writes the name of the operation
 * 					(ra) in the standard output
 * 
 * @param stack 	The stack to rotate
 */
void	ft_make_rotate_a(t_lst_int **stack)
{
	ft_rotate(stack);
	ft_putstr_fd("ra\n", 1);
}
