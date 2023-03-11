#include <iostream>

using namespace std;

string starString(int n);
int abs_max(int[], int);

int main(){
    int maxSIZE = 5;
    int arr[maxSIZE] {1,10,9,5,-7};
    cout << "Max value: " << abs_max(arr,maxSIZE) << endl;
    return 0;
}

int abs_max(int arr[], int size){
    if(size <= 1){
        return *arr;
    } else {
        int value = abs_max(arr+1, size-1);
        return (value > abs(*arr-*(arr+1)))? value : abs(*arr-*(arr+1));
    }
}
string starString(int n){
    if(n <= 0){
        return "*";
    } else {
        return (starString(n-1) + starString(n-1));
    }
}