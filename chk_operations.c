/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:48:21 by joestrad          #+#    #+#             */
/*   Updated: 2023/02/14 18:28:31 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * @brief 			This function reads the operations that we want to do with
 * 					the stacks, using the get_next_line() function
 * 
 * @param opers 	The list of operations
 */
void	ft_read_opers(t_lst_oper **opers)
{
	char		*oper;
	t_lst_oper	*node;

	oper = get_next_line(0);
	while (oper)
	{
		node = ft_lst_oper_new(oper);
		if (!node)
			return ;
		ft_lst_oper_add_back(opers, node);
		oper = get_next_line(0);
	}
	free(oper);
}

/**
 * @brief 			This function checks if an operation is a valid one
 * 
 * @param oper 		The operation to check
 * @return int 		The return value, 1 if is a valid operation, 0 otherwise
 */
int	ft_oper_isvalid(char *oper)
{
	if (!ft_strncmp(oper, "sa\n", 3) || !ft_strncmp(oper, "sb\n", 3) \
		|| !ft_strncmp(oper, "ss\n", 3) || !ft_strncmp(oper, "pa\n", 3) \
		|| !ft_strncmp(oper, "pb\n", 3) || !ft_strncmp(oper, "ra\n", 3) \
		|| !ft_strncmp(oper, "rb\n", 3) || !ft_strncmp(oper, "rr\n", 3) \
		|| !ft_strncmp(oper, "rra\n", 4) || !ft_strncmp(oper, "rrb\n", 4) \
		|| !ft_strncmp(oper, "rrr\n", 4))
		return (1);
	else
		return (0);
}

/**
 * @brief 			This function calls the ft_read_opers() function and checks
 * 					if they are valid operations or not
 * 
 * @param opers 	The list of operations
 * @return int 		The return value 1 if the operations are valid, 0 otherwise
 */
int	ft_add_opers(t_lst_oper **opers)
{
	t_lst_oper	*node;

	ft_read_opers(opers);
	node = *opers;
	while (node)
	{
		if (!ft_oper_isvalid(node->inst))
			return (0);
		node = node->next;
	}
	return (1);
}

/**
 * @brief 			This function makes a valid operation on the stack a, on 
 * 					the stack b or in both of them
 * 
 * @param stack_a 	The stack a
 * @param stack_b 	The stack b
 * @param oper 		The operation to make
 */
void	ft_make_oper(t_lst_int **stack_a, t_lst_int **stack_b, char *oper)
{
	if (ft_strncmp(oper, "sa\n", 3) == 0)
		ft_swap(*stack_a);
	else if (ft_strncmp(oper, "sb\n", 3) == 0)
		ft_swap(*stack_b);
	else if (ft_strncmp(oper, "ss\n", 3) == 0)
		ft_dblswap(*stack_a, *stack_b);
	else if (ft_strncmp(oper, "pa\n", 3) == 0)
		ft_push_a(stack_a, stack_b);
	else if (ft_strncmp(oper, "pb\n", 3) == 0)
		ft_push_b(stack_a, stack_b);
	else if (ft_strncmp(oper, "ra\n", 3) == 0)
		ft_rotate(stack_a);
	else if (ft_strncmp(oper, "rb\n", 3) == 0)
		ft_rotate(stack_b);
	else if (ft_strncmp(oper, "rr\n", 3) == 0)
		ft_dblrotate(stack_a, stack_b);
	else if (ft_strncmp(oper, "rra\n", 4) == 0)
		ft_revrotate(stack_a);
	else if (ft_strncmp(oper, "rrb\n", 4) == 0)
		ft_revrotate(stack_b);
	else if (ft_strncmp(oper, "rrr\n", 4) == 0)
		ft_dblrevrotate(stack_a, stack_b);
}

/**
 * @brief 			This function checks if the operations of the list of
 * 					operations oprs that are made on the stacks stck_a and
 * 					stck_b sort the stack stck_a and get the stack stck_b
 * 					empty at the end
 * 
 * @param stck_a 	The initial stack of unordered integers
 * @param stck_b 	An auxiliary stack to help, is empty at the begining and
 * 					has to be empty at the end
 * @param oprs 		The list of operations to do
 */
void	ft_check_movs(t_lst_int **stck_a, t_lst_int **stck_b, t_lst_oper **oprs)
{
	t_lst_oper	*oper;

	oper = *oprs;
	while (oper)
	{
		ft_make_oper(stck_a, stck_b, oper->inst);
		oper = oper->next;
	}
	if (ft_stack_is_sorted(stck_a) && ft_lst_int_size(*stck_b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
