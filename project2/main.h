#ifndef MAIN_H
#define MAIN_H

#include"heap.h"
#include"util.h"

int nextCommand(int *i, int *v, int *f, int *n, int *k);
HEAP initialze(int n);
void printHeap(HEAP heap);
void BuildHeap(HEAP heap, ELEMENT* A, int n, int flag);
void Insert(HEAP heap, int k, int flag);
ELEMENT DeleteMax(HEAP heap, int flag);
void IncreaseKey(HEAP heap, int index, int value, int flag);

#endif
