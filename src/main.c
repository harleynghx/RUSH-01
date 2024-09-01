#include "functions.h"

static int *get_numbers(char *str)
{
	int i;
	int j;
	int *tab;

	if (!(tab = malloc(sizeof(int) * 16)))
		return (0);
	i = -1;
	j = 0;
	while (str[++i] != '\0')
		if (str[i] >= '0' && str[i] <= '9')
			tab[j++] = ft_atoi(str + i);
	return (tab);
}

int static solve(int tab[4][4], int entry[16], int pos)
{
	int size;

	if (pos == 16)
		return (1);
	size = 0;
	while (++size <= 4)
	{
		//checking if the number I want to place is correct
		if (check_double(tab, pos, size) == 0)
		{
			tab[pos / 4][pos % 4] = size;
			//checking if the tab is correct with the new number
			if (check_case(tab, pos, entry) == 0)
			{
				//checking for next possibility
				if (solve(tab, entry, pos + 1) == 1)
					return (1);
			}
			else
				tab[pos / 4][pos % 4] = 0;
		}
	}
	//did not find any solutions
	return (0);
}

static void display_solution(int tab[4][4])
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ft_putnbr(tab[i][j]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int main(int ac, char **av)
{
	int tab[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	};
	int *entry;

	if (ac != 2)
		return (0);
	if (ft_strlen(av[1]) != 31)
		return (0);
	entry = get_numbers(av[1]);

	if (solve(tab, entry, 0) == 1)
		display_solution(tab);
	else
		ft_putstr("Did not find any solutions\n");
	return (0);
}
