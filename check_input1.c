/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:58:05 by joestrad          #+#    #+#             */
/*   Updated: 2023/02/10 11:58:13 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief 			This function counts the arguments that are included in the
 * 					string str. These arguments are separated by white spaces
 * 
 * @param str 		The string we want to know how many arguments are contained
 * 					in it
 * @return int 		The number of arguments
 */
int	ft_count_args(char *str)
{
	int	args;
	int	i;

	args = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == ' ')
			i++;
		if (str[i] != '\0')
			args++;
		while (str[i] != '\0' && str[i] != ' ')
			i++;
	}
	return (args);
}

/**
 * @brief 			This functon splits the argument if it is given between "",
 * 					and return then as a array of array of characters. Also
 * 					return the number of arguments in the parameter n_args
 * 
 * @param n_args 	This parameter is used to return the number of arguments that
 * 					is given between "" and are separated by white spaces
 * @param argv 		The string contained all the arguments, between ""
 * @return char** 	The array of array of characters returned (an array which
 * 					contain each of the single arguments)
 */
char	**ft_split_args(int *n_args, char **argv)
{
	*n_args = ft_count_args(argv[0]);
	return (ft_split(argv[0], ' '));
}

/**
 * @brief 			This function does the free of the memory alocated in the
 * 					array of characters of size n. First makes the free of each
 * 					string and then makes the free of de char**
 * 
 * @param str 		The arrays of characters that we want to liberate
 * @param n 		The size of the array
 * @return char** 	The new value of the array of characters, NULL
 */
char	**ft_free(char **str, int n)
{
	int	index;

	index = 0;
	while (index < n)
		free(str[index++]);
	free(str);
	return (NULL);
}

/**
 * @brief 			This function checks if the arguments are valid integer
 * 					numbers
 * 
 * @param arg 		Is the index of the first argument, 0
 * @param n_args 	Is a pointer to the number or arguments
 * @param argv 		Is a matrix (array of strings) which contain the arguments
 * @param stack 	Is the list that will contain the arguments, if they are
 * 					valid ones
 * @return int 		The return value, 1 if they are valid integers or 0 if not
 */
int	ft_check_numbers(int arg, int *n_args, char **argv, t_lst_int **stack)
{
	int			value;
	t_lst_int	*node;

	while (arg < *n_args)
	{
		if (ft_strlen(argv[arg]) == 0)
			return (0);
		if (!ft_isnbr(argv[arg]) || !ft_check_nbr_limits(argv[arg]))
			return (0);
		value = ft_atoi(argv[arg]);
		if (!ft_num_is_in_lst_int(value, *stack))
		{
			node = ft_create_node(value);
			if (!node)
				return (0);
			ft_lst_int_add_back(stack, node);
			arg++;
		}
		else
		{
			ft_lst_int_clear(stack, free);
			return (0);
		}
	}
	return (1);
}

/**
 * @brief 			This function checks the arguments given in the command
 * 					line input and verifies if they are correct
 * 
 * @param argc 		Is the number of arguments of the command line, without
 * 					the program name
 * @param argv 		Is an array of each of the arguments or a string containing
 * 					all arguments in a single line
 * @param stack 	Is the list that will contain the arguments, if they are
 * 					valid ones
 * @return int 		The return value, 1 if they are correct or 0 if not
 */
int	ft_check_args(int argc, char **argv, t_lst_int **stack)
{
	int		n_args;
	char	**v_args;
	int		free_mem;
	int		res;

	free_mem = 0;
	if (argc == 1)
	{
		v_args = ft_split_args(&n_args, argv);
		free_mem = 1;
	}
	else
	{
		n_args = argc;
		v_args = argv;
	}
	if (!v_args[0])
	{
		ft_free(v_args, n_args);
		return (0);
	}
	res = ft_check_numbers(0, &n_args, v_args, stack);
	if (free_mem)
		ft_free(v_args, n_args);
	return (res);
}
