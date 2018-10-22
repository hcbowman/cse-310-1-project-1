#ifndef HEAP_H
#define HEAP_H

typedef struct {

  int key;
  //void value;

} ELEMENT;

class Heap {


public:

  int capacity;
  int size;
  ELEMENT *A;

} HEAP;


HEAP initialze(int n);
void printHeap(HEAP heap);
void BuildHeap(HEAP heap, ELEMENT* A, int n, int flag);
void Insert(HEAP heap, int k, int flag);
ELEMENT DeleteMax(HEAP heap, int flag);
void IncreaseKey(HEAP heap, int index, int value, int flag);

#endif
