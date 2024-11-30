#ifndef SORTER_H
#define SORTER_H

#include <stdio.h>
#include "comparator.h"

void merge_sort(void **base, size_t nitems, int (*compar)(const void*, const void*));

void quick_sort(void **base, size_t nitems, int (*compar)(const void*, const void*));

void merge(void **leftBase, void **rightBase, size_t nitemsLeft, size_t nitemsRight, int (*compar)(const void*, const void*));

int partition (void **base, size_t nitems, int (*compar)(const void*, const void*));

void swap(void **base, int i, int j);
#endif //SORTER_H