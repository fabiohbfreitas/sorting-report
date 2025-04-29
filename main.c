#include "sort.h"

int main(void) {

  int v1[100] = {0};
  int v2[300] = {0};
  int v3[500] = {0};
  int v4[1000] = {0};
  int v5[10000] = {0};

  const unsigned long v1_size = sizeof(v1) / sizeof(v1[0]);
  array_random_init(v1, v1_size);

  const unsigned long v2_size = sizeof(v2) / sizeof(v2[0]);
  array_random_init(v2, v2_size);

  const unsigned long v3_size = sizeof(v3) / sizeof(v3[0]);
  array_random_init(v3, v3_size);

  const unsigned long v4_size = sizeof(v4) / sizeof(v4[0]);
  array_random_init(v4, v4_size);

  const unsigned long v5_size = sizeof(v5) / sizeof(v5[0]);
  array_random_init(v5, v5_size);

  const unsigned long sizes[] = {v1_size, v2_size, v3_size, v4_size, v5_size};
  int *samples[] = {v1, v2, v3, v4, v5};
  const int samples_size = sizeof(samples) / sizeof(samples[0]);

  FILE *f = fopen("sort.csv", "w");
  fprintf(f, "size,bubblesort,mergesort,quicksort\n");

  for (int i = 0; i < samples_size; i += 1) {
    const double bubble_time = timed_bubblesort(samples[i], sizes[i]);
    const double merge_time = timed_mergesort(samples[i], sizes[i]);
    const double quick_time = timed_quicksort(samples[i], sizes[i]);

    fprintf(f, "%lu,%.8f,%.8f,%.8f\n", sizes[i], bubble_time, merge_time,
            quick_time);
  }

  fclose(f);

  return EXIT_SUCCESS;
}
