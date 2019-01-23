/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:43:02 by mbraslav          #+#    #+#             */
/*   Updated: 2019/01/23 16:43:02 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int cmp_symtab(symtab_t *a, symtab_t *b) {

    return (ft_strcmp((char *)a->n_name, (char *)b->n_name));
}

static void swap(symtab_t *a, symtab_t *b) {

    symtab_t tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void    sort_symtab(symtab_t *arr, size_t n) {

    size_t i;
    size_t j;
    int swapped;

    i = 0;
    while (i < n - 1) {
        swapped = 0;
        j = 0;
        while (j < n - i - 1) {
            if (cmp_symtab(&arr[j], &arr[j + 1]) > 0) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
            j++;
        }
        if (swapped == 0)
            break;
        i++;
    }
}
