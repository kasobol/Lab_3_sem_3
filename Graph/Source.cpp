#include "Graph_Directed.h"

extern "C" __declspec(dllexport) Graph_Directed<char*>* Create()
{
    return new Graph_Directed<char*>();
}