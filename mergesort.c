#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN 10

void merge(int *arr, int left, int mid, int right)
{
        int i, j, k;
        int size_1 = mid - left + 1;
        int size_2 = right - mid;

        // Temporary arrays
        int L[size_1], R[size_2];

        // Copy data to temp arrays
        for (i = 0; i < size_1; i++)
                L[i] = arr[left + i];

        for (j = 0; j < size_2; j++)
                R[j] = arr[mid + j + 1];

        i = j = 0;
        k = left;

        // Merging
        while (i < size_1 && j < size_2) {
                if (L[i] <= R[j]) {
                        arr[k] = L[i];
                        i++;
                } else {
                        arr[k] = R[j];
                        j++;
                }
                k++;
        }
        while (i < size_1) {
                arr[k] = L[i];
                i++;
                k++;
        }
        while (j < size_2) {
                arr[k] = R[j];
                j++;
                k++;
        }
}

void merge_sort(int *arr, int left, int right)
{
        if (left < right) {
                int mid = left + (right - left) / 2;
                merge_sort(arr, left, mid);
                merge_sort(arr, mid + 1, right);

                merge(arr, left, mid, right);
        }
}


int main (void)
{
        int randArray[ARRAY_LEN];

        for (int i = 0; i < ARRAY_LEN; ++i) {
                randArray[i] = rand()%10;
        }

        printf("Unsorted array: \n");
        for (int i = 0; i < ARRAY_LEN; ++i) {
                printf("%d ", randArray[i]);
        }
        printf("\n");

        merge_sort(randArray, 0, ARRAY_LEN - 1);

        printf("Sorted array: \n");
        for (int i = 0; i < ARRAY_LEN; ++i) {
                printf("%d ", randArray[i]);
        }
        printf("\n");

        return 0;
}
