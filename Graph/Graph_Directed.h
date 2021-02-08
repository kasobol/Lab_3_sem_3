#pragma once

#include "Graph.h"
#include "LinkedListSequence.h"
#include "ArraySequence.h"
#include "BinaryHeap.h"

template<class T>
class Graph_Directed : public Graph<T>
{
    Sequence<Vertex<T>>* Vertexes;
    Sequence<Edge<T>>* Edges;
private:
    void Reset()
    {
        for (int i = 0; i < Vertexes->GetLength(); i++)
        {
            Vertexes->Get(i)->Distance = 0;
            Vertexes->Get(i)->Visited = false;
            Vertexes->Get(i)->Previous = nullptr;
        }
    }
public:
    Graph_Directed()
    {
        Vertexes = new ArraySequence<Vertex<T>>(5);
        Edges = new ArraySequence<Edge<T>>(5);
    }
    void Add_Vertex(Vertex<T>* vertex) override
    {
        Vertexes->Append(vertex);
    }
    void Add_Edge(Vertex<T>* v1, Vertex<T>* v2) override
    {
        Edge<T>* edge = new Edge<T>(v1, v2);
        Edges->Append(edge);
        v1->OutEdges->Append(edge);
    }
    void Add_Edge(Vertex<T>* v1, Vertex<T>* v2, double weight) override
    {
        Edge<T>* edge = new Edge<T>(v1, v2, weight);
        Edges->Append(new Edge<T>(v1, v2, weight));
        v1->OutEdge->Append(edge);
    }

    Sequence<Edge<T>>* Go_Dijkstra(Vertex<T>* start) override
    {
        Reset();

        start->Distance = 0;
        start->Visited = true;

        BinaryHeap<Vertex<T>>* heap = new BinaryHeap<Vertex<T>>(10);
        Vertex<T>* pointer = start;
        Sequence<Edge<T>>* result = new ArraySequence<Edge<T>>(2);
        Vertex<T>* min;
        heap->Add(pointer);
        while (heap->size != 0)
        {
            for (int i = 0; i < pointer->OutEdges->GetLength(); i++)
            {
                if (pointer->OutEdges->Get(i)->To->Visited == false)
                {
                    double distance = pointer->Distance + pointer->OutEdges->Get(i)->Weight;
                    if (distance < pointer->OutEdges->Get(i)->To->Distance)
                    {
                        pointer->OutEdges->Get(i)->To->Distance = distance;
                        pointer->OutEdges->Get(i)->To->Previous = pointer->OutEdges->Get(i);
                        heap->Add(pointer->OutEdges->Get(i)->To);
                    }
                }
            }
            min = heap->Get();
            min->Visited = true;
            result->Append(min->Previous);
            pointer = min;
        }
        return result;
    }

    Sequence<Edge<T>>* Search_Way(Vertex<T>* start, Vertex<T>* end, Sequence<Edge<T>>* list) override
    {
        Sequence<Edge<T>>* result = new ArraySequence<Edge<T>>(2);
        Vertex<T>* pointer = end;
        while (pointer != start)
        {
            result->Append(pointer->Previous);
            pointer = pointer->Previous->From;
        }
        return result;
    }
};