/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev-yuji <dev-yuji@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 10:42:48 by milsonyujia       #+#    #+#             */
/*   Updated: 2026/05/25 05:55:47 by dev-yuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	put_spaces(int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		put_char_len(' ');
		i++;
	}
	return (count);
}

int	print_percent(t_format *fmt, va_list args)
{
	int	count;

	(void)args;
	count = 0;
	if (!fmt->left_align && fmt->width > 1)
		count += put_spaces(fmt->width - 1);
	put_char_len('%');
	count++;
	if (fmt->left_align && fmt->width > 1)
		count += put_spaces(fmt->width - 1);
	return (count);
}
