/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_fwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-kir <mben-kir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 22:53:27 by mben-kir          #+#    #+#             */
/*   Updated: 2018/07/22 22:53:28 by mben-kir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int			ft_atoi_fwd(char **str)
{
	char	*cur;
	int		sign;
	int		nb;

	cur = *str;
	while (*cur && ISSPACE(*cur))
		cur++;
	sign = 1;
	if (*cur && (*cur == '+' || *cur == '-'))
		sign = *(cur++) == '+' ? 1 : -1;
	if (*cur && !ISNUM(*cur))
		return (0);
	nb = 0;
	while (*cur && ISNUM(*cur))
	{
		nb += *cur - '0';
		if (*(++cur) && ISNUM(*cur))
			nb *= 10;
	}
	*str = cur;
	return (sign * nb);
}
