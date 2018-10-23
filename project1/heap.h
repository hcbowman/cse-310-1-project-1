#ifndef HEAP_H
#define HEAP_H

typedef struct {

  int key;
  //void value;

} ELEMENT;

class HEAP {


public:

  int capacity;
  int size;
  ELEMENT *A;

  int right(int i);
  int left(int i);
  void heapify();


};

#endif
