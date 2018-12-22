
#include <stddef.h>

#include "libft.h"
#include "nm.h"

int cmp_symtab(struct symtab *a, struct symtab *b) {
	return (ft_strcmp((char *)a->n_name, (char *)b->n_name));
}

void swap(struct symtab *a, struct symtab *b) {
	struct symtab tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort_symtab(struct symtab *arr, size_t n)
{
	size_t i;
	size_t j;
	int swapped;

	i = 0;
	while (i < n - 1) {
		swapped = 0;
		j = 0;
		while (j < n - i - 1) {
			if (cmp_symtab(&arr[j], &arr[j+1]) > 0) { // < 0?
				swap(&arr[j], &arr[j+1]);
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break;
		i++;
	}
}
