/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_alnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milsonyujiaoki <milsonyujiaoki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 04:39:31 by milsonyujia       #+#    #+#             */
/*   Updated: 2026/05/25 04:39:34 by milsonyujia      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isalnum(int ch)
{
    return (ft_isupper(ch) || ft_islower(ch) || ft_isdigit(ch));
}
