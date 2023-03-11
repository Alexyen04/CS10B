#include <iostream>

using namespace std;

int sum(const int arr[], int size);

int main (){
    int arr[] = {3, 2, 9, 7, 4, 3, 5, 6};
    cout << "sum([3, 2, 9, 7, 4, 3, 5, 6], 8) = 39: " << sum(arr, 8) << endl;
    
    cout << *(arr+1) << endl;
    cout << *arr << endl;
    //arr + 1 is pointer to array at index 1 etc..
    return 0;
}

int sum(const int arr[], int size) {
    if (size == 0) {
        return 0;
    }
    return sum(arr + 1, size - 1) + arr[0];
}
