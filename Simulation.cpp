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

Simulation::Simulation(string fileName){
    
    string bodyInfo;
    ifstream File(fileName);
    getline(File, bodyInfo);
     
    while (getline(File, bodyInfo)){
        if (bodyInfo[0] != '#'){
            ImportData bodyData = infoToValues(bodyInfo);
            ProcessedData pData = convertData(bodyData);
            auto body = make_shared<Body>(pData);
            bodiesV.push_back(body);
            bodiesM[body->getName()] = body;
        }
    }
    File.close();       
}

void Simulation::displayBodies(){
    for (int i = 0; i < bodiesV.size(); i++){
        displayBody(*bodiesV.at(i));
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
            << "\t\tPerigee: " << sciNo(to_string(body.getPe())) << " km" << "\n";
            // << "\t\t\tPos: " << loc.x << ", " << to_string(loc.y) << ", " << to_string(loc.z) << "\n\n";
}

// void Simulation::assignStart(Body b){
//     Body satOf = bodiesM.at(b.getSatOf());


//     displayBody(satOf);
// }

void Simulation::calcPositions(){
    displayBodies();
    for (int i = 0; i < bodiesV.size(); i++){
  
        // assignStart(bodiesV.at(i));
    }
}
