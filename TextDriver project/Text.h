#pragma once
#include <ostream>;
using std::ostream;


class Text
{
private:
	char* pStore{ nullptr};

public:
	Text();
	Text(const char* pCstr);  //conversion constr
	Text(const Text& txt);  //copy contructor
	
	void assign(const char* psCstr);
	void assign(const Text& txt);
	Text& operator=(const Text& txt);

	void append(const char* pCstr);
	void append(const Text& txt);

	
	void clear();


	const char* getCstring() const;

	

	int length() const;
	bool isEmpty() const;
	virtual ~Text();
	
	friend ostream& operator<<(ostream&, const Text&);
	
};



