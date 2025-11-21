#include <stdio.h>

void improvedSelectionSort(int arr[], int n) {
    for (int i = 0; i < n/2; i++) {
        int min = i, max = i;
        for (int j = i+1; j < n-i; j++) {
            if (arr[j] < arr[min]) min = j;
            if (arr[j] > arr[max]) max = j;
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;

        if (max == i) max = min;

        temp = arr[n-i-1];
        arr[n-i-1] = arr[max];
        arr[max] = temp;
    }
}

int main() {
    int arr[100], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    
    improvedSelectionSort(arr, n);
    
    printf("Sorted array: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
}
