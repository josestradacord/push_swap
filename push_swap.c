/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:53:49 by joestrad          #+#    #+#             */
/*   Updated: 2023/02/13 13:59:00 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief 		This function shows the leaks of the main function
 * 
 */
void	ft_leaks(void)
{
	system("leaks -q push_swap");
}

/**
 * @brief 			The main function of the program. It checks the arguments,
 * 					or program's input, if they are correct and the list of
 * 					numbers isn't ordered, it calls the function to order them
 * 					and write on the output the necesary movements that are
 * 					necesary to do in both stacks to do the job
 * 
 * @param argc 		The number of input's arguments (including the program name)
 * @param argv 		The array of arguments (eacho of them is an array too)
 * @return int 		The return value
 */
int	main(int argc, char **argv)
{
	t_lst_int	*stack_a;
	t_lst_int	*stack_b;
	int			s_a_size;
	int			args_ok;

	if (argc > 1)
	{
		stack_b = NULL;
		args_ok = ft_check_args(argc - 1, &argv[1], &stack_a);
		if (!args_ok)
			ft_putstr_fd("Error\n", 2);
		else
		{
			s_a_size = ft_lst_int_size(stack_a);
			ft_update_index(&stack_a);
			if (!ft_stack_is_sorted(&stack_a))
				ft_sort_stack(&stack_a, &stack_b, s_a_size);
		}
	}
	ft_lst_int_clear(&stack_a, free);
	ft_lst_int_clear(&stack_b, free);
	return (0);
}
