#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

//global vars
int heap[MAX_SIZE];
int heapSize;
int isMaxHeap;

//forward decl
void swap(int *a, int *b); //Justin
void displayAsArray(); //Justin
void displayAsTree(); //Justin
void up_heapify(int index); //Migel
void down_heapify(int index); //Migel
void insert(int heap[], int *size, int value); //Jimmy
int findTop(int heap[]); //Jimmy
void deleteRoot(int heap[], int *size); //Jimmy
int extractTop(int heap[], int *size); //Jimmy
void menu(); //Migel

/* Migel - I was thinking na yung part ko, share na lang kayo ron tas decide kayo 
kung sino sa output, like maglalagay ng value ganern */

int main() {
    heapSize = 0;
    isMaxHeap = 1; // default: max heap

    printf("--- Heap Simulation Software ---\n");
    printf("--- Made by Group #6 | BSIT 2-4 ---\n");
    printf("Default Heap Type: MAX HEAP\n");
    menu();
    return 0;
}


void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void displayAsArray() {
    if (heapSize == 0) {
        printf("\nHeap is empty.\n");
        return;
    }

    printf("\nHeap elements (Array form):\n");
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

void displayAsTree() {
    if (heapSize == 0) {
        printf("\nHeap is empty.\n");
        return;
    }

    printf("\nHeap structure (Tree-like form):\n");
    int level = 0, count = 0, limit = 1;

    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i]);
        count++;
        if (count == limit) {
            printf("\n");
            level++;
            limit = 1 << level;
            count = 0;
        }
    }
    printf("\n");
}

//pART NI MIGEL
void up_heapify(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (isMaxHeap) {
            if (heap[index] > heap[parent])
                swap(&heap[index], &heap[parent]);
            else break;
        } else {
            if (heap[index] < heap[parent])
                swap(&heap[index], &heap[parent]);
            else break;
        }

        index = parent;
    }
}

void down_heapify(int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int target = index;

        if (left < heapSize) {
            if (isMaxHeap) {
                if (heap[left] > heap[target]) target = left;
            } else {
                if (heap[left] < heap[target]) target = left;
            }
        }

        if (right < heapSize) {
            if (isMaxHeap) {
                if (heap[right] > heap[target]) target = right;
            } else {
                if (heap[right] < heap[target]) target = right;
            }
        }

        if (target == index) break;

        swap(&heap[index], &heap[target]);
        index = target;
    }
}

void insert(int heap[], int *size, int value) {
    if (*size >= MAX_SIZE) {
        printf("Heap is full!\n");
        return;
    }

    heap[*size] = value;
    (*size)++;
    up_heapify(*size - 1);

    printf("Inserted %d successfully.\n", value);
}

int findTop(int heap[]) {
    if (heapSize == 0) {
        printf("Heap is empty!\n");
        return -1;
    }
    return heap[0];
}

void deleteRoot(int heap[], int *size) {
    if (*size <= 0) {
        printf("Heap is empty!\n");
        return;
    }

    printf("Deleted root: %d\n", heap[0]);
    swap(&heap[0], &heap[*size - 1]);

    (*size)--;
    down_heapify(0);
}

int extractTop(int heap[], int *size) {
    if (*size <= 0) {
        printf("Heap is empty!\n");
        return -1;
    }
    int top = heap[0];
    deleteRoot(heap, size);
    return top;
}


//part ni migel
void menu() {
    int choice, value;

    while (1) {
        printf("\n--------------------------\n");
        printf("        HEAP MENU\n");
        printf("--------------------------\n");
        printf("1. Insert value\n");
        printf("2. Find top\n");
        printf("3. Delete root\n");
        printf("4. Extract top\n");
        printf("5. Display as array\n");
        printf("6. Display as tree\n");
        printf("7. Switch heap type (Min/Max)\n");
        printf("8. Exit\n");
        printf("Enter a number without the period.\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(heap, &heapSize, value);
                break;

            case 2:
                value = findTop(heap);
                if (value != -1) printf("Top element: %d\n", value);
                break;

            case 3:
                deleteRoot(heap, &heapSize);
                break;

            case 4:
                value = extractTop(heap, &heapSize);
                if (value != -1) printf("Extracted: %d\n", value);
                break;

            case 5:
                displayAsArray();
                break;

            case 6:
                displayAsTree();
                break;

            case 7:
                isMaxHeap = !isMaxHeap;
                printf("Switched to %s Heap.\n", isMaxHeap ? "MAX" : "MIN");

                for (int i = heapSize / 2 - 1; i >= 0; i--)
                    down_heapify(i);
                break;

            case 8:
                printf("Exiting...\n");
                return;

            default:
                printf("Invalid choice.\n");
        }
    }
}

