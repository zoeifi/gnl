/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporras- <lporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:24:39 by lporras-          #+#    #+#             */
/*   Updated: 2022/10/23 13:34:45 by lporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *str)
{
	int		rd;
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
	while (str[i])
		i++;
	line = malloc (sizeof(char) * (i + 1));
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
		free (str);
		return (0);
	}
	tmp = malloc(sizeof (char) * (ft_strlen(str) - i + 1));
	if (!tmp)
		return (0);
	count = 0;
	while (str[i])
		tmp[count++] = str[++i];
	tmp[count] = '\0';
	free(str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char		*str[FILES_MAX];
	char			*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > FILES_MAX)
		return (0);
	str[fd] = ft_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_get_line(str[fd]);
	str[fd] = ft_save_line(str[fd]);
	return (line);
}

int	main(void)
{
	char	*line;
	char	*line2;
	char	*line3;
	int		fd;
	int		fd2;
	int		fd3;
	int		i;
	fd = open("text.txt", O_RDONLY);
	fd2 = open("text1.txt", O_RDONLY);
	fd3 = open("text2.txt", O_RDONLY);
	i = 0;
	line = 0;
	line2 = 0;
	line3 = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	// printf("%s", line);
	i = 0;
	line2 = get_next_line(fd2);
	while (line2 != NULL)
	{
		printf("%s", line2);
		free(line2);
		line2 = get_next_line(fd2);
		i++;
	}
	// printf("%s", line2);
	i = 0;
	line3 = get_next_line(fd3);
	while (line3 != NULL)
	{
		printf("%s", line3);
		free(line3);
		line3 = get_next_line(fd3);
		i++;
	}
	//printf("%s", line3);
	return (0);
}
