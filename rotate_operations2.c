/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:14:23 by joestrad          #+#    #+#             */
/*   Updated: 2023/02/13 11:21:46 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief 			This function calls the ft_rotate() function to do the
 * 					rotate of the stack b and writes the name of the operation
 * 					(rb) in the standard output
 * 
 * @param stack 	The stack to rotate
 */
void	ft_make_rotate_b(t_lst_int **stack)
{
	ft_rotate(stack);
	ft_putstr_fd("rb\n", 1);
}

/**
 * @brief 			This function calls the ft_dblrotate() function to do the
 * 					rotate of both the stacks (a and b) and writes the name of 
 * 					the operation (rr) in the standard output
 * 
 * @param stack_a 	The stack a
 * @param stack_b 	The stack b
 */
void	ft_make_dbl_rotate(t_lst_int **stack_a, t_lst_int **stack_b)
{
	ft_dblrotate(stack_a, stack_b);
	ft_putstr_fd("rr\n", 1);
}

/**
 * @brief  			This function calls the ft_revrotate() function to do the
 * 					rotate of the stack a and writes the name of the operation
 * 					(rra) in the standard output
 * 
 * @param stack 	The stack a
 */
void	ft_make_rev_rotate_a(t_lst_int **stack)
{
	ft_revrotate(stack);
	ft_putstr_fd("rra\n", 1);
}

/**
 * @brief  			This function calls the ft_revrotate() function to do the
 * 					rotate of the stack b and writes the name of the operation
 * 					(rrb) in the standard output
 * 
 * @param stack 	The stack b
 */
void	ft_make_rev_rotate_b(t_lst_int **stack)
{
	ft_revrotate(stack);
	ft_putstr_fd("rrb\n", 1);
}

/**
 * @brief 			This function calls the ft_dblrevrotate() function to do 
 * 					the reverse rotate of both the stacks (a and b) and writes 
 * 					the name of the operation (rrr) in the standard output
 * 
 * @param stack_a 	The stack a
 * @param stack_b 	The stack b
 */
void	ft_make_dbl_rev_rotate(t_lst_int **stack_a, t_lst_int **stack_b)
{
	ft_dblrevrotate(stack_a, stack_b);
	ft_putstr_fd("rrr\n", 1);
}
