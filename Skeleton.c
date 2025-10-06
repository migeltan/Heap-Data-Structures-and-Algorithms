#include <stdio.h>
#include <stdlib.h>

// 1. Global variables or constants
#define MAX 100   // maximum size of heap
int heap[MAX];    // array to store heap
int size = 0;     // current size of heap

// 2. Function prototypes
void insert(int value);       // insert element into heap
void deleteRoot();            // delete the root element
void heapify(int i);          // maintain heap property
void displayHeap();           // show heap as array
void displayTree();           // optional: show as tree-like structure
void buildHeap(int arr[], int n);  // build heap from array

// 3. Insert function
// - Add element at the end
// - Bubble it up until heap property is satisfied

// 4. Delete root function
// - Replace root with last element
// - Decrease size
// - Heapify downwards

// 5. Heapify function
// - Compare node with children
// - Swap with larger (for max-heap) or smaller (for min-heap)
// - Recurse until heap property is satisfied

// 6. Display function(s)
// - Print heap as linear array
// - Optionally show parent-child relationships

// 7. Main menu (simulation)
// - Insert
// - Delete root
// - Build heap from array
// - Display heap
// - Exit

int main() {
    int choice, value;
    
    do {
        printf("\n--- Heap Simulation ---\n");
        printf("1. Insert element\n");
        printf("2. Delete root\n");
        printf("3. Display heap\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                deleteRoot();
                break;
            case 3:
                displayHeap();
                break;
            case 4:
                printf("Exiting simulation...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 4);
    
    return 0;
}
