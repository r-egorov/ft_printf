#include <stdio.h>
#include "ft_printf.h"

void	print_info(t_parsed result)
{
	printf("==========\n");
	printf("flag = \'%c\'\n", result.flag);
	printf("width = %d\n", result.width);
	printf("precision = %d\n", result.precision);
	printf("type = \'%c\'\n", result.type);
	printf("length = %d\n", result.length);
	printf("==========\n");
}

t_parsed	test_parse(const char *format, ...)
{
	t_parsed	result;
	va_list		argptr;

	va_start(argptr, format);
	result = ft_parse_format(format, &argptr);
	va_end(argptr);
	return (result);
}

int		main(void)
{
	int		result;

	printf("================\n");
	printf("TESTING CHAR\n");
	printf("result =\t%d\n", printf("|%0*.*c|\n", -5, 2, 'z'));
	printf("ft_result =\t%d\n", ft_printf("|%0*.*c|\n", -5, 2, 'z'));
	printf("result =\t%d\n", printf("|%-*c|\n", 10, 'z'));
	printf("ft_result =\t%d\n", ft_printf("|%-*c|\n", 10, 'z'));
	printf("================\n");
	printf("TESTING STRING\n");
	printf("result =\t%d\n", printf("|%s|\t", NULL));
	printf("ft_result =\t%d\n", ft_printf("|%s|\t", NULL));
	printf("+--------------+\n");
	printf("result =\t%d\n", printf("|%10.3s|\t", NULL));
	printf("ft_result =\t%d\n", ft_printf("|%10.3s|\t", NULL));
	printf("+--------------+\n");
	printf("result(-) =\t%d\n", printf("|%-10.3s|\t", "string"));
	printf("ft_result(-)\t= %d\n", ft_printf("|%-10.3s|\t", "string"));
	printf("+--------------+\n");
	printf("result(-) =\t%d\n", printf("|%0*.*s|\t", -10, 4, "string"));
	printf("ft_result(-)\t= %d\n", ft_printf("|%0*.*s|\t", -10, 4, "string"));
	printf("================\n");
}



