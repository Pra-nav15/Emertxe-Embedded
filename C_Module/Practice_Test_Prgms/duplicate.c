#include <stdio.h>

int main() {
    int i, j, size, count;

    printf("Enter array size: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter array elements: ");
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unique elements: ");
    for(i = 0; i < size; i++) {
        count = 0;
        for(j = 0; j < size; j++) {
            if(arr[i] == arr[j] && i != j) {
                count = 1;
                break;
            }
        }
        if(count == 0) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
