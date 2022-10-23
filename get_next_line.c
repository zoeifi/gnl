/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporras- <lporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:09:44 by lporras-          #+#    #+#             */
/*   Updated: 2022/10/23 13:11:42 by lporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	ssize_t	rd;
	char	*tmp;

	tmp = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (0);
	rd = 1;
	while (rd != 0 && (!ft_strchr(str, '\n')))
	{
		rd = read(fd, tmp, BUFFER_SIZE);
		if (rd == -1)
		{
			free(tmp);
			return (0);
		}
		tmp[rd] = '\0';
		str = ft_strjoin(str, tmp);
	}
	free(tmp);
	return (str);
}

char	*ft_get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i] != '\n' && str[i])
		i++;
	line = (char *)malloc (sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_save_line(char *str)
{
	char	*tmp;
	int		i;
	int		count;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	tmp = (char *)malloc(sizeof (char) * (ft_strlen(str) - i + 1));
	if (!tmp)
		return (0);
	i++;
	count = 0;
	while (str[i])
		tmp[count++] = str[i++];
	tmp[count] = '\0';
	free(str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char		*str;
	char			*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = ft_save_line(str);
	return (line);
}

int	main(void)
{
	char	*line;
	int		fd;
	int		i;
	fd = open("text.txt", O_RDONLY);
	i = 0;
	line = 0;
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	//printf("%s", line);
	// line = get_next_line(fd);
	// printf("%s", line);
	// line = get_next_line(fd);
	// printf("%s", line);
 	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	//system("leaks a.out");
	return (0);
} 