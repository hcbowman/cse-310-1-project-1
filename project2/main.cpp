#include <iostream>
//#include <string>
#include"main.h"

using namespace std;


int main() {


  cout << "Hello. Project1" << '\n';

  char buffer[256];
  int ii = 0;
  //ELEMENT *A = NULL;
  HEAP heap;

  // variables for the parser...
  char c;
  int n, k;
  int i, v, f;


/*
  HEAP heap = initialze(length);
  printHeap(heap);
  BuildHeap(heap, A, length, 1);
  printHeap(heap);*/



  while(1){


    //input user command
    c = nextCommand(&i, &v, &f, &n, &k);

    switch (c) {

      case 'S':
        printf("COMMAND: %c.\n", c); exit(0);
        /* On reading S, the program stops.*/
      break;



      case 'C':
      {
        printf("COMMAND: %c %d.\n", c, n);
        /*On reading C n, the program creates an empty heap with capacity equal to n, and waits for the
        next command. */
        heap = initialze(n);
        printHeap(heap);
      }
      break;


      case 'R':
      {

        /*On reading R f, the program reads in the array A from file HEAPinput.txt, calls the linear time
        build heap algorithm to build the max-heap based on A, with flag set to f, and waits for the next
        command*/

        printf("COMMAND: %c %d.\n", c, f);


        cout << "File read" << '\n';
        cout << "......." << '\n';

        //open file to read
        FILE* file = fopen("HEAPinput.txt", "r");

        fgets(buffer, 4096, file);
        int length = atoi(buffer);

        ELEMENT *A = (ELEMENT*) malloc(length);

        while (fgets(buffer, 4096, file) && ii < (length+1)) {
          A[i].key = atoi(buffer);
          i++;
        }


        BuildHeap(heap, A, length, f);

        printf("here\n");
        //free(A);

        fclose(file);
      }

      break;


      case 'W': printf("COMMAND: %c.\n", c);
      /*On reading W, the program writes the current heap information to the screen, and waits for the
      next command. The output should be in the same format as in the file HEAPinput.txt, proceeded 2
      by the heap capacity.*/
      printHeap(heap);
      break;

      case 'I': printf("COMMAND: %c %d %d.\n", c, k, f);
      /* On reading I k f, the program inserts an element with key equal to k into the current heap with
      the corresponding flag set to f, and waits for the next command. */
      Insert(heap, k, f);

      break;


      case 'D': printf("COMMAND: %c %d.\n", c, f);
      /* On reading D f, the program deletes the maximum element from the heap with the corresponding
      flag set to f, and prints the key field of the deleted element on the screen, it waits for the next
      command. */
      DeleteMax(heap, f);


      break;



      case 'K': printf("COMMAND: %c %d %d %d.\n", c, i, v, f);
      /* On reading K i v f, the program increases the key of element with index i to v with the corresponding
      flag set to f */
      IncreaseKey(heap, i, v, f);

      break;

      default:
      break;



    }
  }


//ELEMENT * A = new ELEMENT[length + 1]
// in my arrays, the first index[0] can be used to store the size of the array.
//Clion, jetbrains

  printf("Goodbye");

}
