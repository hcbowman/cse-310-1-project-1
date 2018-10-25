#include<iostream>
#include"heap.h"

using namespace std;

int parent(int i) {
  return (i / 2);
}

int right(int i){
  return (2*i) + 1;
}

int left(int i) {
  return (2*i);
}

void heapify(HEAP heap, int i) {

  int large = 0;

  int l = left(i);
  int r = right(i);

  if (l <= heap.size && heap.A[l].key > heap.A[i].key) {
    large = l;

  } else {
    large = i;
  }

  if (r <= heap.size && heap.A[r].key > heap.A[large].key) {
    large = r;
  }

  if (large != i) {
    int swap = heap.A[i].key;
    heap.A[i].key = heap.A[large].key;
    heap.A[large].key = swap;

    heapify(heap, large);

  }

}
