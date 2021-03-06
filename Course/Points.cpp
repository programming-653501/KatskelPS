//---------------------------------------------------------------------------


#pragma hdrstop

#include "Points.h"

int Points::GetDistance()
{
	int distance;
	switch(color) {
		case clWhite:
			distance = 1;
			break;
		case clYellow:
			distance = 2;
			break;
		case clOlive:
			distance = 3;
			break;
	}
	return distance;
}

void CreatePoints(Points** &point, int horizontalNumber, int verticalNumber)
{
	point = new Points* [horizontalNumber];

	for(int i = 0 ; i < horizontalNumber; i++)
		point[i] = new Points[verticalNumber];

	for(int i = 0; i < horizontalNumber; i++) {
		for(int j = 0; j < verticalNumber; j++) {
			point[i][j].isPassed = 0;
			point[i][j].distance = -1;
			point[i][j].posX = i;
			point[i][j].posY = j;
			point[i][j].color = clWhite;
		}
	}
}

void DeletePoints(Points** &point, int horizontalNumber, int verticalNumber)
{
	for(int i = 0; i < horizontalNumber; i++)
		delete[] point[i];
	delete[] point;
}

void DrawPoint(TImage* image, int width, int height, Points* point, TColor color)
{
	if(!point)
		return;
	int xCenter = (2 * point->posY + 1) * width / 2;
	int yCenter = (2 * point->posX + 1) * height / 2;
	image->Canvas->Brush->Color = color;
	image->Canvas->Pen->Color = color;
	int r = width < height ? (width / 3 - 1) : (height / 3 - 1);
	image->Canvas->Ellipse(xCenter-r, yCenter-r, xCenter+r, yCenter+r);
}

void ClearPoint(TImage* image, int width, int height, TColor borderColor, TColor cellColor, Points* point)
{
	int xCenter = (2 * point->posY + 1) * width / 2;
	int yCenter = (2 * point->posX + 1) * height / 2;
	image->Canvas->Brush->Color = cellColor;
	image->Canvas->FloodFill(xCenter, yCenter, borderColor, fsBorder);
}

void ChangePointColor(Points* point)
{
	switch(point->color) {
		case clBlack:
			point->color = clWhite;
			break;
		case clWhite:
			point->color = clYellow;
			break;
		case clYellow:
			point->color = clOlive;
			break;
		case clOlive:
			point->color = clBlack;
			break;
	}
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
