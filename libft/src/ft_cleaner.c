
#include "libft.h"

void ft_cleaner(char **tab, int count)
{
  while (--count >= 0)
    free(tab[count]);
  free(tab);
}
