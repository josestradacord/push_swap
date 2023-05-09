/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:32:03 by joestrad          #+#    #+#             */
/*   Updated: 2023/02/14 17:46:04 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "gnl/get_next_line.h"

// Linked list to store the movements
typedef struct s_lst_oper
{
	char				*inst;
	struct s_lst_oper	*next;
}	t_lst_oper;

// Manage list of operations
t_lst_oper	*ft_lst_oper_new(char *oper);
void		ft_lst_oper_add_back(t_lst_oper **lst, t_lst_oper *new);
int			ft_lst_oper_size(t_lst_oper *lst);
void		ft_lst_oper_delone(t_lst_oper *lst, void (*del)(void *));
void		ft_lst_oper_clear(t_lst_oper **lst, void (*del)(void *));
void		ft_free_mem(t_lst_int *stck_a, t_lst_int *stck_b, t_lst_oper *oprs);

// Operations
void		ft_read_opers(t_lst_oper **opers);
int			ft_add_opers(t_lst_oper **opers);
int			ft_oper_isvalid(char *oper);
void		ft_make_oper(t_lst_int **stack_a, t_lst_int **stack_b, char *oper);
void		ft_check_movs(t_lst_int **s_a, t_lst_int **s_b, t_lst_oper **opers);

#endif