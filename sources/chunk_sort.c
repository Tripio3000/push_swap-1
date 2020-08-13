/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:13:50 by acarlett          #+#    #+#             */
/*   Updated: 2020/08/13 03:41:17 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

void		FindMinNumberOfChunkA(t_help **f, t_list **root_a, t_list **a, t_list **root_b)
{
	(*f)->local_min = (*f)->min;
	(*f)->local_max = (*f)->min + (*f)->chunk_size;
	(*f)->up = TakeNumberOperationUp((*root_a), (*f)->local_min, (*f)->local_max);
	(*f)->down = TakeNumberOperationDown((*root_a), (*f)->local_min, (*f)->local_max);
	printf ("up_A = %d, down_A - %d\n", (*f)->up, (*f)->down);
	if ((*f)->up <= (*f)->down)
		MakeMoreRotatePush(root_b, f, root_a);
	else
		MakeMoreReversePush(root_b, f, root_a, a);
}

void		MainSortChunk(t_help *f, t_list *root_a, t_list *a)
{
	int		first_min;
	t_list	*root_b;

	first_min = f->min;
	root_b = NULL;
	int cccc = 9;
	while (cccc && f->min < (first_min + f->chunk_size))
	{
		cccc--;
		FindMinNumberOfChunkA(&f, &root_a, &a, &root_b);
		TakeMinMaxValue(root_a, &f);
	}
}

