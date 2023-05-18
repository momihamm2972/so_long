/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:53:29 by momihamm          #+#    #+#             */
/*   Updated: 2023/04/29 15:34:39 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strstr(char *big, char *little)
{
	int	indx_big;
	int	indx_lit;

	if (*little == '\0')
		return ((char *)big);
	indx_big = 0;
	indx_lit = 0;
	while (big[indx_big])
	{
		while (little[indx_lit] && big[indx_big + indx_lit] == little[indx_lit])
			indx_lit++;
		if (little[indx_lit] == '\0')
			return ((char *) &big[indx_big]);
		indx_big++;
		indx_lit = 0;
	}
	return (NULL);
}

void	free_all(char **s, int ptrs)
{
	int	indx;

	indx = 0;
	while (indx < ptrs)
	{
		free (s[indx]);
		indx++;
	}
	free(s);
}

int	num_of_word(char *s, char c)
{
	int		indx;
	int		len;

	indx = 0;
	len = 0;
	if (s[indx] == '\0')
		return (0);
	while (s[indx])
	{
		if (s[indx] != c)
		{
			len++;
			while (s[indx] != c && s[indx])
				indx++;
			indx--;
		}
		indx++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**spl;
	int		r_s_e_c[4];

	if (!s)
		return (NULL);
	r_s_e_c[0] = -1;
	r_s_e_c[1] = 0;
	r_s_e_c[2] = 0;
	r_s_e_c[3] = num_of_word((char *)s, c);
	spl = (char **) ft_calloc ((r_s_e_c[3] + 1), sizeof(char *));
	if (!spl)
		return (NULL);
	while (++r_s_e_c[0] < r_s_e_c[3])
	{
		while (s[r_s_e_c[2]] && s[r_s_e_c[2]] == c)
			r_s_e_c[2]++;
		r_s_e_c[1] = r_s_e_c[2];
		while (s[r_s_e_c[2]] && s[r_s_e_c[2]] != c)
			r_s_e_c[2]++;
		spl[r_s_e_c[0]] = ft_substr(s, r_s_e_c[1], (r_s_e_c[2] - r_s_e_c[1]));
		if (!spl[r_s_e_c[0]])
			return (free_all(spl, r_s_e_c[3]), NULL);
		r_s_e_c[1] = r_s_e_c[2];
	}
	return (spl);
}
