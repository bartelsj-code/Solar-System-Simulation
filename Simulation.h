#ifndef SIMULATION_H
#define SIMULATION_H

#include "Body.h"
#include <string>
#include <vector>
#include <map>


class Simulation{
    private:
        std::vector<Body> bodiesV;
        std::map<string, Body> bodiesM;
        int massUnitReduction;


    public:
        Simulation(vector<Body> b);
        void displayBodies();
        void calcPositions();
        void displayBody(Body b);
        void assignStart(Body b);
        
        

};


#endif