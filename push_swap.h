/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joestrad <joestrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:54:21 by joestrad          #+#    #+#             */
/*   Updated: 2023/02/14 17:41:25 by joestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define MAX_INT "2147483647"
# define MIN_INT "-2147483648"
# define MAX_NUM 2147483647

// Double linked integers lists
typedef struct s_lst_int
{
	int					*value;
	int					*index;
	struct s_lst_int	*next;
	struct s_lst_int	*prev;
}	t_lst_int;

// Costs of movements
typedef struct s_cost
{
	int	cost_sa;
	int	cost_sb;
	int	cost_tot;
}	t_cost;

// Check input 
int			ft_check_args(int argc, char **argv, t_lst_int **stack);
int			ft_check_nbr_limits(char *str);
int			ft_isnbr(char *str);
t_lst_int	*ft_create_node(int val);

// Index operations
void		ft_update_index(t_lst_int **stack);
int			ft_get_first_index(t_lst_int *stack);
int			ft_get_medium_index(t_lst_int *stack);
int			ft_get_last_index(t_lst_int *stack);

// Sort functions
int			ft_stack_is_sorted(t_lst_int **stack);
void		ft_sort_lst_size_3(t_lst_int **stack);
void		ft_sort_lst_size_5(t_lst_int **stack_a, t_lst_int **stack_b);
void		ft_sort_stack(t_lst_int **stack_a, t_lst_int **stack_b, int size_a);
void		ft_make_rots_stack_a(t_lst_int **s_a, t_lst_int **s_b, int value);
void		ft_sort_lst_radix(t_lst_int **stck_a, t_lst_int **stck_b, int size);
void		ft_sort_lst_int(t_lst_int **stack_a, t_lst_int **stack_b, int s_sa);
void		ft_rotate_stack(t_lst_int **stack_a, int size);
void		ft_make_dbl_movs(t_lst_int **s_a, t_lst_int **s_b, t_cost *cst);
void		ft_make_movs(t_lst_int **stack_a, t_lst_int **stack_b, t_cost *cst);
t_cost		*ft_calc_cost(t_lst_int *stck_a, t_lst_int *stck_b, int sa, int sb);
int			ft_calc_cost_a(t_lst_int *stack, int value, int size_a);
int			ft_calc_cost_b(t_lst_int *stack, int value, int size_b);
t_cost		*ft_inic_cost(void);
void		ft_initial_movs(t_lst_int **stack_a, t_lst_int **stack_b, int s_sa);

// Manage integer's lists
t_lst_int	*ft_lst_int_new(int *value, int *index);
void		ft_lst_int_print_v(t_lst_int *lst);
void		ft_lst_int_print_i(t_lst_int *lst);
int			ft_num_is_in_lst_int(int nbr, t_lst_int *lst);
void		ft_lst_int_add_back(t_lst_int **lst, t_lst_int *new);
void		ft_lst_int_delone(t_lst_int *lst, void (*del)(void *));
void		ft_lst_int_clear(t_lst_int **lst, void (*del)(void *));
void		ft_lst_int_add_front(t_lst_int **lst, t_lst_int *new);
int			ft_lst_int_size(t_lst_int *lst);
int			ft_search_from_top(t_lst_int *stack, int val_max);
int			ft_search_from_bottom(t_lst_int *stack, int val_max);
int			ft_place_from_top(t_lst_int *stack, int val_max);
int			ft_place_from_bottom(t_lst_int *stack, int val_max);

// Stacks operations
void		ft_swap(t_lst_int *stack);
void		ft_dblswap(t_lst_int *stack_a, t_lst_int *stack_b);
void		ft_make_swap_a(t_lst_int *stack);
void		ft_make_swap_b(t_lst_int *stack);
void		ft_make_dbl_swap(t_lst_int *stack_a, t_lst_int *stack_b);
void		ft_push_a(t_lst_int **stack_a, t_lst_int **stack_b);
void		ft_push_b(t_lst_int **stack_a, t_lst_int **stack_b);
void		ft_make_push_a(t_lst_int **stack_a, t_lst_int **stack_b);
void		ft_make_push_b(t_lst_int **stack_a, t_lst_int **stack_b);
void		ft_rotate(t_lst_int **stack);
void		ft_dblrotate(t_lst_int **stack_a, t_lst_int **stack_b);
void		ft_revrotate(t_lst_int **stack);
void		ft_dblrevrotate(t_lst_int **stack_a, t_lst_int **stack_b);
void		ft_make_rotate_a(t_lst_int **stack);
void		ft_make_rotate_b(t_lst_int **stack);
void		ft_make_dbl_rotate(t_lst_int **stack_a, t_lst_int **stack_b);
void		ft_make_rev_rotate_a(t_lst_int **stack);
void		ft_make_rev_rotate_b(t_lst_int **stack);
void		ft_make_dbl_rev_rotate(t_lst_int **stack_a, t_lst_int **stack_b);

#endif