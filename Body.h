#ifndef BODY_H
#define BODY_H

#include <string>
#include <vector>
using namespace std;





struct ImportData{
    int id;
    string n;
    double m;
    int mm;
    float p;
    float a;
    int dm;
    int st;
    double r;
    int rm;
};

struct ProcessedData{
    int id;
    string n;
    unsigned long long m;
    unsigned int r;
    int st;
    unsigned long long a;
    unsigned long long p;
    
};

ImportData infoToValues(string info);

ProcessedData convertData(ImportData data);

class Body {
    private:
        int id; //unique int for each body
        string name; //name
        unsigned long long mass; //mass (converted to gigatons)
        unsigned int radius; //radius (for visuals)
        int satTo; //body around which to orbit
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
        Body(ProcessedData data);
        string repr(){return name;};
        string getName(){return name;};
        unsigned long long getMass(){return mass;};
        unsigned int getRadius(){return radius;};
        void displayInfo();

};

vector<Body> createBodies(string fileName);

#endif