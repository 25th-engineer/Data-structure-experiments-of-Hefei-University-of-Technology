//Heap sort
#include <stdio.h>
#include <stdlib.h>
typedef struct MaxHeap {
  int len;
  int *arr;
} heap;

void printArray(int arr[], int len) {
  for (int i = 0; i < len; i++)
    printf("%d ", arr[i]);

  printf("\n");
}
void swap(int *i, int *j) {
  int temp = *i;
  *i = *j;
  *j = temp;
}
void heapify(heap *maxheap, int N) {
  int largest = N;
  int left = 2 * N + 1;
  int right = 2 * N + 2;

  if(left < maxheap -> len && maxheap -> arr[left] > maxheap -> arr[largest]) {
    largest = left;
  }

  if(right < maxheap -> len && maxheap -> arr[right] > maxheap -> arr[largest]) {
    largest = right;
  }

  if(largest != N) {
    swap(&maxheap -> arr[largest], &maxheap -> arr[N]);
    heapify(maxheap, largest);
  }
}
heap* createHeap(int arr[], int N) {
  heap* maxheap = (heap*)malloc(sizeof(heap));
  maxheap -> len = N;
  maxheap -> arr = arr;
  int i = (maxheap -> len - 2) / 2;

  while(i >= 0) {
    heapify(maxheap, i);
    i--;
  }

  return maxheap;
}

void heapSort(int arr[], int N) {
  //creating a heap
  heap *maxheap = createHeap(arr, N);

  //Repeating the below steps till the size of the heap is 1.
  while(maxheap -> len > 1) {
    //Replacing largest element with the last item of the heap
    swap(&maxheap -> arr[0], &maxheap -> arr[maxheap -> len - 1]);
    maxheap -> len--;//Reducing the heap size by 1
    heapify(maxheap, 0);
  }
}
int main() {
  int arr[] = {9, 4, 8, 3, 1, 2, 5};
  int len = sizeof(arr) / sizeof(int);
  printf("Initial Array  : ");
  printArray(arr, len);
  heapSort(arr, len);
  printf("After Sorting  : ");
  printArray(arr, len);
  return 0;
}