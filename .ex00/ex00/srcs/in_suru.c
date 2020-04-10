/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_suru.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 00:27:27 by tjinichi          #+#    #+#             */
/*   Updated: 2020/04/10 07:37:42 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/eval_expr.h"

int		*in_value(char *nospace, int *value)
{
	int	i;
	int opcnt;

	i = 0;
	opcnt = 0;
	value[0] = 0;
	while (i < ft_strlen(nospace))
	{
		if (nospace[i] >= '0' && nospace[i] <= '9')
			value[opcnt] = 10 * value[opcnt] + (nospace[i] - '0');
		else if (nospace[i] == '+' || nospace[i] == '-' ||
			nospace[i] == '*' || nospace[i] == '/' || nospace[i] == '%')
		{
			opcnt++;
			value[opcnt] = 0;
		}
		i++;
	}
	return (value);
}

char	*in_operator(char *nospace, char *operat)
{
	int		i;
	int		opcnt;

	i = 0;
	opcnt = 0;
	while (i < ft_strlen(nospace))
	{
		if (nospace[i] == '+' || nospace[i] == '-' ||
			nospace[i] == '*' || nospace[i] == '/' || nospace[i] == '%')
			operat[opcnt++] = nospace[i];
		i++;
	}
	return (operat);
}

int		*in_priority(char *nospace, int *priority)
{
	int i;
	int opcnt;
	int nest;

	i = 0;
	opcnt = 0;
	nest = 0;
	while (i < ft_strlen(nospace))
	{
		if (nospace[i] == '+' || nospace[i] == '-')
			priority[opcnt++] = nest + 1;
		else if (nospace[i] == '*' || nospace[i] == '/' || nospace[i] == '%')
			priority[opcnt++] = nest + 2;
		else if (nospace[i] == '(')
			nest += 10;
		else if (nospace[i] == ')')
			nest -= 10;
		i++;
	}
	return (priority);
}

int		in_opcnt(char *nospace)
{
	int	i;
	int opcnt;

	i = 0;
	opcnt = 0;
	while (nospace[i])
	{
		if (nospace[i] == '+' || nospace[i] == '-' ||
			nospace[i] == '*' || nospace[i] == '/' || nospace[i] == '%')
			opcnt++;
		i++;
	}
	return (opcnt);
}
