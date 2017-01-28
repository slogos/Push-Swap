/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slogos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 02:57:20 by slogos            #+#    #+#             */
/*   Updated: 2017/01/02 01:56:19 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_n(const char *s, char c)
{
	int		count;
	int		sub;

	sub = 0;
	count = 0;
	while (*s != '\0')
	{
		if (*s == c && sub == 1)
			sub = 0;
		if (*s != c && sub == 0)
		{
			sub = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static int		ft_wlen(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

static char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s)
	{
		i = 0;
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (start--)
			s++;
		while (i < len && s[i] != '\0')
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**t;
	int		nb_word;
	int		i;

	if (s)
	{
		i = 0;
		nb_word = ft_n((const char *)s, c);
		if (!(t = (char **)malloc(sizeof(*t) * (nb_word + 1))))
			return (NULL);
		while (nb_word--)
		{
			while (*s == c && *s != '\0')
				s++;
			if (!(t[i] = ft_strsub((const char *)s, 0, \
					ft_wlen((const char *)s, c))))
				return (NULL);
			s = s + ft_wlen(s, c);
			i++;
		}
		t[i] = NULL;
		return (t);
	}
	return (0);
}
