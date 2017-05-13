//---------------------------------------------------------------------------

#ifndef FieldH
#define FieldH

#include <vcl.h>
#include "Points.h"

struct Field
{
	int horizontalNumber;
	int verticalNumber;
	bool havePath;
	Points *begin, *end;
	Points **points;
	Field(int _horizontalNumber, int _verticalNumber);
	~Field();
	void Initialize(int distance);
	void DrawField(TImage* image);
	void DrawPath(TImage *image, Points *point);
	void DrawLine(TImage *image, Points *start, Points *finish, TColor color);
	void PaintField(TImage* image);
	void ChangeFieldColor (TImage* image, Points* point);
	void SetBeginPoint(TImage *image, int xCount, int yCount);
	void SetEndPoint(TImage *image, int xCount, int yCount);
};


//---------------------------------------------------------------------------
#endif
