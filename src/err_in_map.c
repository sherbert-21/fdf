#include "../include/fdf.h"


int	valid_input_err(char *argv)
{
	int i;

	i = (int)ft_strlen(argv) - 1;
	if (argv[i - 3] != '.' || argv[i - 2] != 'f'
		|| argv[i - 1] != 'd' || argv[i] != 'f')
		return (err("\tERR!\n \t\t-Not '*.fdf' file"));
	return (SUCCESS);
}

int err_map_check(char *argv)
{
    char *line;
    int fd;

	ft_printf("Checking valid input...\n");
	if (!valid_input_err(argv))
	{
		line = NULL;
    	line = get_next_line(fd);
    	fd = open(argv, O_RDONLY);
   		while (line && *line)
    	{
			while (*line)
			{
				if (!(ft_isdigit(*line)) || *line != ' ')
					return (err("\tERR!\n \t\tFile contains inadmissible symbols"));
				line++;
			}
			line = get_next_line(fd);
		}
		ft_printf("\tOK!");
    	save_free(&line);
    	return (SUCCESS);
	}
	return (ERR);
}