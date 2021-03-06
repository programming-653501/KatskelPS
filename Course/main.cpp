//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

Field *field;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y)
{
	int width = (Image1->Width - 1) / field->verticalNumber;
	int height = (Image1->Height - 1) / field->horizontalNumber;
	int xCount = Y/height;
	int yCount = X/width;
	if(Image1->Canvas->Pixels[X][Y] == clGray ||  Y >= field->horizontalNumber * height
				|| X >= field->verticalNumber * width)
		return;
	if(field->havePath) {
		switch(RadioGroup1->ItemIndex) {
			case 0: field->ChangeFieldColor(Form1->Image1, &field->points[xCount][yCount]); break;
			case 1: field->SetBeginPoint(Form1->Image1, xCount, yCount); break;
			case 2: field->SetEndPoint(Form1->Image1, xCount, yCount); break;
		}
	}
	else {
		field->PaintField(Form1->Image1);
		field->havePath = true;
	}
}


void __fastcall TForm1::FormActivate(TObject *Sender)
{
	field = new Field(2, 2);
	Image1->Canvas->Brush->Color = clWhite;
	Image1->Canvas->FillRect(Rect(0, 0, Image1->Width, Image1->Height));
	field->DrawField(Form1->Image1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	delete field;
	Application->Terminate();
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Points *end = field->end, *begin = field->begin;
	if(field->begin->posX == -1 || field->end->posX == -2) {
		Application->MessageBox(String("���������� ��������� � �������� �����").c_str(),
		 String("��������").c_str(), NULL);
		return;
	}
	bool isUse = isUseDijkstra(field);
	bool answer = isUse ? Dijkstra(field) : Moore(field);
	String message = isUse? "������ ����� ������ ������������. ����� ����������� �������� ��������":
							"������ ����� ���������� ������������. ����� ����������� �������� ����";
	Application->MessageBox(message.c_str(), String("��������").c_str(), NULL);
	if(answer == false)
		 Application->MessageBox(String("���� �� ������").c_str(),
		 String("��������").c_str(), NULL);
	else {
		field->DrawPath(Form1->Image1, &field->points[end->posX][end->posY]);
		field->havePath = false;
	}
}

//---------------------------------------------------------------------------




void __fastcall TForm1::Button1Click(TObject *Sender)
{
	try {
		int horizontalNumber = StrToInt(Edit1->Text);
		int verticalNumber = StrToInt(Edit2->Text);
		if( horizontalNumber < 1 || verticalNumber < 1) {
			Application->MessageBox(String("������� ���� ������� �������").c_str(),
			String("��������").c_str(), NULL);
			return;
		}
		if( horizontalNumber > 50 || verticalNumber > 50) {
			Application->MessageBox(String("������� ������� ������ ���� (>50). ������� ������").c_str(),
			String("��������").c_str(), NULL);
			return;
		}
		delete field;
		field = new Field(horizontalNumber, verticalNumber);
		field->DrawField(Form1->Image1);
	}
	catch(Exception &e) {
		Application->MessageBox(String("�� ������� ���� �������� ���������").c_str(),
		 String("��������").c_str(), NULL);
	}
}
//---------------------------------------------------------------------------


