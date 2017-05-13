//---------------------------------------------------------------------------


#pragma hdrstop

#include "Algorithms.h"

bool Dijkstra(Field *field)
{
	int xCur, yCur;
	field->Initialize(1000000000);
	Points **points = field->points;
	Points *end = field->end;
	Points *begin = field->begin;
	points[begin->posX][begin->posY].distance = 0;
	while(!allIsPassed(field)) {
		if(!FindMinDistance(field, xCur, yCur))
			break;
		if(xCur != 0)
			if( points[xCur][yCur].distance + points[xCur - 1][yCur].GetDistance() <
			   points[xCur - 1][yCur].distance && points[xCur - 1][yCur].color != clBlack )
				points[xCur - 1][yCur].distance = points[xCur][yCur].distance + points[xCur-1][yCur].GetDistance();
		if(xCur != field->horizontalNumber - 1)
			if(points[xCur][yCur].distance + points[xCur + 1][yCur].GetDistance() <
			   points[xCur + 1][yCur].distance && points[xCur + 1][yCur].color != clBlack)
				points[xCur + 1][yCur].distance = points[xCur][yCur].distance + points[xCur + 1][yCur].GetDistance();
		if(yCur != field->verticalNumber-1)
			if(points[xCur][yCur].distance + points[xCur][yCur + 1].GetDistance() <
			   points[xCur][yCur + 1].distance && points[xCur][yCur + 1].color != clBlack)
				points[xCur][yCur + 1].distance = points[xCur][yCur].distance + points[xCur][yCur + 1].GetDistance();
		if(yCur != 0)
			if(points[xCur][yCur].distance + points[xCur][yCur - 1].GetDistance() <
			   points[xCur][yCur - 1].distance && points[xCur][yCur - 1].color != clBlack)
				points[xCur][yCur - 1].distance = points[xCur][yCur].distance + points[xCur][yCur - 1].GetDistance();
		points[xCur][yCur].isPassed = 1;
	}
	if(points[end->posX][end->posY].distance == 1000000000)
		return false;
	else
		return true;
}

bool Moore(Field *field)
{
	field->Initialize(-1);
	Points **points = field->points;
	Points *end = field->end;
	Points *begin = field->begin;
	std::deque<Points> myDeque;
	points[begin->posX][begin->posY].distance = 0;
	points[begin->posX][begin->posY].isPassed = 1;
	myDeque.push_back(points[begin->posX][begin->posY]);
	while(!myDeque.empty()) {
		Points cur = myDeque.front();
		myDeque.pop_front();
		int xCur = cur.posX;
		int yCur = cur.posY;
		if(xCur != 0) {
			if(points[xCur - 1][yCur].color != clBlack && points[xCur - 1][yCur].isPassed != 1) {
			points[xCur - 1][yCur].isPassed = 1;
			points[xCur - 1][yCur].distance = cur.distance + 1;
			myDeque.push_back(points[xCur - 1][yCur]);
			}
		}
		if(xCur != field->horizontalNumber - 1) {
			if(points[xCur + 1][yCur].color != clBlack && points[xCur + 1][yCur].isPassed != 1) {
			points[xCur + 1][yCur].isPassed = 1;
			points[xCur + 1][yCur].distance = cur.distance + 1;
			myDeque.push_back(points[xCur + 1][yCur]);
			}
		}
		if(yCur != field->verticalNumber - 1) {
			if(points[xCur][yCur + 1].color != clBlack && points[xCur][yCur + 1].isPassed != 1) {
			points[xCur][yCur + 1].isPassed = 1;
			points[xCur][yCur + 1].distance = cur.distance + 1;
			myDeque.push_back(points[xCur][yCur + 1]);
			}
		}
		if(yCur != 0) {
			if(points[xCur][yCur-1].color != clBlack && points[xCur][yCur - 1].isPassed != 1) {
			points[xCur][yCur - 1].isPassed = 1;
			points[xCur][yCur - 1].distance = cur.distance + 1;
			myDeque.push_back(points[xCur][yCur - 1]);
			}
		}
	}
	return points[end->posX][end->posY].isPassed != 0;
}

bool FindMinDistance(Field *field, int& x, int& y)
{
	x=0; y=0;
	int dist = 999999999;
	for(int i = 0; i < field->horizontalNumber; i++) {
		for(int j = 0; j < field->verticalNumber; j++) {
			if(field->points[i][j].distance < dist && field->points[i][j].isPassed == 0) {
				dist = field->points[i][j].distance;
				x = i;
				y = j;
			}
		}
	}
	return dist != 999999999;
}

bool allIsPassed(Field *field)
{
	for(int i = 0; i < field->horizontalNumber; i++)
		for(int j = 0; j < field->verticalNumber; j++)
			if(field->points[i][j].isPassed == 0)
				return false;
	return true;
}

bool isUseDijkstra(Field *field)
{
	bool flag = true;
	TColor color;
	for(int i = 0; i < field->horizontalNumber && flag; i++)
		for(int j = 0; j < field->verticalNumber && flag; j++)
			if(field->points[i][j].color != clBlack) {
				color = field->points[i][j].color;
				flag = false;
			}
	for(int i = 0; i < field->horizontalNumber; i++)
		for(int j = 0; j < field->verticalNumber; j++)
			if(field->points[i][j].color != clBlack && field->points[i][j].color != color)
				return true;
	return false;
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
