/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_costs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:03:15 by joestrad          #+#    #+#             */
/*   Updated: 2023/02/09 15:28:09 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief 			This functions returns the absolute value of the argument
 * 
 * @param nbr 		The number to calculate its absolute value
 * @return int 		The absolute value of the number
 */
int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return (nbr);
}

/**
 * @brief 				This function initializes the costs values for the stacks
 * 						(a and b) and the total cost
 * 
 * @return t_cost* 		A pointer to the struct that contains the initial costs
 */
t_cost	*ft_inic_cost(void)
{
	t_cost	*new;

	new = (t_cost *)malloc(sizeof(t_cost));
	if (!new)
		return (NULL);
	new->cost_sa = MAX_NUM;
	new->cost_sb = MAX_NUM;
	new->cost_tot = MAX_NUM;
	return (new);
}

/**
 * @brief 			This function calculates the cost of the movements that 
 * 					have to be done to the stack a to fit the value in the
 * 					correct position
 * 
 * @param stack 	The stack that contains the numbers and must accept the
 * 					value
 * @param value 	The value to be inserted in the stack
 * @param size_a 	The size of the stack a
 * @return int 		The numbers on movements that are necessary to be done
 */
int	ft_calc_cost_a(t_lst_int *stack, int value, int size_a)
{
	int	from_top;
	int	from_bot;

	from_top = ft_place_from_top(stack, value);
	from_bot = size_a - from_top;
	if (from_top <= from_bot)
		return (from_top);
	else
		return (-from_bot);
}

/**
 * @brief 			This function calculates the cost of the movements that 
 * 					have to be done to the stack b to fit the value in the
 * 					correct position
 * 
 * @param stack 	The stack that contains the numbers and must accept the
 * 					value
 * @param value 	The value to be inserted in the stack
 * @param size_b 	The size of the stack b
 * @return int 		The numbers on movements that are necessary to be done
 */
int	ft_calc_cost_b(t_lst_int *stack, int value, int size_b)
{
	int	from_top;
	int	from_bot;

	from_top = ft_search_from_top(stack, value);
	from_bot = size_b - from_top;
	if (from_top <= from_bot)
		return (from_top);
	else
		return (-from_bot);
}

/**
 * @brief 				This function calculates the costs of the movements
 * 						that have to be done to the stacks for each value of
 * 						the stack b to fit in the correct position in the 
 * 						stack a
 * 
 * @param stack_a 		The stack a
 * @param stack_b 		The stack b
 * @param sa 			The size of the stack a
 * @param sb 			The size of the stack b
 * @return t_cost* 		The costs of the movements, for each of the stacks (a 
 * 						negative number if they are reverse rotations) and the
 * 						total cost (the sum of the absolute values of both cost)
 */
t_cost	*ft_calc_cost(t_lst_int *stack_a, t_lst_int *stack_b, int sa, int sb)
{
	t_cost		*mov_cost;
	t_lst_int	*aux;
	int			aux_cost_a;
	int			aux_cost_b;
	int			aux_cost;

	aux = stack_b;
	mov_cost = ft_inic_cost();
	while (aux)
	{
		aux_cost_a = ft_calc_cost_a(stack_a, *(aux->index), sa);
		aux_cost_b = ft_calc_cost_b(stack_b, *(aux->index), sb);
		aux_cost = ft_abs(aux_cost_a) + ft_abs(aux_cost_b);
		if (aux_cost < mov_cost->cost_tot)
		{
			mov_cost->cost_sa = aux_cost_a;
			mov_cost->cost_sb = aux_cost_b;
			mov_cost->cost_tot = aux_cost;
		}
		if (mov_cost->cost_tot == 0)
			break ;
		aux = aux->next;
	}
	return (mov_cost);
}
