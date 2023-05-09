/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:31:08 by joestrad          #+#    #+#             */
/*   Updated: 2023/02/10 12:27:56 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief 			This function does the initial movements to get the stack a
 * 					sorted. It calculates the value of the middle index of the
 * 					stack a (the half of it's size), then pushes to stack b the
 * 					values that are greater and sends to the bottom of the stack a
 * 					(rotating the stack a) those which are lower 
 * 
 * @param stack_a 	The stack a
 * @param stack_b 	The stack b
 * @param s_sa 		The size of the stack a
 */
void	ft_initial_movs(t_lst_int **stack_a, t_lst_int **stack_b, int s_sa)
{
	int	mid_index;
	int	counter;

	mid_index = s_sa / 2;
	counter = 0;
	while (counter < s_sa)
	{
		if (ft_get_first_index(*stack_a) > mid_index)
			ft_make_push_b(stack_a, stack_b);
		else
			ft_make_rotate_a(stack_a);
		counter++;
	}
}

/**
 * @brief 			This function does the double rotate or reverse rotate of 
 * 					the stacks, if both cost (cost of rotate stack a and cost of
 * 					rotate stack b) are positive, the function does a rr
 * 					operation on both stacks (double rotate), otherwise it does
 *					a double reverse rotate, or rrr operation
 * 					
 * @param stack_a 	The stack a
 * @param stack_b 	The stack b
 * @param cst 		A pointer to the struct that contains the cost of the
 * 					movement
 */
void	ft_make_dbl_movs(t_lst_int **stack_a, t_lst_int **stack_b, t_cost *cst)
{
	while (cst->cost_sa < 0 && cst->cost_sb < 0)
	{
		ft_make_dbl_rev_rotate(stack_a, stack_b);
		cst->cost_sa++;
		cst->cost_sb++;
	}
	while (cst->cost_sa > 0 && cst->cost_sb > 0)
	{
		ft_make_dbl_rotate(stack_a, stack_b);
		cst->cost_sa--;
		cst->cost_sb--;
	}
}

/**
 * @brief 			This function does the rotate or reverse rotate of the
 * 					stacks, if the cost (cost of rotate a stack) is positive,
 * 					the function does a rotate on the oportune stack (ra/rb
 * 					operation), otherwise it does a reverse rotate to the stack
 * 					(rra/rrb operation)
 * 
 * @param stack_a 	The stack a
 * @param stack_b 	The stack b
 * @param cst 		A pointer to the struct that contains the cost of the
 * 					movement
 */
void	ft_make_movs(t_lst_int **stack_a, t_lst_int **stack_b, t_cost *cst)
{
	ft_make_dbl_movs(stack_a, stack_b, cst);
	while (cst->cost_sa < 0)
	{
		ft_make_rev_rotate_a(stack_a);
		cst->cost_sa++;
	}
	while (cst->cost_sa > 0)
	{
		ft_make_rotate_a(stack_a);
		cst->cost_sa--;
	}
	while (cst->cost_sb < 0)
	{
		ft_make_rev_rotate_b(stack_b);
		cst->cost_sb++;
	}
	while (cst->cost_sb > 0)
	{
		ft_make_rotate_b(stack_b);
		cst->cost_sb--;
	}
}

/**
 * @brief 				This function does the final rotate of the stack a. The
 * 						stack is ordered, but maybe it is rotated: this means
 * 						that the lower value isn't at the top of the stack. If
 * 						the top value is lower than the medium index, it will 
 * 						take less moves if we reverse rotate the stack to get
 * 						the lower value of the stack at the top of it, in other
 * 						way we must do rotate operations to get the lower value
 * 						at the top of stack a
 * 
 * @param stack_a 		The stack a
 * @param size 			The size of the stack a
 */
void	ft_rotate_stack(t_lst_int **stack_a, int size)
{
	int	top;

	top = ft_get_first_index(*stack_a);
	if (top < size / 2)
	{
		while (top > 1)
		{
			ft_make_rev_rotate_a(stack_a);
			top--;
		}
	}
	else
	{
		while (top <= size)
		{
			ft_make_rotate_a(stack_a);
			top++;
		}
	}
}
