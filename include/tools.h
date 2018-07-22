/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-kir <mben-kir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 22:48:42 by mben-kir          #+#    #+#             */
/*   Updated: 2018/07/22 22:48:43 by mben-kir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# define ISNUM(n) (n >= '0' && n<= '9')
# define ISSPACE1(c) (c == '\t' || c == '\n' || c == '\v')
# define ISSPACE2(c) (c == '\f' || c == '\r' || c == ' ')
# define ISSPACE(c) (ISSPACE1(c) || ISSPACE2(c))
# define TRUE 1
# define FALSE 0

int			ft_atoi_fwd(char **str);

#endif
