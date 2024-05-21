#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char *str, char *charset);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

char	*dict(const char *filename)
{
	int		file;
	char	*store;
	ssize_t	size;

	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);
	store = (char *)malloc(1025 * sizeof(char));
	if (!store)
	{
		close(file);
		return (0);
	}
	size = read(file, store, 1024);
	if (size == -1)
	{
		ft_putstr("Dict Error\n");
		free(store);
		close(file);
		return (0);
	}
	store[size] = '\0';
	close(file);
	return (store);
}

char	**keyword(char *str)
{
	char	**result;
	char	*content;
	char	*charset;
	int		i;

	content = dict(str);
	charset = (char *)malloc(18 * sizeof(char));
	i = -1;
	while (++i < 10)
		charset[i] = i + '0';
	while (i < 15)
	{
		charset[i] = i - 1;
		i++;
	}
	charset[15] = ' ';
	charset[16] = ':';
	charset[17] = '\0';
	result = ft_split(content, charset);
	i = -1;
	free(charset);
	return (result);
}
/*
//	./a.out "numbers.dict" | cat -e
int	main(int argc, char **argv)
{
	int	i;
	char	**separated;
	(void)	argc;

	separated = keyword(argv[1]);
	i = -1;
	while (separated[++i])
	{
		printf("%s\n", separated[i]);
		free(separated[i]);
	}
	free(separated);
	return (0);
}
*/
