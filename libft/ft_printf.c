/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twei-yo- <twei-yo-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 21:44:56 by twei-yo-          #+#    #+#             */
/*   Updated: 2024/09/13 21:57:12 by twei-yo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		temp;
	int		word_c;

	i = 0;
	word_c = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			temp = speci_parser(str[i + 1], args);
			if (temp >= 0)
			{
				word_c += temp;
				i += 1;
			}
			else
			{
				word_c += ft_putchar(str[i]);
				i += 2;
			}
		}
		else
			word_c += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (word_c);
}
/* int main(int argc, char const *argv[])
{
	int a = ft_printf("%p", 0);
	int b = printf("%p", 0);

	printf("\n%i, %i", a, b);
	return 0;
} */
/* int main()
{
	char			c = 'H';
	char			*str = "Im not gay";
	int				nb = 1230921;
	unsigned int	u_int = 1234;
	char			*ptr = "testing";
	int				a;
	a = printf("%cello World, %s, %i, %d, %x, %X, %u, %p, %% avc %r", 
			c, 
			str, 
			nb, 
			nb, 
			nb, 
			nb, 
			u_int, 
			ptr);
	printf("%i", a);
	printf("\n----------------------------------------------------\n");
	a = ft_printf("%cello World, %s, %i, %d, %x, %X, %u, %p, %% avc %r", 
			c, 
			str, 
			nb, 
			nb, 
			nb, 
			nb, 
			u_int, 
			ptr);
	printf("%i", a);

	return 0;
} */