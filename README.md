# ft_printf
The aim of this project is to mimic the behaviour of the original printf funciton in the C language.

## Usage
Running `make all` is going to compile a `libftprintf.a` library (using the `ar` command) which contains the `ft_printf` function.

## Implemented flags and conversions

* Flags: `-0.*`
* Conversions: `cspdiuxX%` (one of them is the percent sign)

# Presentation of the project to the peers

![title image](https://github.com/r-egorov/ft_printf/blob/presentation/presentation/1.png)

![tree of the project](https://github.com/r-egorov/ft_printf/blob/presentation/presentation/2.png?raw=true)

![basic logic explained](https://github.com/r-egorov/ft_printf/blob/presentation/presentation/3.png?raw=true)

![basic logic code](https://github.com/r-egorov/ft_printf/blob/presentation/presentation/4.png?raw=true)

![num printed](https://github.com/r-egorov/ft_printf/blob/presentation/presentation/5.png?raw=true)

![ft_parse_format](https://github.com/r-egorov/ft_printf/blob/presentation/presentation/6.png?raw=true)
**Link to the code of [ft_parse_format](https://github.com/r-egorov/ft_printf/blob/master/parser/ft_parser.c)**

![ft_parse+format_how](https://github.com/r-egorov/ft_printf/blob/presentation/presentation/7.png?raw=true)

![ft_parse_flags](https://github.com/r-egorov/ft_printf/blob/presentation/presentation/9.png?raw=true)
**Link to the code of [ft_parse_flags](https://github.com/r-egorov/ft_printf/blob/master/parser/ft_parse_flags.c)**

![ft_parse_width](https://github.com/r-egorov/ft_printf/blob/presentation/presentation/11.png?raw=true)
**Link to the code of [ft_parse_width](https://github.com/r-egorov/ft_printf/blob/master/parser/ft_parse_width.c)**

![ft_parse_precision](https://github.com/r-egorov/ft_printf/blob/presentation/presentation/13.png?raw=true)
**Link to the code of [ft_parse_precision](https://github.com/r-egorov/ft_printf/blob/master/parser/ft_parse_precision.c)**

![ft_parse_type](https://github.com/r-egorov/ft_printf/blob/presentation/presentation/15.png?raw=true)
**Link to the code of [ft_parse_type](https://github.com/r-egorov/ft_printf/blob/master/parser/ft_parse_type.c)**

![ft_process_format](https://github.com/r-egorov/ft_printf/blob/presentation/presentation/17.png?raw=true)
**Link to the code of [ft_process_format](https://github.com/r-egorov/ft_printf/blob/master/parser/ft_process_format.c)**

![processing logic](https://github.com/r-egorov/ft_printf/blob/presentation/presentation/18.png?raw=true)

![processing example](https://github.com/r-egorov/ft_printf/blob/presentation/presentation/19.png?raw=true)
