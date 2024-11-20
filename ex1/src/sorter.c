#include "../include/sorter.h"
#include <stdio.h>
#include <stdlib.h>

void merge_sort(void **base, size_t nitems, int (*compar)(const void*, const void*)){
  size_t nitemsLeft, nitemsRight;

  if (nitems > 1) {

    if (nitems % 2 == 0) {
      nitemsLeft = nitems / 2;
      nitemsRight = nitems / 2;
    } else {
      nitemsLeft = nitems / 2;
      nitemsRight = (nitems / 2) + 1;
    }

    void **rightBase = base + nitemsLeft;

    merge_sort(base, nitemsLeft, compar);
    merge_sort(rightBase, nitemsRight, compar);

    merge(base, rightBase, nitemsLeft, nitemsRight, compar);
  } else
    return;
}

void quick_sort(void **base, size_t nitems, int (*compar)(const void*, const void*)){
  if (nitems > 1) {
    int pivot = partition(base, nitems, compar);
    quick_sort(base, pivot, compar);
    quick_sort(base + pivot + 1, nitems - (pivot + 1) , compar);
  }
}

void merge(void **leftBase, void **rightBase, size_t nitemsLeft, size_t nitemsRight, int (*compar)(const void*, const void*)){
  // i->left j->right k->tmp
  int i = 0, j = 0, k = 0;

  void **temp = malloc((nitemsLeft + nitemsRight) * sizeof(void *));

  while (i < nitemsLeft && j < nitemsRight) {
    //a ccompar passo un puntatore
    if (compar(leftBase[i], rightBase[j]) >= 0) {
      temp[k] = rightBase[j];
      k++;
      j++;
    } else {
      temp[k] = leftBase[i];
      k++;
      i++;
    }
  }

  while (i < nitemsLeft) {
    temp[k] = leftBase[i];
    k++;
    i++;
  }

  while (j < nitemsRight) {
    temp[k] = rightBase[j];
    k++;
    j++;
  }

  k = 0;
  for (i = 0; i < nitemsLeft; i++, k++)
    leftBase[i] = temp[k];

  for (j = 0; j < nitemsRight; j++, k++)
    rightBase[j] = temp[k];

  free(temp);
}

int partition (void **base, size_t nitems, int (*compar)(const void*, const void*)){
  void *pivot = base[nitems-1];
  int i = -1;

  for (int j = 0; j < nitems - 1; j++) {
    if (compar(base[j], pivot) <= 0) {
      i++;
      swap(base , i, j);
    }
  }

  swap(base, i+1, nitems-1);

  return i + 1;
}

void swap(void **base, int i, int j){
  void *temp = base[i];
  base[i] = base[j];
  base[j] = temp;
}