#include "minFunc.h"
const int * min(const int arr[], int arrSize) {
    if(arrSize == 0){
        return nullptr;
    } else if (arrSize <= 1){
        return arr;
    } else {
        const int *minimum = min(arr+1, arrSize-1);
        return (*arr < *minimum) ? arr : minimum; 
    }
}