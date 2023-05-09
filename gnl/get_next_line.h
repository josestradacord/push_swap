/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:02:51 by joestrad          #+#    #+#             */
/*   Updated: 2023/02/13 19:38:24 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 43
# endif

char	*get_next_line(int fd);

//size_t	ft_strlen(char *str);
//void	ft_bzero(void *s, size_t n);
//void	*ft_calloc(size_t count, size_t size);
//char	*ft_strchr(char *s, int c);
//char	*ft_strjoin(char *s1, char *s2);
#endif
