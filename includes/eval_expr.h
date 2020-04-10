/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:25:26 by tjinichi          #+#    #+#             */
/*   Updated: 2020/04/10 15:32:49 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_EXPR_H
# define EVAL_EXPR_H

# include <unistd.h>
# include <stdlib.h>

int		eval_expr(char *expr);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
char	*skip_space(char *spacestr, char *nospace);
int		ft_strlen(char *str);
int		*in_value(char *nospace, int **value);
char	*in_operator(char *nospace, char **opera);
int		*in_priority(char *nospace, int **priorit);
int		in_opcnt(char *nospace);
int		ft_do_op(int nbr1, int nbr2, char op);
int		calc(int opcnt, int *value, int *priority, char *operat);

#endif
