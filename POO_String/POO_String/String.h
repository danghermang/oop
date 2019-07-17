class String
{
private:
	char Text[100];
public:
	String();
	String(const char*);
	String(const String &);

	char operator[] (int);
	operator char* ();
	operator int(); // returneaza nr el
	String operator& (const char*);
	String operator& (String &);
	String operator& (char);
	String operator! (); // scoate spatii
	String operator= (String &);
	int operator| (char);
};