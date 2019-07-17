#include "Header.h"

UIButton::UIButton(UIControl *parent, int x, int y, int w, int h, string caption, int attr, int parent_attr)
{
	text = caption;
	this->attr = attr;
	childs.resize(0);
	Parent = parent;
	pattr = parent_attr;
	if (parent)
	{
		X = Parent->GetX() + x;
		Y = Parent->GetY() + y;
	}
	else
	{
		X = x;
		Y = y;
	}
	W = w;
	H = h;
}

UIButton::~UIButton(){}

void UIButton::Paint()
{
	int i,j;
	int skip = (W - text.size()) / 2;
	int reminder = ((W-text.size())%2==0) ? skip: skip+1;
	string data="";
	COORD c;
	vector<UIControl*>::iterator it;

	for (j = 0; j < H; j++)
	{
		c.X=X;
		c.Y=Y+j;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
		if (j == H / 2)
		{
			data = "";
			for (i = 0; i < skip; i++)
				data+=" ";
			data+=text;
			for (i = 0; i < reminder; i++)
				data+=" ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attr);
			printf("%s", data.c_str());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), pattr & 0xF0);
			if (H==1)
				printf("%c", 220);
			else
				printf("%c", 219);
		}
		else
		{
			data = "";
			for (i = 0; i < W; i++)
				data+=" ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attr);
			printf("%s", data.c_str());
			if (j>H / 2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), pattr & 0xF0);
				printf("%c", 219);
			}
		}
	}
	c.X=X+1;
	c.Y=Y+H;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), pattr & 0xF0);
	data = "";
	for (i = 0; i < W; i++)
		data+=(char)223;
	printf("%s", data.c_str());

	for (it=childs.begin();it!=childs.end();it++)
	{
		(*it)->Paint();
	}
}
