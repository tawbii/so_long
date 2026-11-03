/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afayad <afayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:33:00 by afayad            #+#    #+#             */
/*   Updated: 2024/08/02 17:16:02 by afayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_countfile(char *filename)
{
	char	c;
	int		count;
	int		fd;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (read(fd, &c, 1) > 0)
		count++;
	close(fd);
	return (count);
}

static char	*map2array(char *filename)
{
	char	*file;
	char	c;
	int		fd;
	int		i;
	int		file_size;

	if (ft_firstvalid(filename) != 1)
		return (NULL);
	file_size = ft_countfile(filename);
	file = malloc((file_size + 1) * sizeof(char));
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(file);
		return (NULL);
	}
	i = 0;
	while (read(fd, &c, 1) > 0)
	{
		file[i] = c;
		i++;
	}
	file[i] = '\0';
	close(fd);
	return (file);
}

char	**map2matrix(char *filename)
{
	char	*file;
	char	**mat;

	file = map2array(filename);
	if (file == NULL)
		return (NULL);
	mat = ft_split(file, '\n');
	free(file);
	return (mat);
}

/* int main()
{
    char *filename = "output.txt";  // Replace with your test file name

    // Test map2array
    char *file_content = map2array(filename);
    if (file_content == NULL)
    {
        fprintf(stderr, "Failed to read file into array.\n");
        return 1;
    }

    printf("File content as array:\n%s\n", file_content);

    // Test map2matrix
    char **matrix = map2matrix(filename);
    if (matrix == NULL)
    {
        fprintf(stderr, "Failed to read file into matrix.\n");
        free(file_content);
        return 1;
    }

    printf("File content as matrix:\n");
    for (int i = 0; matrix[i] != NULL; i++)
    {
		printf("%s\n", matrix[i]);
        free(matrix[i]);  // Free each row of matrix
    }
    free(matrix);  // Free matrix itself

    free(file_content);  // Free array of file content

    return 0;
} */