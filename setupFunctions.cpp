#include "Body.h"
#include "Simulation.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>
#include "physics.h"

ImportData infoToValues(string info){
    string holder;
    ImportData id;
    istringstream ss(info);

    // name
    getline(ss, id.n, ',');

    // mass
    getline(ss, holder, ',');
    id.m = stod(holder);

    // mass magnitude
    getline(ss, holder, ',');
    id.mm = stoi(holder);

    // perigee
    getline(ss, holder, ',');
    id.p = stof(holder);

    // apogee
    getline(ss, holder, ',');
    id.a = stof(holder);

    // magnitude for distances
    getline(ss, holder, ',');
    id.dm = stoi(holder);

    // satellite to
    getline(ss, holder, ',');

    size_t temp = holder.find_first_not_of(" ");
    holder = holder.substr(temp);
    id.so = holder;

    // radius
    getline(ss, holder, ',');
    id.r = stod(holder);

    // radius magnitude
    getline(ss, holder, ',');
    id.rm = stoi(holder);

    return id;
}

ProcessedData convertData(ImportData data){
    ProcessedData out;
    // out.id = data.id;
    out.n = data.n;
    out.m = data.m * pow(10, (data.mm - massReduction));
    out.r = data.r * pow(10, (data.rm));
    out.so = data.so;
    out.a = data.a * pow(10, data.dm);
    out.p = data.p * pow(10, data.dm);
    return out;
}


vector<Body> createBodies(string fileName){
    vector<Body> bodies = {};
    //creates celestial bodies in accordance with input data
    string bodyInfo;
    ifstream File(fileName);
    getline(File, bodyInfo);
     
    while (getline(File, bodyInfo)){
        if (bodyInfo[0] != '#'){
            ImportData bodyData = infoToValues(bodyInfo);
            ProcessedData pData = convertData(bodyData);
            Body body(pData);
            bodies.push_back(body);
        }
    }    

    File.close();
    return bodies;


}