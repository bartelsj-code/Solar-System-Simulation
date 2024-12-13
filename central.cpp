#include "Body.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>


int main() {
    int massMultiplier = 12;  //convert masses from kg to gigatons
    vector<Body> bodies = createBodies("bodies.csv", massMultiplier);   
    
    for (int i = 0; i < 2; i++){
        cout << bodies.at(i).getRadius() << "\n";
    }

    return 0;
}