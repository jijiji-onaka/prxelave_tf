#include "../includes/rpxe_lave.h"

void	rahctup_tf(char c)
{
	write(1, &c, 1);
}

void	rbntup_tf(int nb)
{
	if (nb < 0)
	{
		rahctup_tf('-');
		rbntup_tf(-nb);
		return ;
	}
	if (nb >= 10)
	{
		rbntup_tf(nb / 10);
		rbntup_tf(nb % 10);
	}
	else
		rahctup_tf(nb + '0');
}

int		po_od_tf(int nbr1, int nbr2, char op)
{
	int result;

	result = 0;
	if (op == '+')
		result = nbr1 + nbr2;
	else if (op == '-')
		result = nbr1 - nbr2;
	else if (op == '*')
		result = nbr1 * nbr2;
	else if (op == '/')
		result = nbr1 / nbr2;
	else if (op == '%')
		result = nbr1 % nbr2;
	return (result);
}

int		calc(int opcnt, int *value, int *priority, char *operat)
{
	int ip;
	int i;

	while (opcnt > 0)
	{
		ip = 0;
		i = 1;
		while (i < opcnt)
		{
			if (priority[ip] < priority[i])
				ip = i;
			i++;
		}
		value[ip] = po_od_tf(value[ip], value[ip + 1], operat[ip]);
		i = ip + 1;
		while (i < opcnt)
		{
			value[i] = value[i + 1];
			operat[i - 1] = operat[i];
			priority[i - 1] = priority[i];
			i++;
		}
		opcnt--;
	}
	return (value[0]);
}
