#include "Body.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;

Body::Body(ProcessedData data){
    id = data.id;
    name = data.n;
    mass = data.m;
    radius = data.r;
    satTo = data.st;
    apogee = data.a;
    perigee = data.p;
};

void Body::displayInfo(){
    cout << id << ", name:" << name << ", mass: " << mass << "\n";
};