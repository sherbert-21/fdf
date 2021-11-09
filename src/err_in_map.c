#include "../include/fdf.h"

int	valid_input_err(char *argv)
{
	int i;

	i = (int)ft_strlen(argv) - 1;
	if (argv[i - 3] != '.' || argv[i - 2] != 'f'
		|| argv[i - 1] != 'd' || argv[i] != 'f')
		return (err("ERR!\n \t\t\t-Not '*.fdf' file"));
	return (SUCCESS);
}
