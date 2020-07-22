/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:34:51 by acarlett          #+#    #+#             */
/*   Updated: 2020/07/22 19:15:24 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUSH_H
# define LIB_PUSH_H

# include <libc.h>
# include "libft.h"

typedef struct		s_list
{
	struct s_list	*next;
	int				value;
}					t_list;

typedef	struct		s_help
{
	int				min;
	char			*minn;
	char			*f_min;
	int				mid;
	char			*midd;
	char			*f_mid;
	int				max;
	char			*maxx;
	char			*f_max;
	int				c;
	int				cc;
	int				ccc;
	int				tmp;
	int				f;
	int				ff;
	int				fff;
	int				sec_tmp;
	char			*inst;
	int				i;
	int				q;
	int				w;
	t_list			*a;
	t_list			*b;
	t_list			*root_a;
	t_list			*root_b;
	t_list			*t3;
}					t_help;

int					first_check(char **argv);
int					make_sort(t_list *a, t_list *root_a, char *inst);
int					make_list_a(int argc, long long int arr[argc], char *inst);
int					swap(t_list **a, t_list **b,
t_list **root_a, t_list **root_b);
int					reverse(t_list **a, t_list **b,
t_list **root_a, t_list **root_b);
int					reverse_a(t_list **a, t_list **root_a, int t);
int					reverse_b(t_list **b, t_list **root_b, int t);
int					swap(t_list **a, t_list **b, t_list **root_a,
t_list **root_b);
int					swap_in_b(t_list **root_b, t_list **b);
int					swap_in_a(t_list **root_a, t_list **a);
int					rotate(t_list **root_a, t_list **root_b);
int					rotate_a(t_list **root_a);
int					rotate_b(t_list **root_b);
int					push_numbers_in_b(t_list *a, t_list *root_a, t_help *f);
void				take_min_mid_max(t_list *a, t_list *root_a, int cc, t_help *f);
t_list				*sort_stack_a(t_list **root_a, t_list **a, t_help *f);
t_list				*rewrite(t_list *buff);
int					check_min_max(int value, t_help *f);
int					push_b(t_list **root_b, t_list **root_a);
int					push_a(t_list **root_a, t_list **root_b);
int					check_rb(t_list **root_b);
int					check_ra(t_list *root_a);
int					check_rrb(t_list **b, t_list **root_b);
int					check_rra(t_list **a, t_list **root_a);
int					swap_b_continue(t_list **root_b, t_list *root);
int					swap_a_continue(void);
int					check_argv(char *s);
int					display_error(void);
int					make_sort_continue(t_list *b, t_list *root_b,
t_list *root_a);
int					main_sort(t_help *p);

int					checker_swap_a(t_list **root_a, t_list **a);
int					checker_swap_b(t_list **root_b, t_list **b);
int					checker_swap(t_list **a, t_list **b,
t_list **root_a, t_list **root_b);
int					checker_rotate_a(t_list **root_a);
int					checker_rotate_b(t_list **root_b);
int					checker_rotate(t_list **root_a, t_list **root_b);
int					checker_push_a(t_list **root_a, t_list **root_b);
int					checker_push_b(t_list **root_b, t_list **root_a);
int					checker_reverse_a(t_list **a, t_list **root_a);
int					checker_reverse_b(t_list **b, t_list **root_b);
int					checker_reverse(t_list **a, t_list **b,
t_list **root_a, t_list **root_b);
int					check_massive(t_list *root_a);
int					check_stack_a(t_list *root_a);
int					main_sort_second(t_help *p);
int					ft_check_data(t_list *root_a);
void				print_a(t_list *root_a);
void				print_b(t_list *root_b);
int					help_rotate(t_list *tmp, int c);
void				for_make(t_help **p);
int					help_main(char **av, int i, t_list **a);
void				print_a(t_list *root_a);
void				print_b(t_list *root_b);
int					main_continue(t_list *a, t_list *root_a, t_help *f);
void				for_take_mmm(t_help **f, int cc);
void				make_first_if(t_help **f, t_list *buff, t_list *root_buff);
void				make_first_else(t_help **f, t_list *buff);
void				second_step_while(t_help **f, t_list **root_a,
t_list **a, t_list **root_b);
void				second_step_secondwhile(t_help **f, t_list **root_a,
t_list **root_b);
void				print_b(t_list *root_b);
void				print_a(t_list *root_a);
void				free_list(t_list *root_a);

#endif