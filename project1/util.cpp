#include "util.h"

/*
void test(HEAP i) {

  printf("hi");

}*/

//=============================================================================


int nextCommand(int *i, int *v, int *f)
{
  char c;
  while(1){
    scanf("%c", &c);
    if (c == ' ' || c == '\t' || c == '\n'){
      continue;
    }
    if (c == 'S' || c == 'R' || c == 'W'){
      break;
    }
    if (c == 'K' || c == 'k'){
      scanf("%d", i); scanf("%d", v); scanf("%d", v);
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

  for (int i = 0; i <= heap.capacity; i++) {
    heap.A[i].key = 0;
  }

  return heap;

}

void printHeap(HEAP heap) {
  /*which prints out the heap information, including capacity, size, and the
  key ﬁelds of the elements in the array with index going from 1 to heap->size*/

  printf("capacity %d\n" , heap.capacity);
  printf("size %d\n" , heap.size);

  for (int i = 1; i <= heap.capacity; i++) {
    printf("key = %d\n", heap.A[i].key);
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

  if (n <= heap.capacity) {
    heap.A = A;
  } else {
    heap.A = (ELEMENT*) realloc(heap.A, n*sizeof(ELEMENT));
    heap.capacity = n;
    heap.A = A;
  }

  switch (flag) {
    case 0:
    //print nothing
    break;

    case 1:
    printHeap(heap);
    break;

    case 2:
    //TODO
    break;


  }

 }

void Insert(HEAP heap, int k, int flag) {
  /*which inserts an element with key equal to k into the max-heap heap.
  When ﬂag=1, the function prints out the heap content before the insertion,
  and the heap content after the insertion. When ﬂag=0, the function does not
  do any additional printing.*/


  //TODO: put catch if size is >= capacity, if size is >= capacity,

  if (flag == 1) {
    printHeap(heap);
  }
  heap.A[heap.size + 1].key = k;
  heap.size +=1;
  //heapify();
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
  e.key = -1; //TODO ? does heap account for negatives??

  //TODO: put catch if size is <= 0

  if (flag == 1) {
    printHeap(heap);
  }
  e.key = heap.A[1].key;
  heap.A[1].key = 0;
  //heapify();
  heap.size -=1;
  if (flag == 1) {
    printHeap(heap);
  }

  return e;


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
    heap.A[index].key = value;
    //heapify();
    if (flag == 1) {
      printHeap(heap);
    }

}
