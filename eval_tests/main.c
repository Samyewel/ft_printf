/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:53:35 by swilliam          #+#    #+#             */
/*   Updated: 2022/08/03 14:10:59 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_tests.h"

/*
** nb_length:
** - Calculates the length of a given number.
** - Used in test functions when calculating the length of all the text
**   printed onto a line to ensure the width can always reach 80.
*/

static int	nb_length(intmax_t n)
{
	int	len;

	len = !n;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/*
** print_int_test:
** - Used for printing the numeric results of the original and remade
**   printf functions side-by-side.
*/

static void	print_int_test(char *format, intmax_t di)
{
	static int	i = 1;
	int			input_length;

	input_length = (nb_length(i) + 1) + (ft_strlen(format) + 2) + 3;
	printf("\e[4;37m#%d: \"%s\" %-*jd\e[0m\n\n", i, format, 80 - input_length, di);
	printf("\e[1;35m%-80s\e[0m\n", "Original");
	printf("|\e[0;35m\nBytes returned: %-64d\e[0m\n", printf(format, di));
	printf("\e[1;35m%-80s\e[0m\n", "Remake");
	printf("|\n\e[0;35mBytes returned: %-64d\e[0m\n", ft_printf(format, di));
	printf("\e[4;37m%-80c\e[0m\n", ' ');
	i++;
}

/*
** print_char_test:
** - Used for printing the singular character results of the original and remade
**   printf functions side-by-side.
*/

static void	print_char_test(char *format, char chr)
{
	static int	i = 1;
	int			input_length;

	input_length = (nb_length(i) + 1) + (ft_strlen(format) + 2) + 3;
	printf("\e[4;37m#%d: \"%s\" %-*lc\e[0m\n\n", i, format, 80 - input_length, chr);
	printf("\e[1;35m%-80s\e[0m\n", "Original");
	printf("|\e[4;35m\nBytes returned: %-64d\e[0m\n", printf(format, chr));
	printf("\e[1;35m%-80s\e[0m\n", "Remake");
	printf("|\n\e[4;35mBytes returned: %-64d\e[0m\n", ft_printf(format, chr));
	printf("\e[4;37m%-80c\e[0m\n", ' ');
	i++;
}

/*
** print_string_test:
** - Used for printing the character string results of the original and remade
**   printf functions side-by-side.
*/

static void	print_string_test(char *format, char *str)
{
	static int	i = 1;
	int			input_length;

	input_length = (nb_length(i) + 1) + (ft_strlen(format) + 2) + 3;
	printf("\e[4;37m#%d: \"%s\" %-*s\e[0m\n\n", i, format, 80 - input_length, str);
	printf("\e[1;35m%-80s\e[0m\n", "Original");
	printf("|\e[0;35m\nBytes returned: %-64d\e[0m\n", printf(format, str));
	printf("\e[1;35m%-80s\e[0m\n", "Remake");
	printf("|\n\e[0;35mBytes returned: %-64d\e[0m\n", ft_printf(format, str));
	printf("\e[4;37m%-80c\e[0m\n", ' ');
	i++;
}

/*
** print_percentage_test:
** - Used for printing the '%%' results of the original and remade printf
**   functions side-by-side.
*/
/*
static void	print_percentage_test(char *format)
{
	static int	i = 1;
	int			input_length;

	input_length = (nb_length(i) + 1) + (ft_strlen(format) + 2) + 3;
	printf("\e[4;37m#%d: \"%s\" %-*s\e[0m\n\n", i, format, 80 - input_length, " ");
	printf("\e[1;35m%-80s\e[0m\n", "Original");
	//printf("|\e[0;35m\nBytes returned: %-64d\e[0m\n", printf(format));
	printf("\e[1;35m%-80s\e[0m\n", "Remake");
	//printf("|\n\e[0;35mBytes returned: %-64d\e[0m\n", ft_printf(format));
	printf("\e[4;37m%-80c\e[0m\n", ' ');
	i++;
}
*/
/*
** print_float_test:
** - Used for printing the float results of the original and remade
**   printf functions side-by-side.
*/

static void	print_float_test(char *format, float n)
{
	static int	i = 1;
	int			input_length;

	input_length = (nb_length(i) + 1) + (ft_strlen(format) + 2) + 3;
	printf("\e[4;37m#%d: \"%s\" %-*f\e[0m\n\n", i, format, 80 - input_length, n);
	printf("\e[1;35m%-80s\e[0m\n", "Original");
	printf("|\e[0;35m\nBytes returned: %-64d\e[0m\n", printf(format, n));
	printf("\e[1;35m%-80s\e[0m\n", "Remake");
	printf("|\n\e[0;35mBytes returned: %-64d\e[0m\n", ft_printf(format, n));
	printf("\e[4;37m%-80c\e[0m\n", ' ');
	i++;
}

static void	print_pointer_test(char *format, void *ptr)
{
	static int	i = 1;
	int			input_length;

	input_length = (nb_length(i) + 1) + (ft_strlen(format) + 2) + 3;
	printf("\e[4;37m#%d: \"%s\" %-*p\e[0m\n\n", i, format, 80 - input_length, ptr);
	printf("\e[1;35m%-80s\e[0m\n", "Original");
	printf("|\e[0;35m\nBytes returned: %-64d\e[0m\n", printf(format, ptr));
	printf("\e[1;35m%-80s\e[0m\n", "Remake");
	printf("|\n\e[0;35mBytes returned: %-64d\e[0m\n", ft_printf(format, ptr));
	printf("\e[4;37m%-80c\e[0m\n", ' ');
	i++;
}

/*
** di_test_container:
** - Contains tests for the 'd' / 'i' conversion.
*/

static void	di_test_container(void)
{
	printf("\e[1;47m%-80s\e[0m\n", "Integers");
	print_int_test("%d", 1);
	print_int_test("%d", -1);
	print_int_test("%d", 4242);
	print_int_test("%d", -4242);
	print_int_test("%d", 2147483647);
	print_int_test("%d", -2147483647);
	print_int_test("% d", 42);
	print_int_test("% d", -42);
	print_int_test("%+d", 42);
	print_int_test("%+d", -42);
	print_int_test("%+d", 0);
	print_int_test("%++d", 42);
	print_int_test("%++d", -42);
	print_int_test("%0d", 42);
	print_int_test("%0d", -42);
	print_int_test("%00d", 42);
	print_int_test("%00d", -42);
	print_int_test("%5d", 42);
	print_int_test("%5d", -42);
	print_int_test("%05d", 42);
	print_int_test("%05d", -42);
	print_int_test("%0+5d", 42);
	print_int_test("%0+5d", -42);
	print_int_test("%-5d", 42);
	print_int_test("%-5d", -42);
	print_int_test("%4.15d", 4242);
	print_int_test("%4.15d", -4242);
	print_int_test("%-4.15d", 4242);
	print_int_test("%-4.15d", -4242);
	print_int_test("%.2d", 4242);
	print_int_test("%.2d", -4242);
	print_int_test("%-.2d", 4242);
	print_int_test("%-.2d", -4242);
	print_int_test("%.10d", 4242);
	print_int_test("%.10d", -4242);
	print_int_test("%-.10d", 4242);
	print_int_test("%-.10d", -4242);
	print_int_test("%10.5d", 4242);
	print_int_test("%10.5d", -4242);
	print_int_test("%-10.5d", 4242);
	print_int_test("%-10.5d", -4242);
	print_int_test("% 10.5d", 4242);
	print_int_test("% 10.5d", -4242);
	print_int_test("%+10.5d", 4242);
	print_int_test("%+10.5d", -4242);
	print_int_test("%-+10.5d", 4242);
	print_int_test("%-+10.5d", -4242);
	print_int_test("%03.2d", 1);
	print_int_test("%03.2d", -1);
	print_int_test("%03.2d", 0);
	print_int_test("%d", 0);
	printf("\e[1;47m%-80s\e[0m\n", "Longs");
	print_int_test("%ld", 2147483649);
	print_int_test("%d", -2147483649);
	printf("\e[1;47m%-80s\e[0m\n", "Long longs");
	print_int_test("%lld", 9223372036854775807);
	print_int_test("%lld", -9223372036854775807);
	print_int_test("%lld", -9223372036854775807 - 1);
	printf("\e[1;47m%-80s\e[0m\n", "Shorts");
	print_int_test("%hd", 32767);
	print_int_test("%hd", -32768);
	printf("\e[1;47m%-80s\e[0m\n", "Signed chars");
	print_int_test("%hhd", 127);
	print_int_test("%hhd", -127);
	print_int_test("%hhd", 128);
	print_int_test("%hhd", -128);
}

/*
** o_test_container:
** - Contains tests for the 'o' conversion.
*/

static void	o_test_container(void)
{
	printf("\e[1;47m%-80s\e[0m\n", "Octals");
	print_int_test("%o", 40);
	print_int_test("%5o", 41);
	print_int_test("%05o", 42);
	print_int_test("%-5o", 2500);
	print_int_test("%#6o", 2500);
	print_int_test("%-#6o", 2500);
	print_int_test("%-5.10o", 2500);
	print_int_test("%-10.5o", 2500);
	print_int_test("%.10o", 42);
	print_int_test("%.10o", 4242);
	print_int_test("%o", 0);
	print_int_test("%0o", 0);
	print_int_test("%5.o", 0);
	print_int_test("%5.0o", 0);
	print_int_test("%#.o", 0);
	print_int_test("%#.0o", 0);
}

/*
** u_test_container:
** - Contains tests for the 'u' conversion.
*/

static void	u_test_container(void)
{
	printf("\e[1;47m%-80s\e[0m\n", "Decimals (unsigned numbers)");
	print_int_test("%u", 1);
	print_int_test("%u", 4242);
	print_int_test("%u", 2147483647);
	print_int_test("% u", 42);
	print_int_test("%+u", 42);
	print_int_test("%+u", 0);
	print_int_test("%++u", 42);
	print_int_test("%0u", 42);
	print_int_test("%00u", 42);
	print_int_test("%5u", 42);
	print_int_test("%05u", 42);
	print_int_test("%0+5u", 42);
	print_int_test("%-5u", 42);
	print_int_test("%.5u", 42);
	print_int_test("%4.15u", 4242);
	print_int_test("%-4.15u", 4242);
	print_int_test("%.2u", 4242);
	print_int_test("%-.2u", 4242);
	print_int_test("%.10u", 4242);
	print_int_test("%-.10u", 4242);
	print_int_test("%10.5u", 4242);
	print_int_test("%-10.5u", 4242);
	print_int_test("% 10.5u", 4242);
	print_int_test("%+10.5u", 4242);
	print_int_test("%-+10.5u", 4242);
	print_int_test("%03.2u", 1);
	print_int_test("%03.2u", 0);
	print_int_test("%u", 0);
	printf("\e[1;47m%-80s\e[0m\n", "Unsigned longs");
	print_int_test("%lu", 2147483649);
	printf("\e[1;47m%-80s\e[0m\n", "Unsigned long longs");
	print_int_test("%llu", 9223372036854775807);
	printf("\e[1;47m%-80s\e[0m\n", "Unsigned shorts");
	print_int_test("%hu", 32767);
	printf("\e[1;47m%-80s\e[0m\n", "Unsigned chars");
	print_int_test("%hhu", 127);
	print_int_test("%hhu", 128);
}

/*
** x_test_container:
** - Contains tests for the 'x' conversion.
*/

static void	x_test_container(void)
{
	printf("\e[1;47m%-80s\e[0m\n", "Hexadecimals");
	print_int_test("%x", 42);
	print_int_test("%X", 42);
	print_int_test("%x", 0);
	print_int_test("%X", 0);
	print_int_test("%x", -42);
	print_int_test("%X", -42);
	print_int_test("%x", 4294967296);
	print_int_test("%X", 4294967296);
	print_int_test("%10x", 42);
	print_int_test("%-10x", 42);
	print_int_test("%lx", 4294967296);
	print_int_test("%llX", 4294967296);
	print_int_test("%hx", 4294967296);
	print_int_test("%hhX", 4294967296);
	print_int_test("%llx", 9223372036854775807);
	print_int_test("%010x", 542);
	print_int_test("%-15x", 542);
	print_int_test("%2x", 542);
	print_int_test("%.2x", 5427);
	print_int_test("%5.2x", 5427);
	print_int_test("%#x", 42);
	print_int_test("%#llx", 9223372036854775807);
	print_int_test("%#x", 0);
	print_int_test("%#x", 42);
	print_int_test("%#X", 42);
	print_int_test("%#8x", 42);
	print_int_test("%#08x", 42);
	print_int_test("%#-08x", 42);
	print_int_test("%#.x", 0);
	print_int_test("%#.0x", 0);
	print_int_test("%.x", 0);
	print_int_test("%.0x", 0);
	print_int_test("%5.x", 0);
	print_int_test("%5.0x", 0);
}

/*
** c_test_container:
** - Contains tests for the 'c' conversion.
*/

static void	c_test_container(void)
{
	printf("\e[1;47m%-80s\e[0m\n", "Chars");
	print_char_test("%c", 42);
	print_char_test("%c", 42);
	print_char_test("%5c", 42);
	print_char_test("%-5c", 42);
	print_char_test("%5.2c", 42);
	print_char_test("%-5.2c", 42);
	print_char_test("%.2c", 42);
	print_char_test("%-.2c", 42);
	print_char_test("% c", 0);
	print_char_test("%c", 0);
	print_char_test("%.2c", 0);
	print_char_test("%.2c", (char) NULL);
}

/*
** s_test_container:
** - Contains tests for the 's' conversion.
*/

static void	s_test_container(void)
{
	printf("\e[1;47m%-80s\e[0m\n", "Strings");
	print_string_test("%.2s", "test");
	print_string_test("%5.2s", "test");
	print_string_test("%-.2s", "test");
	print_string_test("%-5.2s", "test");
	print_string_test("%7.5s", "yolo");
	print_string_test("%-7.5s", "tubular");
	print_string_test("%-5s", "test");
	print_string_test("%.s", "test");
	print_string_test("%-32s", NULL);
	print_string_test("%10s", "");
	print_string_test("%-10s", "");
}

/*
** percentage_test_container:
** - Contains tests for the '%%' conversion.
*/

static void	percentage_test_container(void)
{
	printf("\e[1;47m%-80s\e[0m\n", "Percentages");
	//#1
	printf("\e[1;35m%-80s\e[0m\n", "Original");
	printf("|\e[0;35m\nBytes returned: %-64d\e[0m\n", printf("%%"));
	printf("\e[1;35m%-80s\e[0m\n", "Remake");
	printf("|\n\e[0;35mBytes returned: %-64d\e[0m\n", ft_printf("%%"));
	printf("\e[4;37m%-80c\e[0m\n", ' ');
	//#2
	printf("\e[1;35m%-80s\e[0m\n", "Original");
	printf("|\e[0;35m\nBytes returned: %-64d\e[0m\n", printf("%% %%"));
	printf("\e[1;35m%-80s\e[0m\n", "Remake");
	printf("|\n\e[0;35mBytes returned: %-64d\e[0m\n", ft_printf("%% %%"));
	printf("\e[4;37m%-80c\e[0m\n", ' ');
	//#3
	printf("\e[1;35m%-80s\e[0m\n", "Original");
	printf("|\e[0;35m\nBytes returned: %-64d\e[0m\n", printf("%5%"));
	printf("\e[1;35m%-80s\e[0m\n", "Remake");
	printf("|\n\e[0;35mBytes returned: %-64d\e[0m\n", ft_printf("%5%"));
	printf("\e[4;37m%-80c\e[0m\n", ' ');
}

/*
** e_test_container:
** - Contains tests for the 'e' conversion.
*/

static void	e_test_container(void)
{
	printf("\e[1;47m%-80s\e[0m\n", "Floats (e)");
	print_float_test("%e", (float) 0.1);
	print_float_test("%e", (float) -0.1);
	print_float_test("%e", (float) 4.12);
	print_float_test("%e", (float) -4.12);
	print_float_test("%.2e", (float) 11/3);
	print_float_test("%.2e", (float) -11/3);
	print_float_test("%.2e", (float) 4.1234);
	print_float_test("%.2e", (float) -4.1234);
	print_float_test("%3.5e", (float) 4.12345);
	print_float_test("%3.5e", (float) -4.12345);
	print_float_test("%3e", (float) 4.1234567);
	print_float_test("%3e", (float) -4.2888);
	print_float_test("%.9e", (float) 4.2999);
	print_float_test("%.9e", (float) -1234.2123456789);
	print_float_test("%0.5e", (float) 1234.2123456789);
	print_float_test("%0.5e", (float) -1234.2123456789);
	print_float_test("% 09.5e", (float) 1234.2123456789);
	print_float_test("% 09.5e", (float) -1234.2123456789);
	print_float_test("% 10.5e", (float) 1234.2123456789);
	print_float_test("% 10.5e", (float) -1234.2123456789);
}

/*
** f_test_container:
** - Contains tests for the 'f' conversion.
*/

static void	f_test_container(void)
{
	printf("\e[1;47m%-80s\e[0m\n", "Floats (f)");
	print_float_test("%f", (float) 0.1);
	print_float_test("%f", (float) -0.1);
	print_float_test("%f", (float) 4.12);
	print_float_test("%f", (float) -4.12);
	print_float_test("%f", (float) 0.1);
	print_float_test("%f", (float) 1.2);
	print_float_test("%f", (float) 1.23);
	print_float_test("%f", (float) 1.234);
	print_float_test("%f", (float) 1.2345);
	print_float_test("%.2f", (float) 11/3);
	print_float_test("%.2f", (float) -11/3);
	print_float_test("%.2f", (float) 4.1234);
	print_float_test("%.2f", (float) -4.1234);
	print_float_test("%3.5f", (float) 4.12345);
	print_float_test("%3.5f", (float) -4.12345);
	print_float_test("%3f", (float) 4.1234567);
	print_float_test("%3f", (float) -4.2888);
	print_float_test("%.9f", (float) 4.2999);
	print_float_test("%.9f", (float) -1234.2123456789);
	print_float_test("%0.5f", (float) 1234.2123456789);
	print_float_test("%0.5f", (float) -1234.2123456789);
	print_float_test("% 09.5f", (float) 1234.2123456789);
	print_float_test("% 09.5f", (float) -1234.2123456789);
	print_float_test("%0 15.5f", (float) 1234.2123456789);
	print_float_test("%0 15.5f", (float) -1234.2123456789);
	print_float_test("%0 -15.1f", (float) 1234.2123456789);
	print_float_test("%0 -15.5f", (float) -1234.2123456789);
	print_float_test("% 20.5f", (float) 1234.212);
	print_float_test("% 20.5f", (float) -1234.212);
	print_float_test("% -20.5f", (float) 1234.212);
	print_float_test("% -20.5f", (float) -1234.212);
	print_float_test("% 9f", (float) 1.2);
	print_float_test("%14f", (float) 3.5);
	print_float_test("%0 7f", (float) 4.7);
	print_float_test("% 9f", (float) -1.2);
	print_float_test("%14f", (float) -3.5);
	print_float_test("%0 7f", (float) -4.7);
	print_float_test("%f", (float) -0.0);
	print_float_test("% 15f", (float) -0.0);
	print_float_test("%015f", (float) -0.0);
	print_float_test("%-15f", (float) -0.0);
}

/*
** g_test_container:
** - Contains tests for the 'g' conversion.
*/

static void	g_test_container(void)
{
	printf("\e[1;47m%-80s\e[0m\n", "Floats (g)");
	print_float_test("%g", (float) 0.1);
	print_float_test("%g", (float) -0.1);
	print_float_test("%g", (float) 4.12);
	print_float_test("%g", (float) -4.12);
	print_float_test("%.2g", (float) 11/3);
	print_float_test("%.2g", (float) -11/3);
	print_float_test("%.2g", (float) 4.1234);
	print_float_test("%.2g", (float) -4.1234);
	print_float_test("%3.5g", (float) 4.12345);
	print_float_test("%3.5g", (float) -4.12345);
	print_float_test("%3g", (float) 4.1234567);
	print_float_test("%3g", (float) -4.2888);
	print_float_test("%.9g", (float) 4.2999);
	print_float_test("%.9g", (float) -1234.2123456789);
	print_float_test("%0.5g", (float) 1234.2123456789);
	print_float_test("%0.5g", (float) -1234.2123456789);
	print_float_test("% 09.5g", (float) 1234.2123456789);
	print_float_test("% 09.5g", (float) -1234.2123456789);
	print_float_test("% 10.5g", (float) 1234.2123456789);
	print_float_test("% 10.5g", (float) -1234.2123456789);
}

/*
** p_test_container:
** - Contains tests for the 'p' conversion.
*/

static void	p_test_container(void)
{
	int 		G = 0;
	static int	s;
	int			a;
	int			*p;

	p = malloc(sizeof(int));
	printf("\e[1;47m%-80s\e[0m\n", "Pointers");
	print_pointer_test("%1p", (void *)&G);
	print_pointer_test("%-1p", (void *)&s);
	print_pointer_test("%1p", (void *)&a);
	print_pointer_test("%-1p", (void *)&p);
	free(p);
}

/*
** draw_contents:
** - Prints a table of contents at the top of the test results so that navigation
**   of results is easier.
*/

static void	draw_contents(void)
{
	int	i;

	i = 0;
	printf("\e[40m/");
	while (i++ != 78)
		printf("-");
	printf("\\\e[0m\n");
	printf("|\e[40m%-78s\e[0m|\n", "Order of contents:");
	printf("|\e[40m%-78s\e[0m|\n", "- Integers (d / i)");
	printf("|\e[40m%-78s\e[0m|\n", "- Longs (ld / li)");
	printf("|\e[40m%-78s\e[0m|\n", "- Long longs (lld / lli)");
	printf("|\e[40m%-78s\e[0m|\n", "- Shorts (hd / hi)");
	printf("|\e[40m%-78s\e[0m|\n", "- Signed chars (hhd / hhi");
	printf("|\e[40m%-78s\e[0m|\n", "- Octals (o / O)");
	printf("|\e[40m%-78s\e[0m|\n", "- Unsigned Integers (u)");
	printf("|\e[40m%-78s\e[0m|\n", "- Unsigned longs (lu)");
	printf("|\e[40m%-78s\e[0m|\n", "- Unsigned long longs (llu)");
	printf("|\e[40m%-78s\e[0m|\n", "- Unsigned shorts (hu)");
	printf("|\e[40m%-78s\e[0m|\n", "- Unsigned chars (hhu)");
	printf("|\e[40m%-78s\e[0m|\n", "- Hexadecimals (x / X)");
	printf("|\e[40m%-78s\e[0m|\n", "- Chars (c)");
	printf("|\e[40m%-78s\e[0m|\n", "- Strings (s)");
	printf("|\e[40m%-78s\e[0m|\n", "- Percentage symbols (%%)");
	printf("|\e[40m%-78s\e[0m|\n", "- Floats (f)");
	printf("|\e[40m%-78s\e[0m|\n", "- Pointers (p)");
	printf("\e[40m\\");
	i = 0;
	while (i++ != 78)
		printf("-");
	printf("\e[0m/\n\n");
}

/*
** notify_max_terminal_lines:
** - Since the terminal in VSCode is initially limited in the total
**   lines, not of the test results will be displayed, therefore
**   a notification is printed at the bottom of the test results
**   with instructions on how to modify the maximum lines
**   the terminal can display.
*/

static void	notify_max_terminal_lines(void)
{
	int	i;

	i = 0;
	printf("\e[40m/");
	while (i++ != 78)
		printf("-");
	printf("\\\e[0m\n");
	printf("|\e[40m%-78s\e[0m|\n",
		" In order to see every test within your "
		"terminal when using VSCode, go to");
	printf("|\e[40m%-78s\e[0m|\n",
		" Preferences/settings, search \"Terminal\", "
		"edit the Osx settings.json and");
	printf("|\e[40m%-78s\e[0m|\n",
		" add the line:");
	printf("|\e[40m%-78s\e[0m|\n",
		" \"terminal.integrated.scrollback\": 100000000,");
	printf("\e[40m\\");
	i = 0;
	while (i++ != 78)
		printf("-");
	printf("\e[0m/\n");
}

/*
** main:
** - usage:
**		  - ./test
**        - ./test all
**        - ./test d / i / o / u / x / c / s / % / e / f / g / efg / p
*/

int	main(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && ft_strcmp(argv[1], "all") == 0))
	{
		draw_contents();
		di_test_container();
		o_test_container();
		u_test_container();
		x_test_container();
		c_test_container();
		s_test_container();
		percentage_test_container();
		e_test_container();
		f_test_container();
		g_test_container();
		p_test_container();
		notify_max_terminal_lines();
	}
	else if (argc == 2)
	{
		if (ft_strcmp(argv[1], "d") == 0 || ft_strcmp(argv[1], "i") == 0
			|| ft_strcmp(argv[1], "di") == 0)
			di_test_container();
		else if (ft_strcmp(argv[1], "o") == 0)
			o_test_container();
		else if (ft_strcmp(argv[1], "u") == 0)
			u_test_container();
		else if (ft_strcmp(argv[1], "x") == 0 || ft_strcmp(argv[1], "X") == 0)
			x_test_container();
		else if (ft_strcmp(argv[1], "c") == 0)
			c_test_container();
		else if (ft_strcmp(argv[1], "s") == 0)
			s_test_container();
		else if (ft_strcmp(argv[1], "%") == 0)
			percentage_test_container();
		else if (ft_strcmp(argv[1], "e") == 0)
			e_test_container();
		else if (ft_strcmp(argv[1], "f") == 0)
			f_test_container();
		else if (ft_strcmp(argv[1], "g") == 0)
			g_test_container();
		else if (ft_strcmp(argv[1], "efg") == 0)
		{
			e_test_container();
			f_test_container();
			g_test_container();
		}
		else if (ft_strcmp(argv[1], "p") == 0)
			p_test_container();
		else
			return ((int)write(1, "usage: ./test || ./test all "
					"|| ./test d / i / o / u / x / c / s / % / "
					"e / f / g / efg / p", 89));
	}
	else if (argc > 2)
		return ((int)write(1, "usage: ./test || ./test all || "
				"./test d / i / o / u / x / c / s / %", 75));
	printf("\n");
	system("leaks test");
	return (1);
}
