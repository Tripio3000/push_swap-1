/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_second.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:08:48 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/22 19:32:47 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

t_list		*sort_stack_a(t_list **root_a, t_list **a, t_help *f)
{
	t_list *tmp;
	t_list *buff;

	tmp = (*root_a)->next;
	buff = (*root_a);
	if (f->max == (*root_a)->value)
	{
		if (f->mid == tmp->value && write(1, "sa\n", 3))
			swap_in_a(root_a, a);
	}
	else if (f->mid == (*root_a)->value &&
	f->max == tmp->value && write(1, "rra\n", 4))
		reverse_a(a, root_a, 0);
	else if (f->mid == (*root_a)->value &&
	f->min == tmp->value && write(1, "sa\n", 3))
		swap_in_a(root_a, a);
	else if (f->min == (*root_a)->value &&
	f->max == tmp->value)
	{
		swap_in_a(root_a, a);
		write(1, "sa\n", 3);
	}
	return (buff);
}

int			main_continue(t_list *a, t_list *root_a, t_help *f)
{
	if (!check_massive(root_a))
	{
		write(1, "RT\n", 3);
		return (display_error());
	}
	if (!check_stack_a(root_a))
	{
		free_list(root_a);
		free(f);
		return (0);
	}
	take_min_mid_max(a, root_a, f->cc, f);
	return (0);
}

void		for_take_mmm(t_help **f, int cc)
{
	(*f)->mid = 0;
	(*f)->max = 0;
	(*f)->c = 0;
	(*f)->cc = cc;
	(*f)->minn = NULL;
	(*f)->midd = NULL;
	(*f)->maxx = NULL;
}

void		make_first_if(t_help **f, t_list *buff, t_list *root_buff)
{
	while ((*f)->cc >= 0)
	{
		while (buff != NULL)
		{
			if (buff->value > (*f)->tmp && buff->value < (*f)->sec_tmp)
				(*f)->sec_tmp = buff->value;
			buff = buff->next;
		}
		(*f)->tmp = (*f)->sec_tmp;
		(*f)->sec_tmp = (*f)->max;
		(*f)->cc--;
		buff = root_buff;
	}
	(*f)->mid = (*f)->tmp;
	(*f)->midd = "r";
}

void		make_first_else(t_help **f, t_list *buff)
{
	while (buff->next != NULL)
	{
		if ((buff->value != (*f)->min) && (buff->value != (*f)->max))
		{
			(*f)->midd = "r";
			(*f)->mid = buff->value;
		}
		buff = buff->next;
	}
}