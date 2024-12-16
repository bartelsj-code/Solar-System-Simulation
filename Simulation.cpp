#include "Simulation.h"
#include "Body.h"
#include "physics.h"
#include "mathStuff.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <typeinfo>


using namespace std;

Simulation::Simulation(vector<Body> b){
    bodiesV = b;
    for (int i = 0; i < bodiesV.size(); i++){
        bodiesM[bodiesV.at(i).getName()] = bodiesV.at(i);
    }
}

void Simulation::displayBodies(){
    for (int i = 0; i < bodiesV.size(); i++){
        displayBody(bodiesV.at(i));
    }
}

void Simulation::displayBody(Body body){
    string nameOfSatOf = body.getSatOf();
    Loc loc = body.getLoc();
    cout << body.getName() << ":\n" 
        << "\tmass:           " << sciNo(to_string(body.getMass())) << " " << massUnit << "\n"
        << "\tradius:         " << sciNo(to_string(body.getRadius())) << " km" << "\n"
        << "\torbit:" << "\n"
            << "\t\tsatellite of:   " << nameOfSatOf << "\n"
            << "\t\tApogee: " << sciNo(to_string(body.getAp())) << " km" << "\n"
            << "\t\tPerigee: " << sciNo(to_string(body.getPe())) << " km" << "\n"
            << "\t\t\tPos: " << to_string(loc.x) << ", " << to_string(loc.y) << ", " << to_string(loc.z) << "\n\n";
}

void Simulation::assignStart(Body b){
    // displayBody(b);
    // Body satOf = bodiesM.at(b.getSatOf());
    // // cout << satOf << "\n";
    // displayBody(satOf);
    // Loc rfLoc = satOf.getLoc();
    // // cout << satOf.getName() << "\n";
    // cout << rfLoc.x << "," << rfLoc.y << "," << rfLoc.z << "\n";

}

void Simulation::calcPositions(){
    // displayBodies();
    // displayBodies();

    Loc startLoc;
    startLoc.x = 0;
    startLoc.y = 0;
    startLoc.z = 0;

    Loc* adr = &startLoc;
    cout << adr;

    // Vel startVel;
    // startVel.x = 0;
    // startVel.y = 0;
    // startVel.z = 0;

    // array<long long, 3> center = {0, 0, 0};
    // array<double, 3> v = {0, 0, 0};

    //set sun to center

    bodiesV.at(0).setPos(adr);
    // bodiesV.at(0).setVel(startVel);

    displayBody(bodiesV.at(0));

    // for (int i = 1; i < bodiesV.size(); i++){
    //     assignStart(bodiesV.at(i));
    // }
    // displayBody(bodiesV.at(0));
}
