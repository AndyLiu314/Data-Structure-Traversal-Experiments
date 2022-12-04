#include <iostream>
#include <algorithm>
#include <time.h>
#include "dsexceptions.h"
using namespace std;

double elapsed_time( clock_t start, clock_t finish){ // returns elapsed time in milliseconds 
   return (finish - start)/(double)(CLOCKS_PER_SEC/1000); 
} 

int main(){
    clock_t start, finish ;// used for getting the time. 
    int *a = new int[1000000];
    int *b = new int[1000000]; 

    for (int i = 0; i<1000000; i++){
        a[i];
        
    }
    //cout << a[0] << endl;
    //cout << a[1] << endl;

    start = clock(); 

    finish = clock(); 
}