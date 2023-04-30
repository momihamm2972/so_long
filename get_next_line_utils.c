/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:28:34 by momihamm          #+#    #+#             */
/*   Updated: 2023/04/30 18:42:48 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//rak dayeeer strdup machi ft_strdup

char	*ft_strdup(char *s1)
{
	int		len;
	char	*str;
	int		indx;

	len = ft_strlen(s1);
	str = ft_calloc (len + 1, sizeof(char));
	indx = 0;
	if (!str)
		return (NULL);
	while (indx < len)
	{
		str[indx] = s1[indx];
		indx++;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str1;
	char	*str2;
	unsigned int 	indx_of_conca;
	char	*buff;
	unsigned int 	indx;

	if (!s1)
		s1 = ft_strdup("");
	str1 = (char *)s1;
	str2 = (char *)s2;
	indx_of_conca = 0;
	buff = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!buff)
		return (NULL);
	indx = 0;
	while (s1[indx] != '\0')
	{
		buff[indx] = str1[indx];
		indx++;
	}
	while (indx < (ft_strlen(str1) + ft_strlen(str2)))
		buff[indx++] = str2[indx_of_conca++];
	buff[indx] = '\0';
	return (free(s1), buff);
}

unsigned int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char	*alloc_adds;
	unsigned int		str_len;
	unsigned int		indx;
	unsigned int		end;

	if (!s)
		return (NULL);
	str_len = ft_strlen (s);
	if (start >= str_len)
		return (ft_calloc(1, sizeof(char)));
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	alloc_adds = (char *) ft_calloc(len + 1, sizeof(char));
	if (!alloc_adds)
		return (NULL);
	indx = 0;
	end = start + len;
	while (start < end && indx < len + 1 && s[start])
		alloc_adds[indx++] = s[start++];
	return (alloc_adds);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*str;
	size_t	indx;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	str = (char *)ptr;
	indx = 0;
	while (indx < (count * size))
		str[indx++] = 0;
	return (ptr);
}
