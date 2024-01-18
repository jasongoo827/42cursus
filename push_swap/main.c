/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:51:51 by jgoo              #+#    #+#             */
/*   Updated: 2024/01/15 12:51:53 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	check_leak(void)
// {
// 	system("leaks --list -- a.out");
// }

int	main(int argc, char *argv[])
{
	int	*arr;
	int	cnt;

	arr = NULL;
	if (argc == 2)
		arr = parse_str(argv[1], &cnt);
	else if (argc > 2)
		arr = parse_num(++argv, argc - 1, &cnt);
	else
		return (0);
	if (arr == NULL || check_dup(arr, cnt) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	push_swap(arr, cnt);
	free(arr);
	return (0);
}

void	push_swap(int *arr, int cnt)
{
	t_push_swap	*ps;
	int			*m_arr;
	int			*o_arr;

	if (check_sorted(arr, cnt) == 1)
		return ;
	o_arr = NULL;
	m_arr = normalize_arr(arr, cnt);
	ps = create_push_swap(cnt);
	init_stack(ps -> a, m_arr, cnt);
	optimize(ps, &cnt);
	if (cnt > 5)
	{
		o_arr = dup_arr(m_arr, cnt);
		normalize_by_stack(ps -> a, m_arr, cnt);
		ps -> cnt = 0;
		ps -> f_sort = 1;
		init_stack_again(ps -> a, o_arr, m_arr);
		optimize(ps, &cnt);
	}
	free_push_swap(ps);
	free(m_arr);
	if (o_arr != NULL)
		free(o_arr);
}

void	optimize(t_push_swap *ps, int *cnt)
{
	if (*cnt == 2)
		ft_printf("sa\n");
	else if (*cnt <= 5)
	{
		ps->f_sort = 1;
		push_swap_hard(ps, *cnt);
	}
	else if (*cnt > 81 && *cnt <= 108)
		ps_repeat_opt(ps, ps -> a, ps -> b, 5);
	else
		ps_repeat(ps, ps -> a, ps -> b, cnt);
}

void	ps_repeat(t_push_swap *ps, t_stack *a, t_stack *b, int *cnt)
{
	int	order;
	int	rep;

	rep = count_rep(ps, cnt);
	order = rep % 2;
	while (rep != 0)
	{
		if (rep % 2 == order)
			ps_radix_sort(ps, a, b);
		else
			ps_radix_sort(ps, b, a);
		rep--;
	}
	if (order == 1)
	{
		while (b -> cnt != 0)
			push(ps, b, a);
	}
}

void	ps_repeat_opt(t_push_swap *ps, t_stack *a, t_stack *b, int cnt)
{
	int	order;

	order = cnt % 2;
	while (cnt != 0)
	{
		if (cnt % 2 == order)
			ps_radix_sort(ps, a, b);
		else
		{
			if (cnt == 2)
			{
				ps_radix_opt(ps, b, a);
				cnt--;
			}
			else
				ps_radix_sort(ps, b, a);
		}
		cnt--;
	}
}
