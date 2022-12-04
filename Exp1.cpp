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
    clock_t start2, finish2;
    clock_t start3, finish3;
    int *a = new int[1000000];
    int *b = new int[1000000]; 
    int *c = new int[1000000]; 
    int *d = new int[1000000]; 

    start = clock();
    for (int j = 0; j<1000000; j++){
        a[j]*=3;
    }
    finish = clock();

    start1 = clock();
    for (int i = 0; i<1000000; i+=16){
        b[i]*=3;
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


    start2 = clock();
    for (int k = 0; k<1000000; k+=16){
        c[k]*=3;
        c[k+1]*=3;
        c[k+2]*=3;
        c[k+3]*=3;
        c[k+4]*=3;
        c[k+5]*=3;
        c[k+6]*=3;
        c[k+7]*=3;
        c[k+8]*=3;
        c[k+9]*=3;
        c[k+10]*=3;
        c[k+11]*=3;
        c[k+12]*=3;
        c[k+13]*=3;
        c[k+14]*=3;
        c[k+15]*=3;
    }
    finish2 = clock();

    start3 = clock();
    for (int n = 0; n<1000000; n++){
        d[n]*=3;
    }
    finish3 = clock();

    double time_taken = elapsed_time(start,finish); 
    double time_taken1 = elapsed_time(start1,finish1); 
    double time_taken2 = elapsed_time(start2,finish2);
    double time_taken3 = elapsed_time(start3,finish3);

    cout<< "---------- TEST FOR OPERATION TIME ----------" << endl;
    cout<< "Time taken for the first loop: " << time_taken << endl;
    cout<< "Time taken for the second loop: " << time_taken1 << endl;

    /*
    cout<< "---------- TEST FOR CACHE MISS TIME ----------" << endl;
    cout<< "Time taken for the first loop: " << time_taken2 << endl;
    cout<< "Time taken for the second loop: " << time_taken3 << endl;*/
}