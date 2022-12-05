#include <iostream>
#include <algorithm>
#include <time.h>
#include "dsexceptions.h"
#include "LinkedList.h"
#include "UnrolledLL.h"

using namespace std;

double elapsed_time( clock_t start, clock_t finish){ // returns elapsed time in milliseconds 
   return (finish - start)/(double)(CLOCKS_PER_SEC/1000); 
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
    clock_t start, finish;// used for getting the time. 
    clock_t start1, finish1;
    clock_t start2, finish2;

    /* ************************************ */
    //unrolled linked list
    ull* newUll = new_unrolled(500, &unrolled_equality);

    for (int i = 0; i < 10000000; i++){
        insert_unrolled(i, newUll);
    }
    start = clock(); 
    printList(newUll, &printFunction);
    finish = clock();
    
    free_unrolled(newUll); 
    /* ************************************ */


    /* ************************************ */
    //linked list
    LL_t* list = LLcreate();
    if (list == NULL)
        return -1;

    int N = 10000000;
    while(N>0) {
        LL_add_to_head(list, N);
        N--;
    }
    start1 = clock(); 
    LL_print(list);
    finish1 = clock(); 

    LL_free(list);
    /* ************************************ */ 


    /* ************************************ */
    //regular array
    int *a = new int[10000000]; 
    for (int k = 0; k < 10000000; k++){
        a[k] = k; 
    }

    
    int p = 0;
    start2 = clock(); 
    for (int l = a[p]; p < 10000000; l = a[p++]){
        int temp = 2;
        int temp1 = 3;
        temp *= temp1;
    }
    finish2 = clock(); 
    /* ************************************ */

    double time_taken = elapsed_time(start,finish); 
    double time_taken1 = elapsed_time(start1,finish1); 
    double time_taken2 = elapsed_time(start2,finish2);

    cout<< "---------- TEST FOR OPERATION TIME ----------" << endl;
    cout<< "Time taken for the Unrolled Linked List: " << time_taken << endl;
    cout<< "Time taken for the Linked List: " << time_taken1 << endl;   
    cout<< "Time taken for the Array: " << time_taken2 << endl;   

    return 0;
}
