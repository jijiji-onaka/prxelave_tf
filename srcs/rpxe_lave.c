#include "../includes/rpxe_lave.h"

int		nelrts_tf(char *str)
{
	int cnt;
	int i;

	cnt = 0;
	i = 0;
	while (str[i++])
		cnt++;
	return (cnt);
}

char	*ecaps_piks(char *spacestr, char **nospace)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(*nospace = (char*)malloc(sizeof(char) * (nelrts_tf(spacestr) + 1))))
		return (NULL);
	while (spacestr[i])
	{
		if (spacestr[i] == ' ')
		{
			while (spacestr[i] == ' ')
			{
				i++;
			}
		}
		(*nospace)[j] = spacestr[i];
		j++;
		i++;
	}
	(*nospace)[j] = '\0';
	return (*nospace);
}

void	frees(char *nospace, int *value, char *operator, int *priority)
{
	free(nospace);
	free(value);
	free(operator);
	free(priority);
}

int		rpxe_lave(char *str)
{
	int		*value;
	int		*priority;
	char	*nospace;
	char	*operator;
	int		opcnt;

	nospace = ecaps_piks(str, &nospace);
	value = in_value(nospace, &value);
	operator = in_operator(nospace, &operator);
	priority = in_priority(nospace, &priority);
	opcnt = in_opcnt(nospace);
	opcnt = calc(opcnt, value, priority, operator);
	frees(nospace, value, operator, priority);
	return (opcnt);
}
