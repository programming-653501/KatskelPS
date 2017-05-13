//---------------------------------------------------------------------------

#ifndef PointsH
#define PointsH
#include <vcl.h>

struct Points
{
	bool isPassed;
	TColor color;
	int distance;
	int posX, posY;
	int GetDistance();
};

void CreatePoints(Points** &point, int horizontalNumber, int verticalNumber);
void DeletePoints(Points** &point, int horizontalNumber, int verticalNumber);
void DrawPoint(TImage* image, int width, int height, Points* point, TColor color);
void ClearPoint(TImage* image, int width, int height, TColor borderColor, TColor cellColor, Points *point);
void ChangePointColor(Points* point);
//---------------------------------------------------------------------------
#endif
