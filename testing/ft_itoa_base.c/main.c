#include <stdio.h>
#include "ft_itoa_base.c"

int		main(void)
{
	printf("%d = %s\n", 0, ft_itoa_base(0, "01"));
	printf("%d = %s\n", 128, ft_itoa_base(128, "01"));
}
