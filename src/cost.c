/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamottet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:05:11 by mamottet          #+#    #+#             */
/*   Updated: 2023/07/20 17:05:27 by mamottet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = get_stack_size(tmp_a);
	size_b = get_stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->tab_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->tab_b = (size_b - tmp_b->pos) * -1;
		tmp_b->tab_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->tab_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (nb_abs(tmp->tab_a) + nb_abs(tmp->tab_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(tmp->tab_b) + nb_abs(tmp->tab_a);
			cost_a = tmp->tab_a;
			cost_b = tmp->tab_b;
		}
		tmp = tmp->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}
