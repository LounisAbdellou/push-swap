/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:41:34 by labdello          #+#    #+#             */
/*   Updated: 2024/07/24 15:41:35 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"
# include <limits.h>

typedef struct s_stack {
	int				value;
	int				index;
	int				order;
	int				grp;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// Parse utils >>>
char	*join_input(char **input);
int		check_tab(char **tab);
int		fill_stack(char **tab, t_stack **stack);

// Free utils >>>
void	free_tab(char **tab);
void	free_stack(t_stack **stack);
int		ft_tablen(char **tab);

// Stack utils >>>
t_stack	*ft_stknew(int value);
t_stack	*ft_stk_gethead(t_stack *stk);
void	ft_stkadd_top(t_stack **stk, t_stack *new);
t_stack	*ft_stkdel_top(t_stack **stk);
int		get_index_of(int value, t_stack *stack);
int		ft_stksize(t_stack *stack);
int		is_stack_sorted(t_stack *stack, int len);
void	push_from_to(t_stack **stack_from, t_stack **stack_to);
void	swap_top_of(t_stack **stack);
void	rotate_stack(t_stack **stack, int direction);
t_stack	*get_this_node(int index, t_stack *stack);
t_stack	*get_limit_node(t_stack *stack, int limit);
void	init_push_swap(t_stack **stack_a);

// Mouve >>>
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_s(t_stack **stack_a, t_stack **stack_b);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	rotate_r(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_r(t_stack **stack_a, t_stack **stack_b);

// Calculate >>>
int		direction_of_rotate(int index, t_stack *stack);
int		number_of_rotate(int index, t_stack *stack);
int		get_place_of(int value, t_stack *stack);
int		eval_move(t_stack *current, t_stack *stack_a);

// Algo small >>>
void	sort_stack(t_stack **stack);
void	sort_three(t_stack **stack_a);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	bring_back_small(t_stack **stack_a, t_stack **stack_b);
void	handle_small(t_stack **stack_a, t_stack **stack_b);

// Execute >>>
void	push_by_grp(t_stack **sa, t_stack **sb, int len, int glen);
void	bring_back_sb(t_stack **stack_a, t_stack **stack_b, int grp);
void	execute_move(t_stack *to_move, t_stack **stack_a, t_stack **stack_b);

// Error utils >>>
int		return_error(char *message);

#endif
