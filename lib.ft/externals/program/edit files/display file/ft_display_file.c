/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:37:18 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 13:37:25 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024  // Fixed buffer size

void	ft_display_file(char *filename)
{
	int		fd;
	ssize_t	bytes_read;
	char	buf[BUF_SIZE];

	// Open the file for reading
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		if (errno == ENOENT)
			write(2, "Cannot read file\n", 17);  // File does not exist
		else if (errno == EACCES)
			write(2, "Cannot read file\n", 17);  // Permission denied
		else
			write(2, "Cannot read file\n", 17);  // Generic error message
		return;
	}

	// Read the file content and write to standard output
	while ((bytes_read = read(fd, buf, BUF_SIZE)) > 0)
	{
		write(1, buf, bytes_read);  // Write to stdout
	}

	// Check for read errors
	if (bytes_read == -1)
	{
		write(2, "Cannot read file\n", 17);
	}

	// Close the file
	close(fd);
}

int	main(int argc, char **argv)
{
	// Check for argument count
	if (argc == 1)
		write(2, "File name missing\n", 18);
	else if (argc > 2)
		write(2, "Too many arguments\n", 19);
	else
		ft_display_file(argv[1]);

	return 0;
}
