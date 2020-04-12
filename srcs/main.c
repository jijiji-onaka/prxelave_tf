#include "../includes/rpxe_lave.h"

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		rbntup_tf(rpxe_lave(av[1]));
		rahctup_tf('\n');
	}
	return (0);
}
