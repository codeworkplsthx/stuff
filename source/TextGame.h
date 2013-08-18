#include <iostream>
#include <string>
#include <Windows.h>


using namespace std;

class ScrollingText {

public:

	template<typename TEXT>
	void PrintText (TEXT& text, float text_delay = 100)
	{
		string str;
		str.assign(text);

		for (unsigned int i = 0; i < str.length(); i++)
		{
			Sleep(text_delay);
			cout << str.at(i);
		}
	}

};

class Player {


	string name;
	string state;

public:

	string GetName () { return name; };
	void SetName (string str) { name = str; };
	string GetState() { return state; };
	void SetState (string str) { state = str; };
};

class Narrator : public ScrollingText {

public:

	 template<typename INPUT, typename TEXT>
	 INPUT prompt(TEXT& text, float text_delay = 100) 
	 {
		INPUT input;

		PrintText(text, text_delay);
		cout << "> ";
		cin >> input;
		return input;
	 }
	
};

class Vector2d {


public:

	int x;
	int y;

	Vector2d (int x = 0, int y = 0) { x = x; y = y; };
};

