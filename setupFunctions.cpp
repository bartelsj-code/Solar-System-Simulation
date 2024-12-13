#include "Body.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>


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

    // radius
    getline(ss, holder, ',');
    id.r = stod(holder);

    // radius magnitude
    getline(ss, holder, ',');
    id.rm = stoi(holder);

    return id;
}

ProcessedData convertData(ImportData data, int massReduction){
    ProcessedData out;
    out.n = data.n;
    out.m = data.m * pow(10, (data.mm - massReduction));
    out.r = data.r * pow(10, (data.rm));
    return out;
}


vector<Body> createBodies(string fileName, int massReduction){
    vector<Body> bodies = {};
    //creates celestial bodies in accordance with input data
    string bodyInfo;
    ifstream File(fileName);
    getline(File, bodyInfo);
     
    while (getline(File, bodyInfo)){
        ImportData bodyData = infoToValues(bodyInfo);
        ProcessedData pData = convertData(bodyData, massReduction);
        Body body(pData.n, pData.m, pData.r);
        bodies.push_back(body);
    }    
    File.close();
    return bodies;
}