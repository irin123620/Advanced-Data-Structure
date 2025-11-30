#include <stdio.h>

// Function to search an element in array
int search(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // return index if found
        }
    }
    return -1; // return -1 if not found
}

int main() {
    int n, key, result;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    result = search(arr, n, key);

    if (result != -1)
        printf("%d found at position %d\n", key, result + 1); // position starts from 1
    else
        printf("%d not found in the array\n", key);

    return 0;
}
