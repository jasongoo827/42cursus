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

#include "push_swap_bonus.h"

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

	m_arr = normalize_arr(arr, cnt);
	ps = create_push_swap(cnt);
	init_stack(ps -> a, m_arr, cnt);
	checker(ps, 0);
	free_push_swap(ps);
	free(m_arr);
}

void	checker(t_push_swap *ps, int fd)
{
	char		*input;
	t_node		*node;
	t_stack		*stack;

	stack = create_stack("", 0);
	while (1)
	{
		input = get_next_line(fd);
		if (input == NULL)
			break ;
		node = create_node(0, input);
		enque(stack, node, FRONT);
	}
	iter_cmdlist(ps, stack);
	if (check_stack_sorted(ps))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(stack);
}
