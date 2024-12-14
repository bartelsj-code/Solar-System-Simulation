#ifndef SIMULATION_H
#define SIMULATION_H

#include "Body.h"
#include <string>
#include <vector>


class Simulation{
    private:
        std::vector<Body> bodies;
        int massUnitReduction;

    public:
        Simulation(vector<Body> b);
        void displayBodies();
        void calcPositions();
        
        

};


#endif