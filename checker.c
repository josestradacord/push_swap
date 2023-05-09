/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:32:57 by joestrad          #+#    #+#             */
/*   Updated: 2023/02/14 18:11:23 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * @brief 		This function shows the leaks of the main function
 * 
 */
void	ft_leaks(void)
{
	system("leaks -q checker");
}

/**
 * @brief 			This function frees both stacks (a and b) and the list of
 * 					operations
 * 
 * @param stack_a 	The stack a
 * @param stack_b 	The stack b
 * @param opers 	The list of operations
 */
void	ft_free_mem(t_lst_int *stack_a, t_lst_int *stack_b, t_lst_oper *opers)
{
	ft_lst_int_clear(&stack_a, free);
	ft_lst_int_clear(&stack_b, free);
	ft_lst_oper_clear(&opers, free);
}

/**
 * @brief 			This is the main function of the program, the one who starts
 * 					the execution
 * 
 * @param argc 		The number of arguments that appear in the command line
 * @param argv 		An array of strings (char *) that contains the arguments
 * 					of the command line
 * @return int 		The return value, normally 0
 */
int	main(int argc, char **argv)
{
	t_lst_int	*stack_a;
	t_lst_int	*stack_b;
	t_lst_oper	*opers;
	int			args_ok;
	int			oper_ok;

	if (argc > 1)
	{
		stack_b = NULL;
		opers = NULL;
		args_ok = ft_check_args(argc - 1, &argv[1], &stack_a);
		if (!args_ok)
			ft_putstr_fd("Error\n", 2);
		else
		{
			oper_ok = ft_add_opers(&opers);
			if (!oper_ok)
				ft_putstr_fd("Error\n", 2);
			else
				ft_check_movs(&stack_a, &stack_b, &opers);
		}
		ft_free_mem(stack_a, stack_b, opers);
	}
	return (0);
}
