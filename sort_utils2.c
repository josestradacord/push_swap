/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:29:07 by joestrad          #+#    #+#             */
/*   Updated: 2023/02/10 12:41:13 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief 			This function sorts the stack a (stack_a) of size_sa size
 * 					using the empty stack b (stack_b) as an auxiliary stack.
 * 					To do this, the function uses the radix sorting algorithm,
 * 					sorting the values of the stack_a by pasing they indexes
 * 					to binary and rotates stack_a if the digit is 1 and push it
 * 					to stack_b if the digit is 0
 * 					At the end stack_a has to be sorted (with the minor value
 * 					at the top) and stack_b has to be empty again 
 * 
 * @param stack_a 	The stack to sort
 * @param stack_b 	The auxiliary stack
 * @param size_a 	The stack_a's size
 */
void	ft_sort_lst_radix(t_lst_int **stack_a, t_lst_int **stack_b, int size_a)
{
	int	n_iter;
	int	digit;
	int	n_elems;

	n_iter = 0;
	digit = 0;
	while ((size_a >> n_iter) != 0)
		n_iter++;
	while (digit < n_iter)
	{
		n_elems = 0;
		while (size_a > n_elems)
		{
			if (((ft_get_first_index(*stack_a) >> digit) & 1) == 1)
				ft_make_rotate_a(stack_a);
			else
				ft_make_push_b(stack_a, stack_b);
			n_elems++;
		}
		while (ft_lst_int_size(*stack_b) > 0)
			ft_make_push_a(stack_a, stack_b);
		digit++;
	}
}

/**
 * @brief 			This function sorts the stack a (stack_a) of size_sa size
 * 					(greater than 5) using the empty stack b (stack_b) as an 
 * 					auxiliary stack. At the end stack_a has to be ordereded
 * 					(with the minor value at the top) and stack_b has to be
 * 					empty again. It uses an algorithm that chooses the value of
 * 					the stack b that is the best candidate to be moved to the
 * 					sorted stack a (first we push elements from stack a to stack
 * 					b until stack a has three elements, then we sort this three
 * 					elements), to do that it calculates the cost for each value
 * 					(or element) of the stack b
 * 
 * @param stack_a 	The stack to sort
 * @param stack_b 	The auxiliary stack
 * @param s_sa 		The stack_a's size
 */
void	ft_sort_lst_int(t_lst_int **stack_a, t_lst_int **stack_b, int s_sa)
{
	int		index;
	int		size_sb;
	int		size_sa;
	t_cost	*cost_mov;

	ft_initial_movs(stack_a, stack_b, s_sa);
	index = ft_lst_int_size(*stack_a);
	while (index > 3)
	{	
		ft_make_push_b(stack_a, stack_b);
		index--;
	}
	ft_sort_lst_size_3(stack_a);
	size_sb = ft_lst_int_size(*stack_b);
	size_sa = ft_lst_int_size(*stack_a);
	while (size_sb > 0)
	{
		cost_mov = ft_calc_cost(*stack_a, *stack_b, size_sa, size_sb);
		ft_make_movs(stack_a, stack_b, cost_mov);
		free(cost_mov);
		ft_make_push_a(stack_a, stack_b);
		size_sb--;
		size_sa++;
	}
	ft_rotate_stack(stack_a, s_sa);
}

/**
 * @brief 			This function sorts the stack a (stack_a) of size_sa size
 * 					using the empty stack b (stack_b) as an auxiliary stack.
 * 					At the end stack_a has to be sorted (with the minor value
 * 					at the top) and stack_b has to be empty again
 * 
 * @param stack_a 	The stack to sort
 * @param stack_b 	The auxiliary stack
 * @param size_sa 	The stack_a's size
 */
void	ft_sort_stack(t_lst_int **stack_a, t_lst_int **stack_b, int size_sa)
{
	if (size_sa == 2)
		ft_make_swap_a(*stack_a);
	else if (size_sa == 3)
		ft_sort_lst_size_3(stack_a);
	else if (size_sa <= 5)
		ft_sort_lst_size_5(stack_a, stack_b);
	else
		ft_sort_lst_int(stack_a, stack_b, size_sa);
}
