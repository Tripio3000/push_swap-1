/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:17:53 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/17 19:51:41 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_push.h"

int			ft_check_data(t_list *root_a)
{
	t_list *buff;

	buff = root_a;
	root_a = root_a->next;
	while (root_a != NULL)
	{
		if (buff->value <= root_a->value)
		{
			buff = root_a;
			root_a = root_a->next;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

int			make_sort(t_list *a, t_list *root_a, char *inst)
{
	t_help	p;

	p.i = 0;
	p.b = NULL;
	p.root_b = p.b;
	p.inst = inst;
	p.a = a;
	p.root_a = root_a;
	p.fff = 0;
	while (inst[p.i++] != '\0')
		while (inst[p.i] != '\n' && inst[p.i] != '\0')
			p.i += main_sort(&p);
	free(p.b);
	return (make_sort_continue(p.b, p.root_b, root_a));
}

int			main_sort(t_help *p)
{
	if (p->inst[p->i] == 'p' && p->inst[p->i + 1] == 'a')   // ЧТОБЫ ЧЕКЕР НЕ ВЫВОДИЛ КОМАНДЫ,В КАЖДУЮ ФУНКЦИЮ ПУШ6 СВАП6 РОТЕЙТ И ТАК ДАЛЕЕ НАДО ПЕРЕДАТЬ УКАЗАТЕЛЬ t_help *p, И УЖЕ В ЭТИ ФУНКЦИЯХ ПРОВЕРЯТЬ ПЕРЕМЕННУЮ p->fff, ЕСЛИ ОНА НОЛЬ - НЕ ВЫВОДИМ, ИНАЧЕ ВЫВОДИМ КОМАНДУ
		p->q = push_a(&(p->root_a), &(p->root_b));
	else if (p->inst[p->i] == 'p' && p->inst[p->i + 1] == 'b')
		p->q = push_b(&(p->root_b), &(p->root_a));
	else if (p->inst[p->i] == 's' && p->inst[p->i + 1] == 'b')
		p->q = swap_in_b(&(p->root_b), &(p->b));
	else if (p->inst[p->i] == 's' && p->inst[p->i + 1] == 'a')
		p->q = swap_in_a(&(p->root_a), &(p->a));
	else if (p->inst[p->i] == 's' && p->inst[p->i + 1] == 's')
		p->q = swap(&(p->a), &(p->b), &(p->root_a), &(p->root_b));
	else if (p->inst[p->i] == 'r' && p->inst[p->i + 1] == 'a')
		p->q = rotate_a(&(p->root_a));
	else if (p->inst[p->i] == 'r' && p->inst[p->i + 1] == 'b')
		p->q = rotate_b(&(p->root_b));
	else if (p->inst[p->i] == 'r' && p->inst[p->i + 1] == 'r' && (!ft_isalpha(p->inst[p->i + 2])))
		p->q = rotate(&(p->root_a), &(p->root_b));
	else if (p->inst[p->i] == 'r' && p->inst[p->i + 1] == 'r' && p->inst[p->i + 2] == 'a')
		p->q = reverse_a(&(p->a), &(p->root_a));
	else if (p->inst[p->i] == 'r' && p->inst[p->i + 1] == 'r' && p->inst[p->i + 2] == 'b')
		p->q = reverse_b(&p->b, &(p->root_b));
	else if (p->inst[p->i] == 'r' && p->inst[p->i + 1] == 'r' && p->inst[p->i + 2] == 'r')
		p->q = reverse(&(p->a), &(p->b), &(p->root_a), &(p->root_b));
	return (p->q);
}

int			make_sort_continue(t_list *b, t_list *root_b, t_list *root_a)
{
	b = root_b;
	if (root_b == NULL && ft_check_data(root_a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (0);
}

int			make_list_a(int argc, long long int arr[argc], char *inst)
{
	t_list	*a;
	t_list	*root_a;
	int		i;

	a = malloc(sizeof(t_list));
	root_a = a;
	i = 0;
	a->value = arr[i];
	while (i != (argc - 2))
	{
		a->next = malloc(sizeof(t_list));
		a = a->next;
		i++;
		a->value = arr[i];
	}
	a->next = NULL;
	a = root_a;
	make_sort(a, root_a, inst);
	return (0);
}
