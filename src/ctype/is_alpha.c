/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_alpha.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milsonyujiaoki <milsonyujiaoki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 04:50:46 by milsonyujia       #+#    #+#             */
/*   Updated: 2026/05/25 04:50:47 by milsonyujia      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int ch)
{
	return (ft_isupper(ch) || ft_islower(ch));
}
