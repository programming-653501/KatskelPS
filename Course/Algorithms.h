//---------------------------------------------------------------------------

#ifndef AlgorithmsH
#define AlgorithmsH

#include "Field.h"
#include <deque>

bool FindMinDistance(Field *field, int& x, int& y);
bool Dijkstra(Field *field);
bool allIsPassed(Field *field);
bool isUseDijkstra(Field *field);
bool Moore(Field *field);

//---------------------------------------------------------------------------
#endif
