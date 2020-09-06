#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;
class Menu
{
private:
	vector<string> optionList;
	string top_message;
	string bottom_message;

public:
	Menu();
	Menu(const string& str);
	void set_top_message(string& message);
	void set_bottom_message(string& message);
	void clear_top_message();
	void clear_bottom_message();
	void push(string& option);
	void display();
	//menu option functions

};
