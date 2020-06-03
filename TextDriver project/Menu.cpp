#include "Menu.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;



//DEFAULT CONSTRUCTOR
Menu::Menu() :minimalStringLiteral("??"), top_message(""), bottom_message(""), capacity{1}, count{ 0 }
{
	this->option_list = new Text[capacity];
	/*cout << "default Menu constrcutor" << endl;*/

}

//COPY CONSTRUCTOR
Menu::Menu(const Menu& mnu):minimalStringLiteral(mnu.minimalStringLiteral), top_message(mnu.top_message), bottom_message(mnu.bottom_message), capacity(mnu.capacity), count(mnu.count)
{
	this->option_list = new Text[this->capacity];
	for (size_t i = 1; i <= mnu.count; i++)
	{
		this->option_list[i - 1] = mnu.option_list[i - 1];
	}
}



//OPERATOR = OVERLOADING
Menu& Menu::operator=(const Menu& m)
{
	//cout << "copy assignment overload" << endl;
	if (this == &m) //self assignment, same memory addresses
	{
		return *this;
	}
	else if (this != &m)
	{
		delete[] this->option_list;
		this->option_list = nullptr;
		this->capacity = m.capacity+1;
		this->option_list = new Text[this->capacity];
		this->count = m.count;
		this->top_message = m.top_message;
		this->bottom_message = m.bottom_message;
		this->minimalStringLiteral = m.minimalStringLiteral;

		for (size_t i = 1; i <= m.count; i++)
		{
			this->option_list[i - 1] = m.option_list[i - 1];
		}

	}
}





//DOUBLING CAPACITY
void Menu::double_capacity()
{
	/*doubling capacity, creating temp of Text type for options list
	and then reassigning, same concept*/
	int tempCapacity = 2 * this->capacity;
	Text* temp = new Text[tempCapacity];
	for (size_t i = 1; i <=this->count; i++)
	{	
		temp[i-1] = this->option_list[i-1];
	}
	delete[]this->option_list;
	this->option_list = temp;
	this->capacity*=2;
	/*cout << "capacity doubled to:" << this->capacity;*/
}







//GET CAPACITY , GET NO# OF TEXT OBJECTS RESIDES IN OPTION_LIST
int const Menu::getCapacity()
{
	return this->capacity;
}



//PUSH BACK TEXT, ADD AT LAST
void Menu::push_back(const char* pOption)
{	/*just checking here the last index of dynamically allocated text array
	is empty*/
	if (this->option_list[(this->capacity) - 1].isEmpty())
	{
		this->option_list[this->count] = Text(pOption);		
	}
	else {
		/* otherwise we double the capacity*/
		this->double_capacity();
		this->option_list[this->count] = Text(pOption);	
	}
	this->count++;

}

//PUSH BACK [[TEXT OBJECT]], ADD AT LAST
void Menu::push_back(const Text& option)
{
	this->push_back(option.getCstring());//delegated to above method after extracting cString
}


//INSERTION AT SPECIFIC INDEX [[TEXT OBJECT]]
void Menu::insert(int index, Text& option)
{
	this->insert(index,option.getCstring()); //simply delegated down below after extracting cString
}

//INSERTION AT SPECIFIC INDEX [[TEXT]]
void Menu::insert(int index, const char* option)
{
	if (index > this->count || index <= 0 || this->isEmpty())
	{
		cout << "out of bounds, no such option/index, exiting, trynext time!" << endl;
	}
	else 
	{
		/*created a temp menu
		loop through this.menu options  and just assigning options to temp which
		is of previous index of this. menu options
		and then reassigning this object to temp*/
		Menu temp = *this;
		temp.option_list[index-1]=option;
		for (size_t i = index+1; i <= this->count+1; i++)
		{
			temp.option_list[i-1] = this->option_list[i - 2];
		}
		temp.count++;
		*this = temp;
		cout << " \""<<option<<"\" inserted successfully" <<" at option " << index<< endl;
	} 

	cout << *this;

}



//REMOVE OPTION AT SPECIFIC INDEX
void Menu::remove(int index)
{
	if (index > this->count || index <= 0 || this->isEmpty())
	{
		cout << "out of bounds, no such option/index, exiting, try next time!" << endl;
	}
	else 
	{

		/*created a temp menu
		loop through this.menu options excluding the one that
		is being removed and just assigning options to temp.
		and then reassigning this object to temp*/
		Menu temp = *this;
		
		for (size_t i = index; i <= this->count - 1; i++)
		{
			temp.option_list[i - 1] = this->option_list[i];
		}
		temp.count--;
		
		cout << "\nOption " << index << " \"" << this->option_list[index-1] << "\" removed successfully!" <<endl;
		*this = temp;
		cout << *this;
	}
}

//POP, REMOVE LAST OPTION
void Menu::pop_back()
{
	if (this->isEmpty())
	{
		cout << "Nothing to remove, option list is empty"<<endl;
	}
	else 
	{/*getting to the last option which is count-1 since arrays are 0 based*/
		this->option_list[(this->count) - 1].clear();
		this->count--;
	}
	
}









//GET KTH OPTION
Text Menu::get(int k)
{
	// check for subscript out-of-range error
	if (k <= 0 || k > this->count)
	{
		throw std::out_of_range::out_of_range("\nNo such option");
	}
	return this->option_list[k - 1];
}


//READ AND GET OPTION NUMBER
int Menu::read_option_number()
{/*if there are no options then just return what user entered*/
	int optionNumber;
	if (this->isEmpty()) 
	{
		cin >> optionNumber;
		return optionNumber;		
	}
	
	else 
	{/*if option list exists and wrong choice entered, it will keep looping*/
		cout << *this;
		while (true)
		{				
			cin >> optionNumber;

			if (optionNumber > 0 && optionNumber <= this->count)
			{
				return optionNumber;
				
			}
			cout << "\nInvalid choice: " << optionNumber << ". It must be in the range" << "[" << 1 << "," << this->count << "]" << endl;
			cout << '\n'<<*this;
		}
	}
}








//SET TOP MESSAGE OF MENU
void Menu::set_top_message(const Text& m)
{
	this->top_message=m;
}

//SET BOTTOM MESSAGE OF MENU
void Menu::set_bottom_message(const Text& m)
{
	this->bottom_message=m;
}

//CLEAR TOP MESSAGE
void Menu::clear_top_message()
{
	this->top_message.clear();
}

//CLEAR BOTTOM MESSAGE
void Menu::clear_bottom_message()
{
	this->bottom_message.clear();
}





//RETURN TOTAL OPTIONS COUNT
int const Menu::size()
{
	return this->count;
}



//TO STRING
Text Menu::toString() const
{
	Text tempText;
	/*I am taking whole menu and it's variables, converting into one large menu and storing it in
	Text tempText and returning it*/

	tempText.assign(this->top_message.getCstring());
	tempText.append("\n");

	for (size_t i = 1; i <= this->count; i++)
	{
		tempText.append(" ");
		tempText.append(std::to_string(i).c_str());
		tempText.append(":");
		tempText.append(this->option_list[i - 1].getCstring());
		tempText.append("\n");
	}
	tempText.append(this->bottom_message.getCstring());
	tempText.append("\n");
	tempText.append(this->minimalStringLiteral.getCstring());
	tempText.append(" ");
	

	return tempText.getCstring();
}




//OVERRIDING <<
  ostream&  operator<<( ostream& sout, const Menu& mnu) 
{
	sout << '\n' << "===========================================" << endl;

	  sout<<mnu.toString();//returning complete menu from above toString()

	return sout;
}



//IF OPTION LIST IS EMPTY
bool const Menu::isEmpty()
{
	if (count == 0)
	{
		return true;
	}
	return false;
}




//DESTRUCTOR
Menu::~Menu()
{
	/*cout << "menu destructor called" << endl;*/
	delete[] this->option_list;
	this->option_list = nullptr;
}


