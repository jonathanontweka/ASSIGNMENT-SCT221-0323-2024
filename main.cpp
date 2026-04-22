#include <stdio.h>
#include <time.h>

#define SIZE 100

int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while(left <= right) {
        int mid = (left + right) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Hashing (simple direct addressing)
int hashTable[SIZE];

void insertHash(int key) {
    int index = key % SIZE;
    hashTable[index] = key;
}

int searchHash(int key) {
    int index = key % SIZE;
    if(hashTable[index] == key)
        return index;
    return -1;
}

int main() {
    int arr[SIZE], n, key, choice, result;
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        insertHash(arr[i]); // Insert into hash table
    }

    do {
        printf("\n--- MENU ---\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Hashing Search\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 4) break;

        printf("Enter element to search: ");
        scanf("%d", &key);

        start = clock();

        switch(choice) {
            case 1:
                result = linearSearch(arr, n, key);
                break;

            case 2:
                result = binarySearch(arr, n, key);
                break;

            case 3:
                result = searchHash(key);
                break;

            default:
                printf("Invalid choice\n");
                continue;
        }

        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        if(result != -1)
            printf("Element found!\n");
        else
            printf("Element not found.\n");

        printf("Time taken: %f seconds\n", time_taken);

    } while(1);

    return 0;
}
