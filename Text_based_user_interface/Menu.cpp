#include "Menu.h"
#include <iostream>
using std::cout;
using std::endl;
Menu::Menu():top_message{"\nChoose one of the following options:\n"},bottom_message{"Enter an option number\n??"}
{
	this->optionList.push_back("Append input from the keyboard");
	this->optionList.push_back("Insert input from the keyboard");
	this->optionList.push_back("Append input from text file");
	this->optionList.push_back("Insert input from text file");
	this->optionList.push_back("Quit");

}
Menu::Menu(const string& str) :top_message{ "\nChoose one of the following options:\n" }, bottom_message{ "Enter an option number\n??" }
{
	this->optionList.push_back("Append input from the keyboard");
	this->optionList.push_back("Insert input from the keyboard");
	this->optionList.push_back("Append input from text file");
	this->optionList.push_back("Insert input from text file");
	this->optionList.push_back("Print the current line");
	this->optionList.push_back("Print a span of lines around the current position");
	this->optionList.push_back("Set the length of upper or lower line spans");
	this->optionList.push_back("Print all");
	this->optionList.push_back("Move the current line");
	this->optionList.push_back("Delete the current line");
	this->optionList.push_back("Write mini-database to file");
	this->optionList.push_back("Quit");
}





void Menu::set_top_message(string& message)
{
	this->top_message.assign(message);
}

void Menu::set_bottom_message(string& message)
{
	this->bottom_message.assign(message);
}

void Menu::clear_top_message()
{
	this->top_message="";
}

void Menu::clear_bottom_message()
{
	this->bottom_message="";
}

void Menu::push(string& option)
{
	this->optionList.push_back(option);
}

void Menu::display()
{
	cout << this->top_message;
	for (vector<string>::size_type i = 0; i != optionList.size(); i++) 
	{
		cout <<"    "<< i+1<<":  "<<this->optionList[i] << endl;
	}
	cout << this->bottom_message;
}
