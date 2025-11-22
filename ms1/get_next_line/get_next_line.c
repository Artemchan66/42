/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabdull <arabdull@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:26:30 by arabdull          #+#    #+#             */
/*   Updated: 2025/11/22 15:37:48 by arabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 128
#endif

char	*get_next_line(int fd)
{
	char 	buf[BUFFER_SIZE];
	int		bytes_read;
	char 	c;
	static int current_chunk;
	static int churrent_byte_in_chunk;
	int i;
	char linei[];

	bytes_read = read(fd, buf, BUFFER_SIZE);
	i = 0;
	*line = malloc(BUFFER_SIZE);
	while (buf[i] != '\n')
	{
		line[]
	}

}
