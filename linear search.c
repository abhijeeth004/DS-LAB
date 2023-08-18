#include <stdio.h>
#include<stdlib.h>

int main() {
    int size, search, found = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &search);

    for (int i = 0; i < size; i++) {
        if (arr[i] == search) {
            printf("Element %d found at index %d\n", search, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element %d not found in the array\n", search);
    }

    return 0;
}
