#include "Simulation.h"
#include "Body.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Simulation::Simulation(vector<Body> b){
    bodies = b;
    
}

void Simulation::displayBodies(){
    for (int i = 0; i < bodies.size(); i++){
        bodies.at(i).displayInfo();
    };
};