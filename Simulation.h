#ifndef SIMULATION_H
#define SIMULATION_H

#include "Body.h"
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <memory>
#include <fstream>



class Simulation{
    private:
        vector<shared_ptr<Body>> bodiesV;
        map<string, shared_ptr<Body>> bodiesM;
    
        int massUnitReduction;


    public:
        Simulation(string fileName);
        void displayBodies();
        void calcPositions();
        void displayBody(Body b);
        void assignStart(Body b);
        Body getBody(int i);
        Body getBody(string s);

        
        

};


#endif