#include <iostream>
//#include <string>
#include"heap.h"
#include"util.h"

using namespace std;

/*

typedef struct {

  int key;
  //void value;

} ELEMENT;

typedef struct {

  int capacity;
  int size;
  ELEMENT *A;


} HEAP; */

//Don't use vectors!!
// some guy said it was taking forever becuase he is using templets? generics in java?

int main()
{
  printf("HEllo\n");


  HEAP heap = initialze(3);
  printHeap(heap);

//ELEMENT * A = new ELEMENT[length + 1]
// in my arrays, the first index[0] can be used to store the size of the array.
//Clion, jetbrains

  printf("Goodbye");
  exit(0);
}
