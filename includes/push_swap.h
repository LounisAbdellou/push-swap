/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:18:26 by labdello          #+#    #+#             */
/*   Updated: 2024/07/02 22:07:40 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h" 
# include <limits.h>

typedef struct s_stack
{
	size_t			index;
	int				value;
	int				price;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

int			is_stk_sorted(t_stack *stack);
int			is_above_median(t_stack *stack);
t_stack		*stk_new(int value);
t_stack		*stk_last(t_stack *stack);
t_stack		*stk_first(t_stack *stack);
t_stack		*stk_biggest(t_stack *stack);
t_stack		*stk_smallest(t_stack *stack);
t_stack		*get_cheapest_node(t_stack *stack);
size_t		stk_size(t_stack *stack);
void		stk_display(t_stack *stack);
void		stk_clear(t_stack **stack);
void		stk_add(t_stack **stack, t_stack *new);
void		push_swap(t_stack **a_stack, t_stack **b_stack);
void		update_nodes(t_stack *a_stack, t_stack *b_stack);
void		update_indexes(t_stack *stack);

void		swap(t_stack **stack, char *action);
void		swap_s(t_stack **a_stack, t_stack **b_stack);
void		push(t_stack **sender, t_stack **receiver, char *action);
void		rotate(t_stack **stack, char *action);
void		rotate_r(t_stack **a_stack, t_stack **b_stack);
void		reverse_rotate(t_stack **stack, char *action);
void		reverse_rotate_r(t_stack **a_stack, t_stack **b_stack);

#endif
