#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int hoare_partition(int *array, int low, int high, size_t size) {
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;

    while (1) {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j) {
            return j;
        }

        swap(&array[i], &array[j]);
        for (size_t k = 0; k < size; k++) {
            printf("%d ", array[k]);
        }
        printf("\n");
    }
}

void quick_sort(int *array, int low, int high, size_t size) {
    if (low < high) {
        int partition_index = hoare_partition(array, low, high, size);

        quick_sort(array, low, partition_index, size);
        quick_sort(array, partition_index + 1, high, size);
    }
}

void quick_sort_hoare(int *array, size_t size) {
    if (array == NULL || size < 2) {
        return; // Nothing to sort
    }

    printf("Original array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    quick_sort(array, 0, size - 1, size);
}

int main() {
    int array[] = {12, 4, 5, 6, 7, 3, 1, 15, 2, 10};
    size_t size = sizeof(array) / sizeof(array[0]);

    quick_sort_hoare(array, size);

    printf("Sorted array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
