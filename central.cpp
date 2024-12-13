#include "Body.h"
#include "physics.h"
#include "Simulation.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>

int main() {
    vector<Body> bodies = createBodies("bodies.csv");

    Simulation sim(bodies);
    sim.displayBodies();

    return 0;
}