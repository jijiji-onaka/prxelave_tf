

#include "../includes/eval_expr.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	printf("%d\n", ((((1 + ((((1 - 42))))) / (435 * ((23 + 34) - 12) * 1) + 2))));
	return (0);
}
