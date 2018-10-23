#include <iostream>
//#include <string>
#include"heap.h"
#include"util.h"

using namespace std;
int nextCommand(int *i, int *v, int *f);
HEAP initialze(int n);
void printHeap(HEAP heap);
void BuildHeap(HEAP heap, ELEMENT* A, int n, int flag);
void Insert(HEAP heap, int k, int flag);
ELEMENT DeleteMax(HEAP heap, int flag);
void IncreaseKey(HEAP heap, int index, int value, int flag);

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

  char buffer[256];
  int i = 1;

  //open file to read
  FILE* file = fopen("HEAPinput.txt", "r");

  //check if exists
  if (!file) {
    cout << "ERROR: HEAPinput.txt does not exist or would not read." << '\n';
  } else {

    fgets(buffer, 256, file);
    int length = atoi(buffer);
    ELEMENT A* = (ELEMENT*) malloc(length);

    while (fgets(buffer, 256, file) && i < (length+1)) {

      A[i].key = atoi(buffer);
      i++

    }

  }





  HEAP heap = initialze(3);
  printHeap(heap);

//ELEMENT * A = new ELEMENT[length + 1]
// in my arrays, the first index[0] can be used to store the size of the array.
//Clion, jetbrains

  printf("Goodbye");
  exit(0);
}
