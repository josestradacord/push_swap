/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:18:41 by joestrad          #+#    #+#             */
/*   Updated: 2023/01/11 12:03:26 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief 			This function checks if the argument is a number or not. To
 * 					do this it uses the ft_isdigit(char) function of the libft
 * 
 * @param str 		A string to check if it is a number
 * @return int 		1 if str is a number or 0 if it is not
 */
int	ft_isnbr(char *str)
{
	int	index;

	index = 0;
	if (str[index] != '\0' && str[index] == '-')
		index++;
	while (str[index] != '\0')
	{
		if (!ft_isdigit(str[index]))
			return (0);
		index++;
	}
	return (1);
}

/**
 * @brief 			This function counts the number of 0 at the left of the
 * 					string (that can be ignored)
 * 
 * @param str		The str argument 
 * @return int 		The number of 0 at the left of the string
 */
int	ft_count_zero(char *str)
{
	int	index;
	int	n_zero;

	index = 0;
	n_zero = 0;
	while (str[index])
	{
		if (str[index] == '-')
			index++;
		while (str[index] == '0')
		{
			n_zero++;
			index++;
		}
		return (n_zero);
	}
	return (n_zero);
}

/**
 * @brief 			This function compares two strings and return an int value
 * 					that says if they are equal, if the first string is lower
 *                  than the second one or if it is greater than the other
 * 
 * @param s1 		The first string to compare
 * @param s2 		The second string
 * @return int 		0 if the strings are equal, a positive number if s1 is
 * 					greater than s2 and a negative number if s2 is greater than
 * 					s1
 */
int	ft_strcmp_nbr(char *s1, char *s2)
{
	int		positive;
	int		index;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1) - ft_count_zero(s1);
	len_s2 = ft_strlen(s2) - ft_count_zero(s2);
	if (s1[0] == '-')
		positive = -1;
	else
		positive = 1;
	if (len_s1 > len_s2)
		return (1 * positive);
	else if (len_s1 < len_s2)
		return (-1 * positive);
	else
	{
		index = 0;
		while (s1[index] != '\0' && s1[index] == s2[index])
				index++;
		return (positive * (s1[index] - s2[index]));
	}
}

/**
 * @brief 			This function checks if a number is in the limits of an
 * 					integer, between -2147483648 and 2147483647
 * 
 * @param str 		The string that represents an integer
 * @return int 		1 if the argument is a valid integer 0 in other case
 */
int	ft_check_nbr_limits(char *str)
{
	if (str[0] == '-')
	{
		if ((ft_strlen(str) - ft_count_zero(str)) > ft_strlen(MIN_INT))
			return (0);
		if (ft_strcmp_nbr(str, MIN_INT) < 0)
			return (0);
	}
	else
	{
		if ((ft_strlen(str) - ft_count_zero(str)) > ft_strlen(MAX_INT))
			return (0);
		if (ft_strcmp_nbr(str, MAX_INT) > 0)
			return (0);
	}
	return (1);
}

/**
 * @brief 				This function creates a node and return it to be added
 * 						to a list of integers. If there is a error or a problem
 * 						with the malloc function it returns NULL
 * 
 * @param val 			The value of the element of the list, a valid integer
 * @return t_lst_int* 	A pointer to the just created node of the list, or NULL
 * 						if a problem has been found
 */
t_lst_int	*ft_create_node(int val)
{
	int			*index;
	int			*value;
	t_lst_int	*node;

	index = (int *) malloc(sizeof(int));
	if (!index)
		return (NULL);
	value = (int *) malloc(sizeof(int));
	if (!value)
		return (NULL);
	*index = 0;
	*value = val;
	node = ft_lst_int_new(value, index);
	return (node);
}
