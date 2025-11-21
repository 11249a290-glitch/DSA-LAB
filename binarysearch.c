#include <stdio.h>
int binary_search(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    while (low <= high) 
{
        int mid = (low + high) / 2;
        if (arr[mid] == target)
   {
     return mid;
   } else if (arr[mid] < target) 
   {
    low = mid + 1;
    } else {
            high = mid - 1;
        }
    }
    return -1;
}
int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 23;
    int index = binary_search(arr, n, target);
    if (index != -1) {
        printf("Element %d found at index %d\n", target, index);
    } else {
        printf("Element %d not found in the array\n", target);
    }
    return 0;
}