#include "../include/fdf.h"


static int	valid_input_err(char *argv)
{
	int i;

	i = (int)ft_strlen(argv) - 1;
	if (argv[i - 3] != '.' || argv[i - 2] != 'f'
		|| argv[i - 1] != 'd' || argv[i] != 'f')
		return (err("\t\t  ERR!\n \t\t\t-Not '*.fdf' file"));
	return (SUCCESS);
}

int err_map_check(char *argv)
{
    char *line;
    int fd;

	ft_printf("\nChecking valid input...\n\n");
	if (!valid_input_err(argv))
	{
		line = NULL;
    	line = get_next_line(fd);
    	fd = open(argv, O_RDONLY);
   		while (line && *line)
    	{
			while (*line)
			{
				if (!(ft_isdigit(*line) || *line == ' ' || *line == '-'))
					return (err("\t\t  ERR!\n \t\t\t-Inadmissible symbols"));
				line++;
			}
			line = get_next_line(fd);
		}
		ft_printf("\t\t  OK\n");
    	save_free(&line);
    	return (SUCCESS);
	}
	return (ERR);
}