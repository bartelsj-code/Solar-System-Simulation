#ifndef BODY_H
#define BODY_H

#include <string>
#include <vector>
#include <array>

using namespace std;





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
        //unique int for each body
        // int id;
        string name; //name
        unsigned long long mass; //mass (converted to gigatons)
        unsigned int radius; //radius (for visuals)
        string satOf; //body around which to orbit
        unsigned long long apogee;
        unsigned long long perigee;

        struct {
            long long x;
            long long y;
            long long z;
        }   location;

        struct {
            double x;
            double y;
            double z;
        }   velocity;

    public:
        //getters
        string getName(){return name;}
        unsigned long long getMass(){return mass;}
        unsigned int getRadius(){return radius;}
        
        string getSatOf(){return satOf;}
        unsigned long long getAp(){return apogee;}
        unsigned long long getPe(){return perigee;}

        //setters
        void setX(long long xVal){location.x = xVal;}
        void setY(long long yVal){location.y = yVal;}
        void setZ(long long zVal){location.z = zVal;}

        void setPos(array<long long, 3> pos){location.x = pos[0]; location.y = pos[1]; location.z = pos[2];}

        
        Body(ProcessedData data);

        Body();
        

        void displayInfo();

        //
        
       
};

vector<Body> createBodies(string fileName);

#endif