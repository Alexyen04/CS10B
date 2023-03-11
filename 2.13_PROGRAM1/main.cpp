#include <vector>
#include <fstream> 
#include <iostream>

using namespace std;

void readData(const string &, vector<double> &flightAngle, vector<double> &coefLift);
double interpolation(double, const vector<double> &flightAngle, const vector<double> &coefLift);
bool isOrdered(const vector<double> &v);
void reorder(vector<double> &flightAngle, vector<double> &coefLift);
void printVectors(vector<double> &flightAngle, vector<double> &coefLift);
bool angleIncluded(double angle, const vector<double> &flightAngle);

int main(int argc, char *argv[]){
    vector <double> flightAngle;
    vector <double> coefLift;
    string inputFile = argv [1];
    double angle;
    string input = "Yes";

    readData(inputFile, flightAngle, coefLift);
    if(!isOrdered(flightAngle)){
        reorder(flightAngle, coefLift);
    }

    
    while(input == "Yes"){
        cout << "Enter flight path angle: ";
        cin >> angle; 
        cout << endl;
        
        if(angle >= flightAngle.at(0) && angle <= flightAngle.back()){
            cout << "Coefficient of Lift: " << interpolation(angle, flightAngle, coefLift) << endl;
        }
        
        
        cout << "Enter another flight path angle? 'Yes' or 'No' : ";
        cin >> input;
    }
    
    return 0;
}

void readData(const string &file, vector<double> &flightAngle, vector<double> &coefLift){ //works
    ifstream inFS;
    double num;

    inFS.open(file);

    if(!inFS.is_open()){
        cout << "Error opening " << file << endl;
        exit(1);
    }   

    while(inFS >> num){
        flightAngle.push_back(num);
        inFS >> num;
        coefLift.push_back(num);
    }

}

bool isOrdered(const vector<double> &flightAngle){ //works
    bool inOrder = true;
    for(unsigned int i = 0; i+1<flightAngle.size(); i++){
        if(flightAngle[i] > flightAngle[i+1]){
            inOrder = false;
        }
    }

    return inOrder;
}

void reorder(vector<double> &flightAngle, vector<double> &coefLift){ //Whiteboard, Why does this work??
    for(unsigned int i = 0; i < flightAngle.size(); i++){
        for(unsigned int j = 0; j < flightAngle.size(); j++){
            if(flightAngle.at(j) > flightAngle.at(i)){
                swap(flightAngle.at(i), flightAngle.at(j));
                swap(coefLift.at(i), coefLift.at(j));
            }
        }
    }
}

void printVectors(vector<double> &flightAngle, vector<double> &coefLift){//helper function: test if vectors print in order
    for(unsigned int i = 0; i < flightAngle.size(); i++){
        cout <<flightAngle.at(i) << "    " << coefLift.at(i)<< endl;
    }
}

double interpolation(double angle, const vector<double> &flightAngle, const vector<double> &coefLift){
    double coef = 0;
    double s;
    double l;
    for(unsigned int i = 0; i < flightAngle.size()-1; i++){
        if((flightAngle.at(i) < angle) && (flightAngle.at(i+1) > angle)){
            s = i;
            l = i+1;
        }
    }
    if(angleIncluded(angle, flightAngle)){
        for(unsigned int i = 0; i < flightAngle.size(); i++){
            if(angle == flightAngle.at(i)){
                coef = coefLift.at(i);
            }
        }
    } else if(angle > flightAngle.at(0) && angle < flightAngle.back()){
        //f(b) = f(a) + ((b - a)/(c - a))(f(c) - f(a))
        coef = coefLift.at(s) + (((angle-flightAngle.at(s))/(flightAngle.at(l)-flightAngle.at(s)))*(coefLift.at(l)-coefLift.at(s)));
    } else if(angle == flightAngle.at(0)){
        coef = coefLift.at(0);
    } else if(angle == flightAngle.back()){
        coef = coefLift.back();
    } 
    return coef;
}

bool angleIncluded(double angle, const vector<double> &flightAngle){
    bool b = false;
    for(unsigned int i = 0; i < flightAngle.size(); i++){
            if(angle == flightAngle.at(i)){
                b = true;
            }
        }
    return b;
}

