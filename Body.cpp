#include "Body.h"
#include <iostream>
#include <string>

using namespace std;

Body::Body(ProcessedData data){
    name = data.n;
    mass = data.m;
    radius = data.r;
    satOf = data.so;
    apogee = data.a;
    perigee = data.p;
};

// Body::Body(){cout << "gotcha\n";};

void Body::displayInfo(){
    cout << "name:" << name << ", mass: " << mass << "\n";
};