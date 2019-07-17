#include "Header.h"

int main(void)
{
	int i, x, y;
	//UIControl *pmain = new UIPanel(0,1,1,78,30,0x3f);

	UIControl *b1 = new UIButton(0, 10, 10, 50, 30, "Buton1", 0x87, 0x00);
	//UIControl *l1 = new UILabel(pmain, 1, 1, "Eticheta", 0x1f);

	//UIControl *p1 = new UIPanel(pmain, 38, 5, 30, 16, 0x68);
	UIControl *pb1 = new UIButton(b1, 3, 2, 13, 1, "Buton Panel", 0x1f,0x87);
	//UIControl *pl1 = new UILabel(p1,12,5,"Label Panel",0xf2);
	UIControl *pb2 = new UIButton(b1, 7, 7, 16, 5, "Big Buton", 0x49, 0x87);

	//p1->Add(pb1);
	//p1->Add(pl1);
	//p1->Add(pb2);

	//pmain->Add(p1);
	//pmain->Add(b1);
	//pmain->Add(l1);

	b1->Add(pb1);
	b1->Add(pb2);

	b1->Paint();

	return 0;
}