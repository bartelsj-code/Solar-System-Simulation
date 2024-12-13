#include "Body.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;

Body::Body(string n, unsigned long long m, unsigned int r){
    name = n;
    mass = m;
    radius = r;
};