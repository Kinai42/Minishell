#include "libft.h"

int	ft_counttab(char **tab)
{
	int	count;

	count = -1;
	while(tab[++count]);
	return(count);
}
