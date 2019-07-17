#include "String.h"
#include <string.h>

String::String()
{
	Text[0] = 0;
}
String::String(const char* sir)
{
	strncpy_s(this->Text, 100, sir, 100);
}
String::String(const String &alt_string)
{
	strcpy_s(this->Text, 100, alt_string.Text);
}

char String::operator[] (int index)
{
	if (index < 0 || index >= 99)
		return NULL;
	return Text[index];
}
String::operator char* ()
{
	return this->Text;
}
String::operator int() // returneaza nr el
{
	return strlen(this->Text);
}
String String::operator& (const char* arg)
{
	String out(*this);
	if (int(*this) + strlen(arg) >= 99)
		return out;

	for (int i = int(*this); i < int(*this) + strlen(arg); i++)
		out.Text[i] = arg[i - int(*this)];

	out.Text[int(*this) + strlen(arg)] = NULL;
	return out;
}
String String::operator& (String &arg)
{
	String out(*this);
	if (int(*this) + int(arg) >= 99)
		return out;

	for (int i = int(*this); i < int(*this) + int(arg); i++)
		out.Text[i] = arg[i - int(*this)];

	out.Text[int(*this) + int(arg)] = NULL;
	return out;
}
String String::operator& (char arg)
{
	String out(*this);
	if (int(*this) + 1 >= 99)
		return out;


	out.Text[int(*this)] = arg;
	out.Text[int(*this) + 1] = NULL;

	return out;
}
String String::operator! () // scoate spatii
{
	String out(*this);
	for (int i = 0; i<int(out); i++)
		if(out.Text[i] == ' ')
		{
			for (int j = i; j <= int(out) - 1; j++) // <= pt ca sa copieze si NULL-ul !
				out.Text[j] = out.Text[j + 1];
		}
	
	return out;
}
String String::operator= (String &arg)
{
	strcpy(this->Text, arg);
	return *this;
}
int String::operator| (char c)
{
	int counter = 0;
	for (int i = 0; i<int(*this); i++)
		if (Text[i] == c)
			counter++;
	return counter;
}
