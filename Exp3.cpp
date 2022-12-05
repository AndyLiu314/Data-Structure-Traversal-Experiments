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

int main(){
    LL_t* list = LLcreate();
    if (list == NULL)
        return -1;

    int N = 10;
    while(N>0) {
        LL_add_to_head(list, N);
        N--;
    }

    LL_print(list);
    LL_free(list);
    return 0;
}
