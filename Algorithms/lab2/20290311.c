#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void printLIS(int arr[], int lis[], int n) {
    int maxLength = 0;
    int endIndex = 0;

    for (int i = 0; i < n; i++) {
        if (lis[i] > maxLength) {
            maxLength = lis[i];
            endIndex = i;
        }
    }

    int *result = (int *)malloc(maxLength * sizeof(int));
    int currentLength = maxLength - 1;

    result[currentLength] = arr[endIndex];
    currentLength--;

    for (int i = endIndex - 1; i >= 0; i--) {
        if (arr[i] < arr[endIndex] && lis[i] == lis[endIndex] - 1) {
            result[currentLength] = arr[i];
            currentLength--;
            endIndex = i;
        }
    }

    for (int i = 0; i < maxLength; i++) {
        printf("%d", result[i]);
	if(i < maxLength-1){
	printf(",");	
	}
    }

    free(result);
}

void findLIS(int arr[], int n) {
    int lis[n];

    for (int i = 0; i < n; i++) {
        lis[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    printLIS(arr, lis, n);
}

int main() {
    int capacity = 1;  
    int size = 0;      
    int *arr = (int *)malloc(capacity * sizeof(int));

    while (scanf("%d,", &arr[size]) == 1) {
        if (++size == capacity) {
            capacity *= 2;
            arr = (int *)realloc(arr, capacity * sizeof(int));
        }
    }

    free(arr);

    return 0;
}

