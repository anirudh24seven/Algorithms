#include <stdio.h>

int binarySearch(int array[], int start, int end, int valueToBeSearched) {
    if (start > end) {
        return -1;
    }

    int middle = start + (end - start)/2;

    if (array[middle] == valueToBeSearched) {
        return middle;
    }

    if (array[middle] > valueToBeSearched) {
        return binarySearch(array, start, middle - 1, valueToBeSearched);
    }

    return binarySearch(array, middle + 1, end, valueToBeSearched);
}

int main() {
    int array[] = {2, 3, 4, 10, 40};
    int n = sizeof(array) / sizeof(array[0]);

    int valueToBeSearched = 10;

    int result = binarySearch(array, 0, n-1, valueToBeSearched);

    if (result == -1) {
        printf("Element is not present in array\n");
    }
    else {
        printf("Element is present at index %d\n", result);
    }

    return 0;
}
