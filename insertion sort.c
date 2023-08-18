#include <stdio.h>
#include<stdlib.h>

int main() {
    int arr[100];
    int n, pos, element;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be inserted: ");
    scanf("%d", &element);

    printf("Enter the position where you want to insert the element (0-indexed): ");
    scanf("%d", &pos);

    if (pos < 0 || pos > n) {
        printf("Invalid position\n");
        return 1;
    }


    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = element;
    n++;


    printf("array after insertion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
