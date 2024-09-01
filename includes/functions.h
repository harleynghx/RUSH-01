#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__
#include <stdlib.h>

void ft_putnbr(int nb);
void ft_putchar(char c);
void ft_putstr(char *str);
int ft_atoi(char *str);
int ft_strlen(char *str);

int check_double(int tab[4][4], int pos, int num);
int check_case(int tab[4][4], int pos, int entry[16]);

#endif