#ifndef HEAP_H
#define HEAP_H

typedef struct {

  int key;
  //void value;

} ELEMENT;


typedef struct {

  int capacity;
  int size;
  ELEMENT *A;


} HEAP;

int parent(int i);
void heapify(HEAP heap, int i);

#endif
