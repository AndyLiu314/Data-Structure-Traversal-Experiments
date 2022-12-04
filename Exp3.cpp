#include <iostream>
#include <algorithm>
#include <time.h>
#include "dsexceptions.h"
using namespace std;

double elapsed_time( clock_t start, clock_t finish){ // returns elapsed time in milliseconds 
   return (finish - start)/(double)(CLOCKS_PER_SEC/1000); 
} 

int main(){
    
    return 0;
}
