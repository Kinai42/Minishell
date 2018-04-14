
#include "libft.h"

void ft_cleaner(char **tab)
{
	int count;

	count = -1;
	while (tab[++count])
		free(tab[count]);
	free(tab);
}
