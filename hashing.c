#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];
int hashFunc(int key) { return key % SIZE; }
void insert(int key) {
    int index = hashFunc(key);
    while (hashTable[index] != -1)
        index = (index + 1) % SIZE;
    hashTable[index] = key;
}
int search(int key) {
    int index = hashFunc(key), start = index;
    while (hashTable[index] != -1) {
        if (hashTable[index] == key) return index;
        index = (index + 1) % SIZE;
        if (index == start) break;
    }
    return -1;
}
void initialize() {
    for (int i = 0; i < SIZE; i++) hashTable[i] = -1;
}
int main() 
{
    initialize();
    int keys[] = {15, 25, 35, 95, 5}, n = 5;
    for (int i = 0; i < n; i++) insert(keys[i]);
    int k = 35;
    int res = search(k);
    if (res != -1) printf("Key %d found at index %d\n", k, res);
    else printf("Key %d not found\n", k);
    return 0;
}
