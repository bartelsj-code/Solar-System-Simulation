#include "Body.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    Body b = Body(7);
 

    int hi = b.getX();
    std::cout << "Result: " << hi << std::endl;
    return 0;
    
}