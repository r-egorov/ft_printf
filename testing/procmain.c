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

	/*printf("================\n");
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
	int	*ptr = &result;
	printf("TESTING POINTER (NO FLAG)\n");
	printf("result =\t%d\n", printf("|%p|\t", ptr));
	printf("ft_result\t= %d\n", ft_printf("|%p|\t", ptr));
	printf("result =\t%d\n", printf("|%20p|\t", ptr));
	printf("ft_result\t= %d\n", ft_printf("|%20p|\t", ptr));
	printf("result =\t%d\n", printf("|%30.20p|\t", ptr));
	printf("ft_result\t= %d\n", ft_printf("|%30.20p|\t", ptr));
	printf("+--------------+\n");
	printf("TESTING POINTER (MINUS FLAG)\n");
	printf("result =\t%d\n", printf("|%-20p|\t", ptr));
	printf("ft_result\t= %d\n", ft_printf("|%-20p|\t", ptr));
	printf("result =\t%d\n", printf("|%-30p|\t", ptr));
	printf("ft_result\t= %d\n", ft_printf("|%-30p|\t", ptr));
	printf("result =\t%d\n", printf("|%-30.20p|\t", ptr));
	printf("ft_result\t= %d\n", ft_printf("|%-30.20p|\t", ptr));
	printf("+--------------+\n");
	printf("TESTING POINTER (ZERO FLAG)\n");
	printf("result =\t%d\n", printf("|%030p|\t", ptr));
	printf("ft_result\t= %d\n", ft_printf("|%030p|\t", ptr));
	printf("result =\t%d\n", printf("|%040.15p|\t", ptr));
	printf("ft_result\t= %d\n", ft_printf("|%040.15p|\t", ptr));
	printf("result =\t%d\n", printf("|%010.40p|\t", ptr));
	printf("ft_result\t= %d\n", ft_printf("|%010.40p|\t", ptr));
	printf("================\n");
	printf("TESTING HEX (NO FLAG)\n");
	printf("result\t\t= %d\n", printf("|%20x|\t", 4325));
	printf("ft_result\t= %d\n", ft_printf("|%20x|\t", 4325));
	printf("result\t\t= %d\n", printf("|%20X|\t", 4325));
	printf("ft_result\t= %d\n", ft_printf("|%20X|\t", 4325));
	printf("result\t\t= %d\n", printf("|%10.15x|\t", 4325));
	printf("ft_result\t= %d\n", ft_printf("|%10.15x|\t", 4325));
	printf("result\t\t= %d\n", printf("|%20.15x|\t", 4325));
	printf("ft_result\t= %d\n", ft_printf("|%20.15x|\t", 4325));
	printf("+--------------+\n");
	printf("TESTING HEX (ZERO FLAG)\n");
	printf("result\t\t= %d\n", printf("|%020.15x|\t", 4325));
	printf("ft_result\t= %d\n", ft_printf("|%020.15x|\t", 4325));
	printf("result\t\t= %d\n", printf("|%020X|\t", 4325));
	printf("ft_result\t= %d\n", ft_printf("|%020X|\t", 4325));
	printf("result\t\t= %d\n", printf("|%010x|\t", 4325));
	printf("ft_result\t= %d\n", ft_printf("|%010x|\t", 4325));
	printf("result\t\t= %d\n", printf("|%010.20x|\t", 4325));
	printf("ft_result\t= %d\n", ft_printf("|%010.20x|\t", 4325));
	printf("+--------------+\n");
	printf("TESTING HEX (MINUS FLAG)\n");
	printf("result\t\t= %d\n", printf("|%-20.15x|\t", 4325));
	printf("ft_result\t= %d\n", ft_printf("|%-20.15x|\t", 4325));
	printf("result\t\t= %d\n", printf("|%-20X|\t", 4325));
	printf("ft_result\t= %d\n", ft_printf("|%-20X|\t", 4325));
	printf("result\t\t= %d\n", printf("|%-010x|\t", 4325));
	printf("ft_result\t= %d\n", ft_printf("|%-010x|\t", 4325));
	printf("result\t\t= %d\n", printf("|%0-10.20x|\t", 4325));
	printf("ft_result\t= %d\n", ft_printf("|%0-10.20x|\t", 4325));
	printf("================\n");*/
	printf("TESTING INT (NO FLAG)\n");
	printf("result\t\t= %d\n", printf("|%20.15d|\t", 4325));
	printf("ft_result\t= %d\n", ft_printf("|%20.15d|\t", 4325));
	printf("result\t\t= %d\n", printf("|%20.10d|\t", -10500));
	printf("ft_result\t= %d\n", ft_printf("|%20.10d|\t", -10500));
	printf("result\t\t= %d\n", printf("|%20i|\t", -20945));
	printf("ft_result\t= %d\n", ft_printf("|%20i|\t", -20945));
	printf("+--------------+\n");
	printf("TESTING INT (MINUS FLAG)\n");
	printf("result\t\t= %d\n", printf("|%-20.15d|\t", 4325));
	printf("ft_result\t= %d\n", ft_printf("|%-20.15d|\t", 4325));
	printf("result\t\t= %d\n", printf("|%-20.10d|\t", -10500));
	printf("ft_result\t= %d\n", ft_printf("|%-20.10d|\t", -10500));
	printf("result\t\t= %d\n", printf("|%-20i|\t", -20945));
	printf("ft_result\t= %d\n", ft_printf("|%-20i|\t", -20945));
	printf("+--------------+\n");
	printf("TESTING INT (ZERO FLAG)\n");
	printf("result\t\t= %d\n", printf("|%020d|\t", 4325));
	printf("ft_result\t= %d\n", ft_printf("|%020d|\t", 4325));
	printf("result\t\t= %d\n", printf("|%015d|\t", -10500));
	printf("ft_result\t= %d\n", ft_printf("|%015d|\t", -10500));
	printf("result\t\t= %d\n", printf("|%020i|\t", -20945));
	printf("ft_result\t= %d\n", ft_printf("|%020i|\t", -20945));
	printf("================\n");
}
