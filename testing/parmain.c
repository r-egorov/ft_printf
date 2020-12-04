#include <stdio.h>
#include "ft_parser.h"

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
	t_parsed	result;

	result = test_parse("-0023.34d");
	print_info(result);
	result = test_parse("-023.*X", 12);
	print_info(result);
	result = test_parse("-01.*X", 24);
	print_info(result);
	result = test_parse("-0*.324dstring", 25);
	print_info(result);
	result = test_parse("0*.256dstring", 4);
	print_info(result);
	result = test_parse("0*.*dstring", -4, -5);
	print_info(result);
}



