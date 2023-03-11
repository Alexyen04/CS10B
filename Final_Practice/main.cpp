#include <iostream>

using namespace std;

void Merge(int numbers[], int , int , int );
void MergeSort(int numbers[], int , int );
void Display(int[], int);

int main(){
    // double x[3] = {1.1, 2.2, 3.3};
    int size = 6;
    int arr[size] {-3,4,2,9,5,7};

    Display(arr,size);
    cout << endl;

    MergeSort(arr, 0, 5);

    Display(arr,size);
    cout << endl;
    
    return 0;
}

void Merge(int numbers[], int front, int mid, int end){

}

void MergeSort(int numbers[], int front, int end){
    int mid = 0;
    if(front < end){
        mid = (front+end)/2;
        MergeSort(numbers, front, mid);
        MergeSort(numbers, mid+1, end);
    }
}

void Display(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}




