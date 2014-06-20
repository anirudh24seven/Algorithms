#include <stdio.h>
#include <stdlib.h>

struct MaxHeap {
    int size;
    int* array;
};

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify a Max Heap. The function assumes that everything under given root is already heap.
void maxHeapify(struct MaxHeap* maxHeap, int idx) {
    int largest = idx; // Initialize largest as root
    int left = (idx << 1) + 1; // 2*idx + 1
    int right = (idx + 1) << 1; // 2*idx + 2

    if (left < maxHeap->size && maxHeap->array[left] > maxHeap->array[largest]) {
        largest = left;
    }

    if (right < maxHeap->size && maxHeap->array[right] > maxHeap->array[largest]) {
        largest = right;
    }

    // Change root if needed
    if (largest != idx) {
        swap(&maxHeap->array[largest], &maxHeap->array[idx]);
        maxHeapify(maxHeap, largest);
    }
}

struct MaxHeap* buildMaxHeap(int *array, int size) {
    int i;
    struct MaxHeap* maxHeap = (struct MaxHeap*) malloc(sizeof(struct MaxHeap));
    maxHeap->size = size;
    maxHeap->array = array;

    for (i = (maxHeap->size - 2) / 2; i>=0; --i) {
        maxHeapify(maxHeap, i);
    }

    return maxHeap;
}

void heapSort(int* array, int size) {
    struct MaxHeap* maxHeap = buildMaxHeap(array, size);

    while (maxHeap->size > 1) {
        swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size - 1]);
        --maxHeap->size;

        maxHeapify(maxHeap, 0);
    }
}

void printArray(int* array, int size) {
    for (int i=0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

int main() {
    int array[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(array)/sizeof(array[0]);

    printf("Given array is: ");
    printArray(array, size);

    heapSort(array, size);

    printf("\n\nSorted array is: ");
    printArray(array, size);

    printf("\n\n");
    return 0;
}
