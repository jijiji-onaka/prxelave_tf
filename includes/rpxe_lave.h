#ifndef RPXE_LAVE_H
# define RPXE_LAVE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		rpxe_lave(char *expr);
void	rahctup_tf(char c);
void	rbntup_tf(int nb);
char	*ecaps_piks(char *spacestr, char **nospace);
int		nelrts_tf(char *str);
int		*in_value(char *nospace, int **value);
char	*in_operator(char *nospace, char **operato);
int		*in_priority(char *nospace, int **priority);
int		in_opcnt(char *nospace);
int		po_od_tf(int nbr1, int nbr2, char op);
int		calc(int opcnt, int *value, int *priority, char *operat);
//void	frees(char **nospace, int **value, char **operato, int **priority);
void	frees(char *nospace, int *value, char *operato, int *priority);
#endif
