#include <iostream>
#include <algorithm>
#include <time.h>
#include "dsexceptions.h"
#include "LinkedList.h"
#include "UnrolledLL.h"

using namespace std;

long double elapsed_time( clock_t start, clock_t finish){ // returns elapsed time in milliseconds 
   return (finish - start)/(long double)(CLOCKS_PER_SEC/1000); 
} 

void printFunction(elem e)
{
  printf("%d ", e);
}

bool unrolled_equality(elem elem1, elem elem2)
{
  if (elem1 == elem2)
    return true;
  else
    return false;
}

int main(){
    clock_t start, finish, start1, finish1, start2, finish2;// used for getting the time. 

    /* ************************************ */
    //unrolled linked list
    ull* newUll = new_unrolled(50000, &unrolled_equality);

    for (int i = 0; i < 10000000; i++){
        insert_unrolled(i, newUll);
    }
    /* ************************************ */


    /* ************************************ */
    //linked list
    LL_t* list = LLcreate();
    if (list == NULL)
        return -1;

    for (int n = 0; n < 10000000; n++) {
        LL_add_to_head(list, n);
    }
    /* ************************************ */ 


    /* ************************************ */
    //regular array
    int *a = new int[10000000];
    for (int k = 0; k < 10000000; k++){
        a[k] = k; 
    }
    /* ************************************ */

    start = clock(); 
    printList(newUll);
    finish = clock();

    start1 = clock(); 
    LL_print(list);
    finish1 = clock(); 

    start2 = clock(); 
    for (int l = 0; l < 10000000; l++){
        a[l] += 1;
    }
    finish2 = clock(); 

    free_unrolled(newUll);
    LL_free(list);
    delete[] a;

    long double time_taken = elapsed_time(start,finish); 
    long double time_taken1 = elapsed_time(start1,finish1); 
    long double time_taken2 = elapsed_time(start2,finish2);

    cout<< "\n---------- TEST FOR OPERATION TIME ----------" << endl;
    cout<< "Time taken for the Unrolled Linked List: " << time_taken << endl;
    cout<< "Time taken for the Linked List: " << time_taken1 << endl;   
    cout<< "Time taken for the Array: " << time_taken2 << endl;   
    return 0;
}
