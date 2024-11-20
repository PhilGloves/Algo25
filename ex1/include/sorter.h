#ifndef SORTER_H
#define SORTER_H

void merge_sort(void **base, size_t nitems, int (*compar)(const void*, const void*));

void quick_sort(void **base, size_t nitems, int (*compar)(const void*, const void*));

#endif //SORTER_H