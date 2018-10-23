#ifndef UTIL_H
#define UTIL_H

#include<iostream>
#include"heap.h"

//void test(HEAP i);
//void heapify();

int nextCommand(int *i, int *v, int *f);
HEAP initialze(int n);
void printHeap(HEAP heap);
void BuildHeap(HEAP heap, ELEMENT* A, int n, int flag);
void Insert(HEAP heap, int k, int flag);
ELEMENT DeleteMax(HEAP heap, int flag);
void IncreaseKey(HEAP heap, int index, int value, int flag);


#endif
