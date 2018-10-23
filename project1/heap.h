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

  void heapify();


};

#endif
