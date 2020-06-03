#include "Text.h"
#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)

using std::cout;
using std::endl;
using std::ostream;

//CONVERSION CONTRUCTOR
Text::Text(const char* pCstr):pStore{new char[ strlen(pCstr) + 1 ]}
{
	/*cout << "Text conversion constr called" << endl;*/
	
	
	/*this->pStore = new char[strlen(pCstr) + 1];*/
	strcpy(this->pStore, pCstr);
	
}

//DEFAULT CONSTRUTOR
Text::Text():Text("") //delegating to above conversion constr
	
{
	/*cout << "Text no args contructor"<<endl;*/
}

//COPY CONSTRUCTOR
Text::Text(const Text& source):Text(source.pStore) //delegating to conversion const
{
	/*cout << "Text copy contructor" << endl;*/
	
}


//ASSIGN CHAR TEXT and REPLACE EXISTING CONTENTS
void Text::assign(const char* psCstr)
{
	/*cout<<"assigns a Cstring to this object replacing its current contents"<<endl;*/
	
	/*delete existing pointer, freeing up dynamic memory
	and creating a new one*/
	delete[] this->pStore;
	this->pStore = nullptr;
	this->pStore = new char[strlen(psCstr) + 1];
	strcpy(this->pStore, psCstr);
}

void Text::assign(const Text& txt)
{
	//cout << "Assigns a Text object to this object, replacing its current contents" << endl;
	/*delete existing pointer, freeing up dyna,ic memory
	and creating a new one*/
	delete[] this->pStore;
	this->pStore = nullptr;
	this->pStore = new char[strlen(txt.pStore) + 1];
	strcpy(this->pStore, txt.pStore);
}


//ASSIGNMENT OPERATOR OVERLOAD
 Text& Text::operator=(const Text& txt)
{
	//cout << "copy assignment overload" << endl;
	if (this == &txt) //self assignment, same memory addresses
	{
		return *this;
	}
	else if (this != &txt)
	{
		assign(txt); //delegating to above assign method accepting objects as  args

	/*	delete[] this->pStore;
		this->pStore=nullptr;
		this->pStore =new char[strlen(txt.pStore) + 1];
		strcpy(this->pStore, txt.pStore);*/

	
	};
	
	

}



//APPENDING REGULAR TEXT
void Text::append(const char* pCstr)
{
	
	char* temp{ new char[strlen(pCstr) + strlen(this->pStore) + 1] };
	strcpy(temp, this->pStore);
	strcat(temp, pCstr);
	delete[] this->pStore;
	this->pStore = temp;
	temp=nullptr;
}

//APPENDING OBJECT TEXT
void Text::append(const Text& txt)
{
	char* temp{ new char[strlen(this->pStore) + strlen(txt.pStore) + 1] };
	strcpy(temp, this->pStore);
	strcat(temp, txt.pStore);
	delete[] this->pStore;
	this->pStore = nullptr;
	this->pStore = temp;
	temp = nullptr;
}


//CLEAR CSTRING
void Text::clear()
{
	/*delete existing pointer, freeing up dynamic memory
	and creating a new one by assigning to nostring "" */
	delete[] this->pStore;
	this->pStore = nullptr;
	this->pStore = new char[2];
	strcpy(this->pStore,"");
}



//GETTER FOR CSRTING SINCE IT'S PRIVATE VAR
const char* Text::getCstring()  const
{
	return this->pStore;
}


//GET CSTRING LENGTH
int Text::length() const
{
	return strlen(this->pStore);
}


//IS IT EMPTY
bool Text::isEmpty() const
{
	if (strcmp(this->pStore, "")==0)
	{
		return true;
	}
	
	return false;
	
}


//DESTRUCTOR
Text::~Text()
{
	//cout << "destructor" << endl;
	delete[] pStore;
	this->pStore = nullptr; //defensive programming
}

ostream& operator<<(ostream& sout, const Text& txt)
{
	
	sout << txt.getCstring();
	return sout;
}
