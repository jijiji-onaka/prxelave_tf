

#include "../includes/eval_expr.h"

int		*in_value(char *nospace, int **value)
{
	int	i;
	int opcnt;

	i = 0;
	opcnt = 0;
	*value = (int*)malloc(sizeof(int) * ((ft_strlen)(nospace) + 1));
	value[0][0] = 0;
	while (i < ft_strlen(nospace))
	{
		if (nospace[i] >= '0' && nospace[i] <= '9')
			value[0][opcnt] = 10 * (value[0][opcnt]) + (nospace[i] - '0');
		else if (nospace[i] == '+' || nospace[i] == '-' ||
			nospace[i] == '*' || nospace[i] == '/' || nospace[i] == '%')
		{
			opcnt++;
			value[0][opcnt] = 0;
		}
		i++;
	}
	return (*value);
}

char	*in_operator(char *nospace, char **opera)
{
	int		i;
	int		opcnt;

	i = 0;
	opcnt = 0;
	*opera = (char*)malloc(sizeof(char) * (ft_strlen(nospace) + 1));
	while (i < ft_strlen(nospace))
	{
		if (nospace[i] == '+' || nospace[i] == '-' ||
			nospace[i] == '*' || nospace[i] == '/' || nospace[i] == '%')
			opera[0][opcnt++] = nospace[i];
		i++;
	}
	return (*opera);
}

int		*in_priority(char *nospace, int **priorit)
{
	int i;
	int opcnt;
	int nest;

	i = 0;
	opcnt = 0;
	nest = 0;
	*priorit = (int*)malloc(sizeof(int) * (ft_strlen(nospace) + 1));
	while (i < ft_strlen(nospace))
	{
		if (nospace[i] == '+' || nospace[i] == '-')
			priorit[0][opcnt++] = nest + 1;
		else if (nospace[i] == '*' || nospace[i] == '/' || nospace[i] == '%')
			priorit[0][opcnt++] = nest + 2;
		else if (nospace[i] == '(')
			nest += 10;
		else if (nospace[i] == ')')
			nest -= 10;
		i++;
	}
	return (*priorit);
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
