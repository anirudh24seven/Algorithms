#include <stdio.h>

int binarySearch(int array[], int start, int end, int valueToBeSearched) {
    while (start <= end) {
        int middle = start + (end - start)/2;

        if (array[middle] == valueToBeSearched) {
            return middle;
        }

        if (array[middle] < valueToBeSearched) {
            start = middle + 1;
        }
        else {
            end = middle - 1;
        }
    }

    return -1;
}

int main() {
    int array[] = {2, 3, 4, 10, 40};
    int n = sizeof(array)/sizeof(array[0]);
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
