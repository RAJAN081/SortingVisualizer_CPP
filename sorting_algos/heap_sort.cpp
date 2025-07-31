#include "common_visuals.h"

void inplaceHeapSort(int* input, int n) {
    for (int i = 1; i < n; i++) {
        int childIndex = i;
        int parentIndex = (childIndex - 1) / 2;
        while (childIndex > 0) {
            if (input[childIndex] > input[parentIndex]) {
                swap(input[parentIndex], input[childIndex]);
                visualize(parentIndex, childIndex);
                SDL_Delay(40);
            } else break;
            childIndex = parentIndex;
            parentIndex = (childIndex - 1) / 2;
        }
    }
    for (int heapLast = n - 1; heapLast >= 0; heapLast--) {
        swap(input[0], input[heapLast]);
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        while (leftChildIndex < heapLast) {
            int maxIndex = parentIndex;
            if (input[leftChildIndex] > input[maxIndex]) maxIndex = leftChildIndex;
            if (rightChildIndex < heapLast && input[rightChildIndex] > input[maxIndex]) maxIndex = rightChildIndex;
            if (maxIndex == parentIndex) break;
            swap(input[parentIndex], input[maxIndex]);
            visualize(maxIndex, parentIndex, heapLast);
            SDL_Delay(40);
            parentIndex = maxIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
    }
}