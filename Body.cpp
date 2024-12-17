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
    Loc g;
    location = &g;
    Vel h;
    velocity = &h;

    location->x = 0;
    location->y = 1;
    location->z = 2;

    velocity->x = 3;
    velocity->y = 4;
    velocity->z = 5;
    
};

// Body::Body(){cout << "gotcha\n";};

void Body::displayInfo(){
    cout << "name:" << name << ", mass: " << mass << "\n";
};