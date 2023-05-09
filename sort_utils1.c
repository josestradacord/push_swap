/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:05:20 by joestrad          #+#    #+#             */
/*   Updated: 2023/02/09 14:58:20 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief 			This function checks if a stack of integer values is
 * 					ordered or not
 * 
 * @param stack 	The stack to check
 * @return int 		The return value: 1 if the stack is ordered, 0 otherwise
 */
int	ft_stack_is_sorted(t_lst_int **stack)
{
	t_lst_int	*node;

	node = *stack;
	while (node->next)
	{
		if (*node->index > *node->next->index)
			return (0);
		else
			node = node->next;
	}
	return (1);
}

/**
 * @brief 			This function sorts the stack_a which size is 3 elements
 * 
 * @param stack 	The stack to sort
 */
void	ft_sort_lst_size_3(t_lst_int **stack)
{
	int	first;
	int	medium;
	int	last;

	first = ft_get_first_index(*stack);
	medium = ft_get_medium_index(*stack);
	last = ft_get_last_index(*stack);
	if (ft_stack_is_sorted(stack))
		return ;
	if (first < medium && first < last)
	{
		ft_make_swap_a(*stack);
		ft_make_rotate_a(stack);
	}
	else if (first > medium && first > last && medium < last)
		ft_make_rotate_a(stack);
	else if (first > medium && medium < last)
		ft_make_swap_a(*stack);
	else if (first < medium && medium > last)
		ft_make_rev_rotate_a(stack);
	else
	{
		ft_make_swap_a(*stack);
		ft_make_rev_rotate_a(stack);
	}
}

/**
 * @brief 			This function pushes to stack_b two elements of the stack_a
 * 
 * @param stack_a 	The stack_a
 * @param stack_b 	The stack_b
 */
void	ft_make_initial_push_b(t_lst_int **stack_a, t_lst_int **stack_b)
{
	int	index;
	int	size_a;

	index = 1;
	if (ft_get_last_index(*stack_a) == 1)
		ft_make_rev_rotate_a(stack_a);
	size_a = ft_lst_int_size(*stack_a);
	while (ft_get_first_index(*stack_a) > (size_a / 2))
		ft_make_rotate_a(stack_a);
	while (index <= (size_a - 3))
	{
		ft_make_push_b(stack_a, stack_b);
		index++;
	}
}

/**
 * @brief 			This function rotates the stack_a stack until its first
 * 					(or top) element is higher than the top of stack_b 
 * 					(passed as the argument value), then push the top of the
 * 					stack a to the stack b and finally does the reverse rotate
 * 					of the stack a to get the stack sorted again (the function
 * 					counts the number of rotate operations so it can does the
 * 					correct reverse operations)
 * 
 * @param s_a 		The stack_a
 * @param s_b 		The stack_b
 * @param value 	The stack_b's top value
 */
void	ft_make_rots_stack_a(t_lst_int **s_a, t_lst_int **s_b, int value)
{
	int	n_rot;

	n_rot = 0;
	while (value > ft_get_first_index(*s_a))
	{
		ft_make_rotate_a(s_a);
		n_rot++;
	}
	ft_make_push_a(s_a, s_b);
	while (n_rot > 0)
	{
		ft_make_rev_rotate_a(s_a);
		n_rot--;
	}
}

/**
 * @brief 			This function sorts a stack of at maximum five elements,
 * 					using the stacks stack_a and stack_b
 * 
 * @param stack_a 	The first stack, stack_a
 * @param stack_b 	The second stack, stack_b
 */
void	ft_sort_lst_size_5(t_lst_int **stack_a, t_lst_int **stack_b)
{
	int	index;
	int	size_b;
	int	value;

	ft_make_initial_push_b(stack_a, stack_b);
	ft_sort_lst_size_3(stack_a);
	index = 0;
	size_b = ft_lst_int_size(*stack_b);
	while (index < size_b)
	{
		if (ft_get_first_index(*stack_b) > ft_get_last_index(*stack_a))
		{
			ft_make_push_a(stack_a, stack_b);
			ft_make_rotate_a(stack_a);
		}
		else
		{
			value = ft_get_first_index(*stack_b);
			ft_make_rots_stack_a(stack_a, stack_b, value);
		}
		index++;
	}
}
