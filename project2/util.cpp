#include <iostream>
#include "util.h"
#include <limits.h>

/*
void test(HEAP i) {

  printf("hi");

}*/

//=============================================================================


int nextCommand(int *i, int *v, int *f, int *n, int *k)
{
  char c;
  while(1){
    scanf("%c", &c);
    if(c >= 97) {
      c = c - 32;
    }

    if (c == ' ' || c == '\t' || c == '\n'){
      continue;
    }
    if (c == 'S' || c == 'W'){
      break;
    }
    if (c == 'K'){
      scanf("%d", i); scanf("%d", v); scanf("%d", f);
      break;
    }

    if (c == 'D' || c== 'R') {
      scanf("%d", f);
      break;
    }
    if (c == 'C') {
      scanf("%d", n);
      break;
    }
    if (c == 'I') {
      scanf("%d", k); scanf("%d", f);
      break;
      }

    printf("Invalid Command\n");
  }
  return c;
}

HEAP initialze(int n) {
    /*which returns an object of type HEAP with capacity n and size 0.
    This function requires you to perform dynamic memory allocation.*/
  HEAP heap;
  heap.A = new ELEMENT[n + 1];
  heap.capacity = n;
  heap.size = 0;

  for (int i = 0; i < heap.capacity; i++) {
    heap.A[i].key = 0;
  }

  return heap;

}

void printHeap(HEAP heap) {
  /*which prints out the heap information, including capacity, size, and the
  key ﬁelds of the elements in the array with index going from 1 to heap->size*/

  printf("capacity %d\n" , heap.capacity);
  printf("size %d\n" , heap.size);

  for (int i = 0; i < heap.size; i++) {
    printf("%d\n", heap.A[i].key);
  }

}

void BuildHeap(HEAP heap, ELEMENT* A, int n, int flag){
  /*where heap is a HEAP object, A is an array of type ELEMENT, n is an int
   which represents the size of array A, and ﬂag is an int. This function copies
   the elements in A into heap->H (such that H[i]=A[i], i=1, 2, ..., n) and
   uses the linear time build heap algorithm to obtain a max-heap of size n
   from the given array A. If ﬂag=1, this function prints out the content of
   the the resulting heap. If ﬂag=2, this function prints out the content of
   the the array heap->H after each outer call to heapify. If ﬂag=0, this
   function does not do any printing.*/

  if (n > heap.capacity) {

    heap.A = (ELEMENT*) realloc(heap.A, n*sizeof(ELEMENT));
    heap.capacity = n;

  }

  for (int i = 0; i < n; i++) {

    heap.A[i+1] = A[i];

  }
  heapify(heap, 1);

  heap.size = n;

  switch (flag) {
    case 0:
    //print nothing
    break;

    case 1:
    printHeap(heap);
    break;

    case 2:
    
    break;


  }

 }

 void IncreaseKey(HEAP heap, int index, int value, int flag) {
    /*which increases the key ﬁeld of the heap element pointed to by index to
    value, which should not be smaller than the current value. Note that you
    have to make necessary adjustment to make sure that heap order is maintained.
    When ﬂag=1, the function prints out the heap content before the increase
    key operation, and the heap content after the increase key operation.
    When ﬂag=0, the function does not do any additional printing.*/

     //TODO check index to make sure that it is <= size has to be >= 1

     if (flag == 1) {
       printHeap(heap);
     }

     if (value < heap.A[index].key) {
       printf("key already smaller\n");
       return;
     } else {
       heap.A[index].key = value;

       while (index > 1 && heap.A[parent(index)].key < heap.A[index].key) {
         int swap = heap.A[index].key;
         heap.A[index].key = heap.A[parent(index)].key;
         heap.A[parent(index)].key = swap;

         index = parent(index);
       }
     }

     if (flag == 1) {
       printHeap(heap);
     }

 }

void Insert(HEAP heap, int k, int flag) {
  /*which inserts an element with key equal to k into the max-heap heap.
  When ﬂag=1, the function prints out the heap content before the insertion,
  and the heap content after the insertion. When ﬂag=0, the function does not
  do any additional printing.*/


  if (heap.size >= heap.capacity) {
    printf("ERROR: heap full\n");
    return;
  }

  if (flag == 1) {
    printHeap(heap);
  }

  heap.size +=1;
  int i = heap.size;

  heap.A[i].key = INT_MIN;
  IncreaseKey(heap, heap.size, k, 0);

  if (flag == 1) {
    printHeap(heap);
  }

}

ELEMENT DeleteMax(HEAP heap, int flag) {
  /*which deletes the element with maximum key and returns it to the caller.
  When ﬂag=1, the function prints out the heap content before the deletion,
  and the heap content after the deletion. When ﬂag=0, the function does not
  do any additional printing.*/

  ELEMENT e;
  e.key = INT_MIN;

  //TODO: put catch if size is <= 0

  if (flag == 1) {
    printHeap(heap);
  }

  if (heap.size < 1) {
    printf("ERROR: heap empty\n");
    return e;
  }

  e.key = heap.A[1].key;
  heap.A[1].key = heap.A[heap.size].key;
  heap.size -=1;
  heapify(heap, 1);

  if (flag == 1) {
    printHeap(heap);
  }

  return e;


}
