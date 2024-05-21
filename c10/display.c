#include <unistd.h>
#include <fcntl.h>

/* In open(filename, 0), 0 == O_RDONLY */
/* When using the result of an assignment as a condition,
	needs additonal parentheses --Line 16*/
/*read automatically moves the file pointer
to the position "immediately" after where it previously ended*/
int	display(const char *filename)
{
	int	file;
	char	c;
	ssize_t	size;

	file = open(filename, 0);
	if (file == -1)
		return (0);
	while ((size = read(file, &c, 1)))
	{
		if (size == -1)
			return (0);
		write(1, &c, 1);
	}
	close(file);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		write(2, "File name missing.\n", 19);
	else if (ac > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		if (!display(av[1]))
			write(2, "Cannot read file.\n", 18);
	}
	return (0);
}
