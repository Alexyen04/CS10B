#include <iostream>
#include <vector>

using namespace std;
void print(vector <int> v);

int main(){
    vector <int> v{4,1,3,2,0};
    cout << "Vector init: ";
    print(v);
    cout << endl;

    int temp;
    for(unsigned int i = 0; i<v.size()-1; i++){
        int minimumIndex = i;
        for (unsigned int j = i+1; j<v.size();j++){
            if(v.at(j) < v.at(minimumIndex)){
                minimumIndex = j;
            }
        }
            temp = v.at(minimumIndex);
            v.at(minimumIndex) = v.at(i);
            v.at(i) = temp;
    }

    cout << "Vector after: ";
    print(v);
    cout << endl;

    return 0;

}

void print(vector <int> v){
    for(unsigned int i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
}