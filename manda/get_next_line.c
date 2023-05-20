/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:28:46 by momihamm          #+#    #+#             */
/*   Updated: 2023/04/29 13:40:34 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//jreb tclosi fd ;

int	isthereanewline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_lenofstr(char *str, char c)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

char	*therestofline(char *str)
{
	int		indx;
	int		len;
	char	*therest;
	int		j;

	indx = 0;
	len = ft_lenofstr(str, '\0') - ft_lenofstr(str, '\n');
	therest = (char *) ft_calloc (len + 1, sizeof (char));
	j = 0;
	while (str[indx] != '\n' && str[indx])
		indx++;
	if (str[indx] == '\n')
	{
		while (str[indx])
		{
			indx++;
			therest[j] = str[indx];
			j++;
		}
	}
	return (therest);
}

char	*reading(int fd, char *buff_read)
{
	char	*readbuff;
	int		offset;

	readbuff = (char *) ft_calloc (BUFFER_SIZE + 1, sizeof (char));
	offset = 1;
	while (isthereanewline(readbuff) == 1 && offset > 0)
	{
		offset = read (fd, readbuff, BUFFER_SIZE);
		if (offset < 0)
		{
			free (readbuff);
			free (buff_read);
			return (NULL);
		}
		readbuff[offset] = '\0';
		buff_read = ft_strjoin (buff_read, readbuff);
		if (buff_read[0] == '\0')
		{
			free(buff_read);
			free (readbuff);
			return (NULL);
		}
	}
	free (readbuff);
	return (buff_read);
}

char	*get_next_line(int fd)
{
	static char		*the_buff;
	char			*the_line;
	char			*ptr_ofad;
	int				len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	the_line = reading(fd, the_buff);
	ptr_ofad = the_line;
	len = ft_lenofstr(the_line, '\0') - ft_lenofstr(the_line, '\n');
	if (!the_buff)
		free(the_buff);
	the_buff = ft_substr(the_line, ft_lenofstr(the_line, '\n') + 1, len);
	the_line = ft_substr(the_line, 0, ft_lenofstr(the_line, '\n') + 1);
	free (ptr_ofad);
	return (the_line);
}
