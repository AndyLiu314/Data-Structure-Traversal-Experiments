#include <iostream>
#include <algorithm>
#include <time.h>
#include "dsexceptions.h"
using namespace std;

double elapsed_time( clock_t start, clock_t finish){ // returns elapsed time in milliseconds 
   return (finish - start)/(double)(CLOCKS_PER_SEC/1000); 
} 

int main(){
    clock_t start, finish;// used for getting the time. 
    clock_t start1, finish1;
    int *a = new int[10000000];
    int *b = new int[10000000]; 

    start = clock();
    for (int j = 0; j<10000000; j+=64){
        b[j]*=3;
    }
    finish = clock();

    start1 = clock();
    for (int i = 0; i<10000000; i+=64){
        a[i]*=3;
        a[i+1]*=3;
        a[i+2]*=3;
        a[i+3]*=3;
        a[i+4]*=3;
        a[i+5]*=3;
        a[i+6]*=3;
        a[i+7]*=3;
        a[i+8]*=3;
        a[i+9]*=3;
        a[i+10]*=3;
        a[i+11]*=3;
        a[i+12]*=3;
        a[i+13]*=3;
        a[i+14]*=3;
        a[i+15]*=3;
        
    }
    finish1 = clock();

    delete[] a;
    delete[] b;

    double time_taken = elapsed_time(start,finish); 
    double time_taken1 = elapsed_time(start1,finish1); 

    cout<< "---------- TEST FOR OPERATION TIME ----------" << endl;
    cout<< "Time taken for the first loop (Less Operations): " << time_taken << endl;
    cout<< "Time taken for the second loop (More Operations): " << time_taken1 << endl;
    return 0;
}