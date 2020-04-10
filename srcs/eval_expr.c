
#include "../includes/eval_expr.h"
#include <stdio.h>

int		ft_strlen(char *str)
{
	int cnt;
	int i;

	cnt = 0;
	i = 0;
	while (str[i++])
		cnt++;
	return (cnt);
}

char	*skip_space(char *spacestr, char *nospace)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	//*nospace = (char*)malloc(sizeof(char) * (ft_strlen(spacestr) + 1));
	//printf("%p\n", nospace);
	while (spacestr[i])
	{
		if (spacestr[i] == ' ')
		{
			while (spacestr[i] == ' ')
			{
				i++;
			}
		}
		nospace[j] = spacestr[i];
		j++;
		i++;
	}
	nospace[j] = '\0';
	return (nospace);
}

int		eval_expr(char *str)
{
	int		*value;
	int		*priority;
	char	*nospace;
	char	*operator;
	int		opcnt;

	nospace = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
	//printf("%p\n", nospace);
	nospace = skip_space(str, nospace);
	//printf("%p\n", nospace);
	//value = (int*)malloc(sizeof(int) * ((ft_strlen)(nospace) + 1));
	value = in_value(nospace, &value);
	//operator = (char*)malloc(sizeof(char) * (ft_strlen(nospace) + 1));
	operator = in_operator(nospace, &operator);
	//priority = (int*)malloc(sizeof(int) * (ft_strlen(nospace) + 1));
	priority = in_priority(nospace, &priority);
	opcnt = in_opcnt(nospace);
	opcnt = calc(opcnt, value, priority, operator);
	free(nospace);
	free(value);
	free(operator);
	free(priority);
	return (opcnt);
}
