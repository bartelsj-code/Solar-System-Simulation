#ifndef BODY_H
#define BODY_H

#include <string>
#include <vector>
#include <array>

using namespace std;

class Loc{
    public:
        long long x;
        long long y;
        long long z; 
        void setX(long long xIn){x = xIn;}
};

class Vel{
    
    double x;
    double y;
    double z;
};

struct ImportData{
    // int id;
    string n;
    double m;
    int mm;
    float p;
    float a;
    int dm;
    string so;
    double r;
    int rm;
};

struct ProcessedData{
    // int id;
    string n;
    unsigned long long m;
    unsigned int r;
    string so;
    unsigned long long a;
    unsigned long long p;
    
};

ImportData infoToValues(string info);

ProcessedData convertData(ImportData data);

class Body {
    private:
        string name; //name
        unsigned long long mass; //mass (converted to gigatons)
        unsigned int radius; //radius (for visuals)
        string satOf; //body around which to orbit
        unsigned long long apogee;
        unsigned long long perigee;
        Loc location; //x, y, z
        Vel vel;


    public:
        //getters
        string getName(){return name;}
        unsigned long long getMass(){return mass;}
        unsigned int getRadius(){return radius;}
        
        string getSatOf(){return satOf;}
        unsigned long long getAp(){return apogee;}
        unsigned long long getPe(){return perigee;}

        Loc getLoc(){return location;}
        // Vel* getVel(){return velocity;}

        //setters
        void setX(long long xVal){location.x = xVal;}
        void setY(long long yVal){location.y = yVal;}
        void setZ(long long zVal){location.z = zVal;}

        // void setLoc(Loc* l){location = l;}
        // // void setVel(Vel* v){velocity = v;}

        
        Body(ProcessedData data);

        Body();
        

        void displayInfo();

        //
        
       
};

vector<Body> createBodies(string fileName);

#endif