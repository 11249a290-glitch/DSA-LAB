#include <stdio.h>
void swap(int* a, int* b) 
{
    int t = *a; *a = *b; *b = t;
}
int partition(int arr[], int low, int high) 
{
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++)
        if (arr[j] < pivot)
            swap(&arr[++i], &arr[j]);
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
void quickSort(int arr[], int low, int high) 
{
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void merge(int arr[], int l, int m, int r) 
{
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void insertionSort(int arr[], int n) 
{
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(&arr[minIdx], &arr[i]);
    }
}
void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int arrQuick[n], arrMerge[n], arrInsert[n], arrSelect[n];
    for (int i = 0; i < n; i++) {
        arrQuick[i] = arrMerge[i] = arrInsert[i] = arrSelect[i] = arr[i];
    }
    quickSort(arrQuick, 0, n - 1);
    printf("Quick Sort: ");
    printArray(arrQuick, n);
    mergeSort(arrMerge, 0, n - 1);
    printf("Merge Sort: ");
    printArray(arrMerge, n);
    insertionSort(arrInsert, n);
    printf("Insertion Sort: ");
    printArray(arrInsert, n);
    selectionSort(arrSelect, n);
    printf("Selection Sort: ");
    printArray(arrSelect, n);
    return 0;
}
