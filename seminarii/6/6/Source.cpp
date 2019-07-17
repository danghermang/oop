#include <iostream>
#include <fstream>
#include <vector>
#include <locale>
#include <set>
#include <cctype>
#include <map>
#include <sstream>
#include <string>
#define loop(n) for(int i=0;i<n;i++)
using namespace std;
string sir;
vector<string> propozitii;
map<string, int> cuvinte;
int nr = 0;
bool citire_cu_verificare(char *path)
{
	char semne[] = ",-!?.";
	fstream f(path, ios::in);
	string aux;

	while (getline(f, aux))
		sir += aux + ' ';
	for (int i = 0; i < sir.size() - 1; i++)
		if (!isalnum(sir[i]))
		{
			if (strchr(semne, sir[i]))
			{
				if (sir[i] == sir[i + 1])
				{
					return 0;
				}
			}//;i+500;}
			if ((sir[i] == ' ' && sir[i + 1] == '-') || (sir[i] == '-'&&!isalnum(sir[i + 1])))
			{
				return 0;//i+600;
			}
			else if (sir[i] != ' '&&!strchr(semne, sir[i]))
			{
				return 0;
			}
		}
	return 1;
}

vector<string> Propo(string text) {
	vector<string> str;
	int start = 0;
	char semne[] = "!?.";
	while (start < text.size()) {
		if (strchr(semne, text[start])) {
			str.push_back(text.substr(0, start + 1));
			text = text.substr(start + 1, text.size());
			start = 0;
		}
		start++;
	}
	return str;
}

map<string, int>  words(string text) {
	map<string, int> W;
	istringstream iss(text);
	string word;
	while (iss >> word) {
		if (!isalnum(word[word.size() - 1]))
			word = word.substr(0, word.size() - 1);
		if (W.find(word) != W.end())
			W.find(word)->second++;
		else W.insert(make_pair(word, 1));
	}
	return W;
}

set<string> makeSet(string str) {
	set<string> S;
	locale loc;
	map<string, int> mp = words(str);
	for (auto it = mp.begin(); it != mp.end(); it++) {
		string word = it->first;
		for (int i = 0; i < word.size(); i++)
			word[i] = tolower(word[i]);
		S.insert(word);
	}
	return S;
}

int main()
{
	if (citire_cu_verificare("file.in")) {
		vector<string> propo = Propo(sir);
		//loop(propo.size()) {
		//cout << propo[i] << endl;
		//}
		map<string, int> Words = words(sir);
		for (auto it = Words.begin(); it != Words.end(); it++) {
			//cout << it->first << ' ' << it->second << endl;
		}

		set<string> S = makeSet(sir);
		for (auto it = S.begin(); it != S.end(); it++) {
			cout << *it << endl;
		}
	}
	else printf("Textul nu e valid");
	cin.get();
}