#include "so_long.h"

void ft_error_qlines(void)
{
    write(1, "Error in quantity lines\n", 24);
    exit(1);
}

void ft_error_arg(void)
{
    write(1, "Error in argument\n", 18);
    exit(1);
}

void ft_error_elements(void)
{
    write(1, "Error in element\n", 17);
    exit(1);
}

void ft_error_wall(void)
{
    write(1, "Error in wall\n", 14);
    exit(1);
}