#pragma once

#include <windows.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class UIControl {
private:

protected:
	int X, Y, W, H;
	UIControl *Parent;

public:
	virtual void Paint() = 0;
	virtual void Add(UIControl *child) = 0;
	virtual int GetX() = 0;
	virtual int GetY() = 0;

};

//------------------------------------------------------------------------------------

class UIButton :public UIControl {
private:
	string text;
	int attr;
	int pattr;
	vector<UIControl*> childs;

public:
	UIButton(UIControl *parent, int x, int y, int w, int h, string caption, int attr, int parent_attr);
	~UIButton();
	virtual void Paint();
	virtual void Add(UIControl *child) { childs.push_back(child); }
	virtual int GetX() { return X; }
	virtual int GetY() { return Y; }
};
class UIPannel :public UIControl {
private:
	int attr;
	int pattr;
	vector<UIControl*> childs;

public:
	UIPannel(UIControl *parent, int x, int y, int w, int h, string caption, int attr, int parent_attr);
	~UIPannel();
	virtual void Paint();
	virtual void Add(UIControl *child) { childs.push_back(child); }
	virtual int GetX() { return X; }
	virtual int GetY() { return Y; }
};
class UILabel :public UIControl {
private:
	int attr;
	int pattr;
	vector<UIControl*> childs;

public:
	UILabel(UIControl *parent, int x, int y, int w, int h, string caption, int attr, int parent_attr);
	~UILabel();
	virtual void Paint();
	virtual void Add(UIControl *child) { childs.push_back(child); }
	virtual int GetX() { return X; }
	virtual int GetY() { return Y; }
};

