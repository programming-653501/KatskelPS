//---------------------------------------------------------------------------


#pragma hdrstop

#include "Field.h"

Field::Field(int _horizontalNumber, int _verticalNumber)
{
	horizontalNumber = _horizontalNumber;
	verticalNumber = _verticalNumber;
	CreatePoints(points, horizontalNumber, verticalNumber);
	begin = new Points();
	begin->posY = begin->posX = -1;
	begin->color = clGreen;
	end = new Points();
	end->posY = end->posX = -2;
	end->color = clRed;
	havePath = true;
}

Field::~Field()
{
	DeletePoints(points, horizontalNumber, verticalNumber);
	delete begin;
	delete end;
}

void Field::Initialize(int distance)
{
	for(int i = 0; i < horizontalNumber; i++) {
		for(int j = 0; j < verticalNumber; j++) {
			if(points[i][j].color == clBlack)
				points[i][j].isPassed = 1;
			else
				points[i][j].isPassed = 0;
			points[i][j].distance = distance;
		}
	}
}

void Field::DrawField(TImage* image)
{
	image->Canvas->Pen->Width = 1;
	image->Canvas->Brush->Color = clWhite;
	image->Canvas->FillRect(Rect(0, 0, image->Width, image->Height));
	image->Canvas->Pen->Color = clGray;

	int width = (image->Width - 1) / verticalNumber;
	int height = (image->Height - 1) / horizontalNumber;

	for(int i = 0; i <= horizontalNumber; i++) {
		image->Canvas->MoveTo(0, i * height);
		image->Canvas->LineTo(width * verticalNumber, i * height);
	}
	for(int i = 0; i <= verticalNumber; i++) {
		image->Canvas->MoveTo(i * width, 0);
		image->Canvas->LineTo(i * width, height * horizontalNumber);
	}
}

void Field::PaintField(TImage* image)
{
	DrawField(image);
	int width = (image->Width - 1) / verticalNumber;
	int height = (image->Height - 1) / horizontalNumber;
	for(int i = 0; i < horizontalNumber; i++) {
		for(int j = 0; j < verticalNumber; j++) {
			int X = (2 * points[i][j].posY + 1) * width / 2;
			int Y = (2 * points[i][j].posX + 1) * height / 2;
			image->Canvas->Brush->Color = points[i][j].color;
			image->Canvas->FloodFill(X, Y, clGray, fsBorder);
		}
	}
	DrawPoint(image, width, height, end, end->color);
	DrawPoint(image, width, height, begin, begin->color);
}
//---------------------------------------------------------------------------

void Field::DrawPath(TImage* image, Points *point)
{
	if(point->distance == 0)
		return;
	int xCur = point->posX;
	int yCur = point->posY;
	if(xCur != 0) {
		if(points[xCur-1][yCur].distance == point->distance - point->GetDistance()) {
			DrawLine(image, point, &points[xCur - 1][yCur], clBlue);
			DrawPath(image, &points[xCur - 1][yCur]);
			return;
		}
	}
	if(xCur != horizontalNumber - 1) {
		if(points[xCur + 1][yCur].distance == point->distance - point->GetDistance()) {
			DrawLine(image, point, &points[xCur + 1][yCur], clBlue);
			DrawPath(image, &points[xCur + 1][yCur]);
			return;
		}
	}
	if(yCur != 0) {
		if(points[xCur][yCur - 1].distance == point->distance - point->GetDistance()) {
			DrawLine(image, point, &points[xCur][yCur - 1], clBlue);
			DrawPath(image, &points[xCur][yCur - 1]);
			return;
		}
	}
	if(yCur != verticalNumber - 1) {
		if(points[xCur][yCur + 1].distance == point->distance - point->GetDistance()) {
			DrawLine(image, point, &points[xCur][yCur + 1], clBlue);
			DrawPath(image, &points[xCur][yCur + 1]);
			return;
		}
	}
}

void Field::DrawLine(TImage *image, Points *start, Points *finish, TColor color)
{
	int width = (image->Width - 1) / verticalNumber;
	int height = (image->Height - 1) / horizontalNumber;
	image->Canvas->Pen->Color = color;
	image->Canvas->Pen->Width = 5;
	int moveToX = (2 * start->posY + 1) * width / 2;
	int moveToY = (2 * start->posX + 1) * height / 2;
	int lineToX = (2 * finish->posY + 1) * width / 2;
	int lineToY = (2 * finish->posX + 1) * height / 2;
	image->Canvas->MoveTo(moveToX, moveToY);
	image->Canvas->LineTo(lineToX, lineToY);
}

void Field::ChangeFieldColor(TImage* image, Points* point)
{
	int width = (image->Width - 1) / verticalNumber;
	int height = (image->Height - 1) / horizontalNumber;
	int X = (2 * point->posY + 1) * width / 2;
	int Y = (2 * point->posX + 1) * height / 2;
	ChangePointColor( point );
	if(end->posY == point->posY && end->posX == point->posX)
		end->posY = end->posX = -2;
	if(begin->posY == point->posY && begin->posX == point->posX)
		begin->posY = begin->posX = -1;
	image->Canvas->Brush->Color = point->color;
	image->Canvas->FloodFill(X, Y, clGray, fsBorder);
}

void Field::SetBeginPoint(TImage *image, int xCount, int yCount)
{
	int width = (image->Width - 1) / verticalNumber;
	int height = (image->Height - 1) / horizontalNumber;
	if((xCount!=end->posX || yCount!=end->posY) && points[xCount][yCount].color!=clBlack) {
		if(begin->posY != -1 && begin->posX != -1)
			ClearPoint(image, width, height, clGray, points[begin->posX][begin->posY].color, begin);
		begin->posX = xCount;
		begin->posY = yCount;
		DrawPoint(image, width, height, begin, begin->color);
	}
}

void Field::SetEndPoint(TImage *image, int xCount, int yCount)
{
	int width = (image->Width - 1) / verticalNumber;
	int height = (image->Height - 1) / horizontalNumber;
	if((xCount!=begin->posX || yCount!=begin->posY) && points[xCount][yCount].color!=clBlack) {
		if(end->posY != -2 && end->posX != -2)
			ClearPoint(image, width, height, clGray, points[end->posX][end->posY].color, end);
		end->posX = xCount;
		end->posY = yCount;
		DrawPoint(image, width, height, end, end->color);
	}
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
