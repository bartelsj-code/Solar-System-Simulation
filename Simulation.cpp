#include "Simulation.h"
#include "Body.h"
#include "physics.h"
#include "mathStuff.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

Simulation::Simulation(vector<Body> b){
    bodiesV = b;
    for (int i = 0; i < bodiesV.size(); i++){
        bodiesM[bodiesV.at(i).getName()] = bodiesV.at(i);
    }
    cout << bodiesM["Sol"].getName() << "\n";

}

void Simulation::displayBodies(){
    for (int i = 0; i < bodiesV.size(); i++){
        displayBody(bodiesV.at(i));
    }
}

void Simulation::displayBody(Body body){
    string nameOfSatOf = body.getSatOf();
    cout << body.getName() << ":\n" 
        << "\tmass:           " << sciNo(to_string(body.getMass())) << " " << massUnit << "\n"
        << "\tradius:         " << sciNo(to_string(body.getRadius())) << " km" << "\n"
        << "\torbit:" << "\n"
            << "\t\tsatellite of:   " << nameOfSatOf << "\n"
            << "\t\tApogee: " << sciNo(to_string(body.getAp())) << " km" << "\n"
            << "\t\tPerigee: " << sciNo(to_string(body.getPe())) << " km" << "\n\n";
}

void Simulation::calcPositions(){
    displayBodies();
    array<long long, 3> center = {0, 0, 0};

    //set sun to center
    bodiesV.at(0).setPos(center);
    for (int i = 1; i < bodiesV.size(); i++){
        Body body = bodiesV.at(i);



    }
}
