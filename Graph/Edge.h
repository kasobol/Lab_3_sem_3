#pragma once

#include <cmath>

#include "Vertex.h"

using namespace std;

template<class T>
class Edge
{
public:
    Vertex<T>* From;
    Vertex<T>* To;
    double Weight;

    Edge(Vertex<T>* From, Vertex<T>* To)
    {
        this->From = From;
        this->To = To;
        Weight = sqrt(pow(To.X - From.X, 2) + pow(To.Y - From.Y, 2));
    }
    Edge(Vertex<T>* From, Vertex<T>* To, double Weight)
    {
        this->From = From;
        this->To = To;
        this->Weight = Weight;
    }
};