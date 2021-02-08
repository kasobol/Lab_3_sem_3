#pragma once

#include "Edge.h"
#include "ArraySequence.h"

template<class T>
class Vertex
{
public:
    double X;
    double Y;
    T Data;

    Sequence<Edge<T>>* OutEdges;
    double Distance;
    bool Visited;
    Edge<T>* Previous;

    Vertex(T Data)
    {
        this->Data = Data;
        OutEdges = new ArraySequence<Edge<T>>(2);
    }
    Vertex(T Data, double X, double Y)
    {
        this->Data = Data;
        this->X = X;
        this->Y = Y;
        OutEdges = new ArraySequence<Edge<T>>(2);
    }
};