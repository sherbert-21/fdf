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
    	fd = open(argv, O_RDONLY);
   		while (get_next_line(fd, &line))
    	{
			while (*line)
			{
				ft_printf("%c", *line);
				if (!((*line >= '0' && *line <= '9') || *line == ' ' || *line == '-'))
					return (err("\t\t  ERR!\n \t\t\t-Inadmissible symbols"));
				line++;
			}
			ft_printf("\n");
		}
		ft_printf("\t\t  OK\n");
    	save_free(&line);
    	return (SUCCESS);
	}
	return (ERR);
}