#include <stdio.h>
#include<stdio.h>

int main()
 {
    int size, target;
    printf("Enter the size of the sorted array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the sorted array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    int left = 0;
    int right = size - 1;
    int found = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            printf("Element %d found at index %d.\n", target, mid);
            found = 1;
            break;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
