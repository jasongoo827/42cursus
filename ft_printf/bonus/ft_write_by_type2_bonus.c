/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_by_type2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:59:49 by jgoo              #+#    #+#             */
/*   Updated: 2023/12/14 19:59:51 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	type_normal(t_conv *conv)
{
	return ((int)write(1, conv -> start, conv -> end - conv -> start));
}
