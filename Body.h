#ifndef BODY_H
#define BODY_H

#include <string>
#include <vector>
using namespace std;



class Body {
    private:
        string name;
        unsigned long long mass;
        unsigned int radius;

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
        Body(string n, unsigned long long m, unsigned int r);
        string repr(){return name;};
        string getName(){return name;};
        unsigned long long getMass(){return mass;};
        unsigned int getRadius(){return radius;}

};

struct ImportData{
    string n;
    double m;
    int mm;
    float p;
    float a;
    int dm;
    double r;
    int rm;
};

struct ProcessedData{
    string n;
    unsigned long long m;
    unsigned int r;
};

ImportData infoToValues(string info);

ProcessedData convertData(ImportData data);

vector<Body> createBodies(string fileName, int massReduction);

#endif