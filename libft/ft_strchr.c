/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 14:16:37 by rfulop            #+#    #+#             */
/*   Updated: 2017/05/25 06:21:08 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	int a;

	a = 0;
	while (src[a] != '\0' && src[a] != c)
		a++;
	if (src[a] == c)
		return ((char *)src + a);
	return (NULL);
}
