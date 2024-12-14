#include "Simulation.h"
#include "Body.h"
#include "physics.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>

int main() {
    //setup
    vector<Body> bodies = createBodies("bodies.csv");
    Simulation sim(bodies);
    // sim.displayBodies();
    sim.calcPositions();



    //

    return 0;
}