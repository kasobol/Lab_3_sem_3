#pragma once

#include "Vertex.h"
#include "Edge.h"
#include "Sequence.h"

template<class T>
class Graph
{
public:
    virtual void Add_Vertex(Vertex<T>* vertex) = 0;
    virtual void Add_Edge(Vertex<T>* v1, Vertex<T>* v2) = 0;
    virtual void Add_Edge(Vertex<T>* v1, Vertex<T>* v2, double weight) = 0;
    virtual Sequence<Edge<T>>* Go_Dijkstra(Vertex<T>* start) = 0;
    virtual Sequence<Edge<T>>* Search_Way(Vertex<T>* start, Vertex<T>* end, Sequence<Edge<T>>* edges) = 0;
};