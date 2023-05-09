/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:49:22 by joestrad          #+#    #+#             */
/*   Updated: 2023/02/10 16:40:26 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief 			This function push the top element of the stack b and puts
 * 					it on the top of the stack a, removing it from the stack b,
 * 					if there is an element on the top of the stack b, otherwise
 * 					the function does nothing
 * 
 * @param stack_a 	The stack a
 * @param stack_b 	The stack b
 */
void	ft_push_a(t_lst_int **stack_a, t_lst_int **stack_b)
{
	t_lst_int	*node;

	if (ft_lst_int_size(*stack_b) > 0)
	{
		node = *stack_b;
		*stack_b = node->next;
		if ((*stack_b))
			(*stack_b)->prev = NULL;
		node->next = *stack_a;
		if (ft_lst_int_size(*stack_a) == 0)
		{
			*stack_a = node;
			(*stack_a)->next = NULL;
			(*stack_a)->prev = NULL;
		}
		else
		{
			(*stack_a)->prev = node;
			*stack_a = node;
			(*stack_a)->prev = NULL;
		}
	}
}

/**
 * @brief 			This function push the top element of the stack a and puts
 * 					it on the top of the stack b, removing it from the stack a,
 * 					if there is an element on the top of the stack a, otherwise
 * 					the function does nothing
 * 
 * @param stack_a 	The stack a
 * @param stack_b 	The stack b
 */
void	ft_push_b(t_lst_int **stack_a, t_lst_int **stack_b)
{
	t_lst_int	*node;

	if (ft_lst_int_size(*stack_a) > 0)
	{
		node = *stack_a;
		*stack_a = node->next;
		if ((*stack_a))
			(*stack_a)->prev = NULL;
		node->next = *stack_b;
		if (ft_lst_int_size(*stack_b) == 0)
		{
			*stack_b = node;
			(*stack_b)->next = NULL;
			(*stack_b)->prev = NULL;
		}
		else
		{
			(*stack_b)->prev = node;
			*stack_b = node;
			(*stack_b)->prev = NULL;
		}
	}
}

/**
 * @brief 			This function calls the ft_push_a() function to do the push
 * 					of the top of the stack b on top of the stack a and writes
 * 					the name of the operation (pa) in the standard output
 * 
 * @param stack_a 	The stack a
 * @param stack_b 	The stack b
 */
void	ft_make_push_a(t_lst_int **stack_a, t_lst_int **stack_b)
{
	ft_push_a(stack_a, stack_b);
	ft_putstr_fd("pa\n", 1);
}

/**
 * @brief 			This function calls the ft_push_b() function to do the push
 * 					of the top of the stack a on top of the stack b and writes
 * 					the name of the operation (pb) in the standard output
 * 
 * @param stack_a 	The stack a
 * @param stack_b 	The stack b
 */
void	ft_make_push_b(t_lst_int **stack_a, t_lst_int **stack_b)
{
	ft_push_b(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
