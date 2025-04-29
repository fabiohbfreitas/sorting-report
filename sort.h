#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #define SHOULD_PRINT_ARRAY

int gen_random_int() { return arc4random() % (UINT16_MAX); }

void array_random_init(int array[], int size) {
  for (int i = 0; i < size; i += 1) {
    array[i] = gen_random_int();
  }
}

void copy_array(int *source, int *dest, int size) {
  for (int i = 0; i < size; i++) {
    dest[i] = source[i];
  }
}

void print_array(int array[], int size) {
  for (int i = 0; i < size; i += 1) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

/*
    BUBBLESORT
*/

void bubblesort(int *vec, int size) {
  int current = 0;
  int next = 0;
  int aux = 0;

  for (current = 1; current < size; current++) {

    for (next = 0; next < size - 1; next++) {

      if (vec[next] > vec[next + 1]) {
        aux = vec[next];
        vec[next] = vec[next + 1];
        vec[next + 1] = aux;
      }
    }
  }
}

double timed_bubblesort(int *array, int size) {
  int *randoms_copy = (int *)malloc(sizeof(int) * size);
  copy_array(array, randoms_copy, size);
  const double timeStart = (double)clock();
#ifdef SHOULD_PRINT_ARRAY
  printf("\n\tBUBBLESORT [%d]\n", size);
  printf("\tBefore:\n");
  print_array(randoms_copy, size);
#endif
  bubblesort(randoms_copy, size);
#ifdef SHOULD_PRINT_ARRAY
  printf("\tAfter:\n");
  print_array(randoms_copy, size);
#endif
  const double timeEnd = (double)clock();
  const double timeTotal = (timeEnd - timeStart) / CLOCKS_PER_SEC;
  free(randoms_copy);
  return timeTotal;
}

/*
    MERGESORT
*/
void _merge(int *vec, int size) {
  int middle = size / 2;
  int i = 0, j = middle, k = 0;
  int aux[size];
  while (i < middle && j < size) {
    if (vec[i] <= vec[j])
      aux[k] = vec[i++];
    else
      aux[k] = vec[j++];
    k++;
  }
  if (i == middle)
    while (j < size)
      aux[k++] = vec[j++];
  else
    while (i < middle)
      aux[k++] = vec[i++];
  for (i = 0; i < size; i++)
    vec[i] = aux[i];
}

void _mergesort(int *vec, int size) {
  int middle = size / 2;
  if (size > 1) {
    _mergesort(vec, middle);
    _mergesort(vec + middle, size - middle);
    _merge(vec, size);
  }
}

double timed_mergesort(int *array, int size) {
  int *randoms_copy = (int *)malloc(sizeof(int) * size);
  copy_array(array, randoms_copy, size);
  const double timeStart = (double)clock();
#ifdef SHOULD_PRINT_ARRAY
  printf("\tMERGESORT[%d]\n", size);
  printf("\tBefore:\n");
  print_array(randoms_copy, size);
#endif
  _mergesort(randoms_copy, size);
#ifdef SHOULD_PRINT_ARRAY
  printf("\tAfter:\n");
  print_array(randoms_copy, size);
#endif
  const double timeEnd = (double)clock();
  const double timeTotal = (timeEnd - timeStart) / CLOCKS_PER_SEC;
  free(randoms_copy);
  return timeTotal;
}

/*
    QUICKSORT
*/
void _qs_swap(int *vec, int first, int second) {

  int aux = vec[first];
  vec[first] = vec[second];
  vec[second] = aux;
}

int _qs_partition(int *vec, int start, int end) {
  int pivot = 0;
  int pivotIdx = 0;
  int i = 0;

  pivot = vec[end];
  pivotIdx = start;
  for (i = start; i < end; i++) {

    if (vec[i] <= pivot) {

      _qs_swap(vec, i, pivotIdx);
      pivotIdx++;
    }
  }

  _qs_swap(vec, pivotIdx, end);

  return pivotIdx;
}

int _qs_random_partition(int *vec, int start, int end) {

  int pivotIdx = (arc4random() % (end - start + 1)) + start;

  _qs_swap(vec, pivotIdx, end);

  return _qs_partition(vec, start, end);
}

void quicksort(int *vetor, int inicio, int fim) {
  if (inicio < fim) {

    int pivoIndice = _qs_random_partition(vetor, inicio, fim);

    quicksort(vetor, inicio, pivoIndice - 1);
    quicksort(vetor, pivoIndice + 1, fim);
  }
}

double timed_quicksort(int *array, int size) {
  int *randoms_copy = (int *)malloc(sizeof(int) * size);
  copy_array(array, randoms_copy, size);
  const double timeStart = (double)clock();
#ifdef SHOULD_PRINT_ARRAY
  printf("\tQUICKSORT[%d]\n", size);
  printf("\tBefore:\n");
  print_array(randoms_copy, size);
#endif
  quicksort(randoms_copy, 0, size - 1);
#ifdef SHOULD_PRINT_ARRAY
  printf("\tAfter:\n");
  print_array(randoms_copy, size);
#endif
  const double timeEnd = (double)clock();
  const double timeTotal = (timeEnd - timeStart) / CLOCKS_PER_SEC;
  free(randoms_copy);
  return timeTotal;
}
