/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 00:24:10 by tjinichi          #+#    #+#             */
/*   Updated: 2020/04/10 07:35:56 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/eval_expr.h"

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

char	*skip_space(char *spacestr, char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (spacestr[i])
	{
		if (spacestr[i] == ' ')
		{
			while (spacestr[i] == ' ')
			{
				i++;
			}
		}
		str[j] = spacestr[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

int		eval_expr(char *str)
{
	int		*value;
	int		*priority;
	char	*nospace;
	char	*operator;
	int		opcnt;

	nospace = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
	nospace = skip_space(str, nospace);
	value = (int*)malloc(sizeof(int) * (ft_strlen(nospace) + 1));
	value = in_value(nospace, value);
	operator = (char*)malloc(sizeof(char) * (ft_strlen(nospace) + 1));
	operator = in_operator(nospace, operator);
	priority = (int*)malloc(sizeof(int) * (ft_strlen(nospace) + 1));
	priority = in_priority(nospace, priority);
	opcnt = in_opcnt(nospace);
	opcnt = calc(opcnt, value, priority, operator);
	free(value);
	free(priority);
	free(operator);
	free(nospace);
	return (opcnt);
}
