/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:15:46 by slogos            #+#    #+#             */
/*   Updated: 2016/11/09 01:21:31 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	char	*ret;

	ret = NULL;
	if (s1 && s2)
	{
		if ((ret = (char*)malloc(sizeof(char) * \
					ft_strlen(s1) + len + 1)) == NULL)
			return (NULL);
		ft_strcpy(ret, s1);
		ft_strncat(ret, s2, len);
	}
	return (ret);
}
