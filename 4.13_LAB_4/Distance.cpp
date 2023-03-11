#include <iostream>
#include "Distance.h"
#include <math.h>
using namespace std;

Distance::Distance(){
    feet = 0;
    inches = 0;
}

Distance::Distance(unsigned ft, double in){
    feet = ft;
    inches = in;
    init();
}

Distance::Distance(double in){
    feet = 0;
    inches = in;
    init();
}

void Distance::init(){
    double temp; 
    feet = fabs(feet);
    inches = fabs(inches);
    if(inches > 12){
        feet += inches/12;
        temp = fmod(inches, 12);
        inches = temp;
        
    } 
}
unsigned Distance::getFeet() const{
    return feet;
}
double Distance::getInches() const{
    return inches;
}
double Distance::distanceInInches() const{
    return ((feet*12)+inches);
}
double Distance::distanceInFeet() const{
    return (feet + (inches/12));
}

double Distance::distanceInMeters() const{
    return (((feet*12)+inches)*0.0254);
}
Distance Distance::operator+(const Distance &rhs) const{
    Distance temp;
    temp.feet = feet + rhs.getFeet();
    temp.inches = inches + rhs.getInches();
    temp.init();
    return temp;
}
Distance Distance::operator-(const Distance &rhs) const{
    Distance temp;
    Distance rhs1;
    Distance this1;
    
    
    rhs1.feet = rhs.getFeet();
    rhs1.inches = rhs.getInches();
    
    this1.feet = feet;
    this1.inches = inches;
   
    if(rhs1.distanceInFeet() > this1.distanceInFeet()){
        if(this1.getInches() > rhs1.getInches()){
            rhs1.feet--;
            rhs1.inches += 12;
            temp.feet = rhs1.getFeet() - this1.getFeet();
            temp.inches = rhs1.getInches() - this1.getInches();
        } else {
            temp.feet = rhs1.getFeet() - this1.getFeet();
            temp.inches = rhs1.getInches() - this1.getInches();
        }
    } else if (rhs1.distanceInFeet() < this1.distanceInFeet()){ 
        if(rhs1.getInches() > this1.getInches()){
            this1.feet--;
            this1.inches += 12;
            temp.feet = this1.getFeet() - rhs1.getFeet();
            temp.inches = this1.getInches() - rhs1.getInches();
        } else {
            temp.feet = this1.getFeet() - rhs1.getFeet();
            temp.inches = this1.getInches() - rhs1.getInches();
        }
    }

    return temp;
}

ostream& operator<<(ostream &out, const Distance &rhs) {
    out << rhs.getFeet() << "' " << rhs.getInches() << "\"";
    return out;
}