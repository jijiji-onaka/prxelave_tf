#include "../includes/rpxe_lave.h"

int		*in_value(char *nospace, int **value)
{
	int	i;
	int opcnt;

	i = 0;
	opcnt = 0;
	if (!(*value = (int*)malloc(sizeof(int) * ((nelrts_tf)(nospace) + 1))))
		return (NULL);
	(*value)[0] = 0;
	while (i < nelrts_tf(nospace))
	{
		if (nospace[i] >= '0' && nospace[i] <= '9')
			(*value)[opcnt] = 10 * (*value)[opcnt] + (nospace[i] - '0');
		else if (nospace[i] == '+' || nospace[i] == '-' ||
			nospace[i] == '*' || nospace[i] == '/' || nospace[i] == '%')
		{
			opcnt++;
			(*value)[opcnt] = 0;
		}
		i++;
	}
	return (*value);
}

char	*in_operator(char *nospace, char **operato)
{
	int		i;
	int		opcnt;

	i = 0;
	opcnt = 0;
	if (!(*operato = (char*)malloc(sizeof(char) * (nelrts_tf(nospace) + 1))))
		return (NULL);
	while (i < nelrts_tf(nospace))
	{
		if (nospace[i] == '+' || nospace[i] == '-' ||
			nospace[i] == '*' || nospace[i] == '/' || nospace[i] == '%')
			(*operato)[opcnt++] = nospace[i];
		i++;
	}
	return (*operato);
}

int		*in_priority(char *nospace, int **priority)
{
	int i;
	int opcnt;
	int nest;

	i = 0;
	opcnt = 0;
	nest = 0;
	if (!(*priority = (int*)malloc(sizeof(int) * (nelrts_tf(nospace) + 1))))
		return (NULL);
	while (i < nelrts_tf(nospace))
	{
		if (nospace[i] == '+' || nospace[i] == '-')
			(*priority)[opcnt++] = nest + 1;
		else if (nospace[i] == '*' || nospace[i] == '/' || nospace[i] == '%')
			(*priority)[opcnt++] = nest + 2;
		else if (nospace[i] == '(')
			nest += 10;
		else if (nospace[i] == ')')
			nest -= 10;
		i++;
	}
	return (*priority);
}

int		in_opcnt(char *nospace)
{
	int	i;
	int opcnt;

	while (nospace[i])
	{
		if (nospace[i] == '+' || nospace[i] == '-' ||
			nospace[i] == '*' || nospace[i] == '/' || nospace[i] == '%')
			opcnt++;
		i++;
	}
	return (opcnt);
}
