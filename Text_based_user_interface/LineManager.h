#pragma once
#include "Menu.h"
#include "MiniDB.h"
#include <iostream>
#include <fstream>

using std::ifstream;
using std::ofstream;
using std::cin;
using std::getline;


class LineManager
{

private:
	size_t upper_span=2;
	size_t lower_span=2;
	Menu partial_menu;
	Menu full_menu{"full"};		//creating an object with full menu options
	MiniDB<string> db_store;	
	void if_cin_fail();		//to clear any invalid cin input such as strings

	//private menu functions optionwise
	void append_input_from_keyboard(string&);
	void insert_input_from_keyboard(string&);
	void read_from_file_and_append(string);
	void read_from_file_and_insert(string);
	std::string print_current_line();
	void print_span_of_lines(size_t, size_t);
	void set_upper_lower_span(short int&);
	void print_all();
	void move_the_current_line(size_t n);
	void delete_the_current_line();
	void write_miniDB_to_file(string);

public:
	void run();

};

