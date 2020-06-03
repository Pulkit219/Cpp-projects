#pragma once
#include "Text.h"

class Menu
{
private:

	Text* option_list;
	int capacity;
	int count;
	Text top_message;
	Text bottom_message;
	Text minimalStringLiteral;
	void double_capacity();

public:
	Menu();
	Menu(const Menu& mnu);
	Menu& operator=(const Menu& m);

	void insert(int index, Text& option);
	void insert(int index, const char* option);
	void push_back(const char* pOption);
	void push_back(const Text& option);

	void remove(int index);


	int const size();
	int const getCapacity(); 

	void pop_back();
	Text get(int k);
	Text toString() const;

	int read_option_number();
	


	void set_top_message(const Text& m);
	void set_bottom_message(const Text& m);
	void clear_top_message();
	void clear_bottom_message();

	

	bool const isEmpty();

	virtual ~Menu();

	friend ostream& operator<<(ostream&, const Menu&);

};

