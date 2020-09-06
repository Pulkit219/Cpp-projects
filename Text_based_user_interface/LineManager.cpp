#include "LineManager.h"



void LineManager::set_upper_lower_span(short int&s)
{
	if (s < 0) //checking negative, if user entered for upper span
	{
		short int max_current_upper_span = this->db_store.get_max_current_upper_span();  //getting the max upper span available
		if (-(s) > max_current_upper_span)		//checking if user entered number greater than the span of lines available
		{
			cout << "That's a large span of lines. Max is "<< max_current_upper_span << endl;
		}
		else {
			this->upper_span = -(s);		// we need to store it as positive number
		}
	}
	else if (s > 0) //checking positive, if user entered for lower span
	{
		short int max_current_lower_span = this->db_store.get_max_current_lower_span();
		if (s > max_current_lower_span)		//checking if user entered number greater than the span of lines available
		{
			cout << "That's a large span of lines. Max is " << max_current_lower_span << endl;
		}
		else {
			this->lower_span = s;
		}
	}
	else
	{
		this->lower_span = 0;
		this->upper_span = 0;
	}
}

void LineManager::append_input_from_keyboard(string& line)
{
	this->db_store.append(line);
}

void LineManager::insert_input_from_keyboard(string& line)
{
	this->db_store.insert(line);
}

void LineManager::read_from_file_and_append(string file_name)
{
	ifstream file;
	file.open(file_name);
	if (file)
	{
		string line;
		while (getline(file, line))
		{
			this->db_store.append(line);
		}
		this->db_store.prev();
		file.close();
	}
	else
	{
		cout << "ERROR opening/reading file. Please check filename/path." << endl;
	}
}

void LineManager::read_from_file_and_insert(string file_name)
{
		ifstream file;
		 file.open(file_name);
		 if (file)
		 {
			 string line;
			 while (getline(file, line))
			 {
				 this->db_store.insert(line);
			 }
			 this->db_store.prev();
			 file.close();
		 }
		 else
		 {
			 cout << "ERROR opening/reading file. Please check filename/path." << endl;
		 }
		
}

std::string LineManager::print_current_line()
{
	return this->db_store.getValue();
}

void LineManager::print_span_of_lines(size_t a, size_t b)
{
	this->db_store.print_span(a, b);
}

void LineManager::if_cin_fail()// this function is created to clear any bad state entered by user like strings or special characters
{
	if (cin.fail())
	{
		cout << "\nPlease enter an integer.\n";
		// clear error state
		cin.clear();
	}
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard 'bad' character(s)
}

void LineManager::print_all()
{
	this->db_store.print();
}

void LineManager::move_the_current_line(size_t n)
{
	if (n <= 0 || n > this->db_store.size()) //checking if user enters invalid line that doesn't exists
	{
		cout << " WARNING! Invalid line, line does not exist.\n";
		return;
	}
	this->db_store.moveToIndex(n);
}

void LineManager::delete_the_current_line()
{
	cout << "removing the current line ...\n";
	this->db_store.remove();
}

void LineManager::write_miniDB_to_file(string file_name)
{
	this->db_store.write_miniDB_to_file(file_name);
}





void LineManager::run()
{
	
	bool run = true;
	while (run) //it will keep looping until user choose to quit by choosing appropriate option
	{				//NOTE that partial menu and full menu have their own switch cases for simplicity
		int option;   // to store cin what option user is entering
		string line;					//used to get the lines entered by user from console
		string file_name;	//this var is used to get filename with path
		if (this->db_store.size() == 0) //shows partial menu if DB is empty
		{
			partial_menu.display();
			cin >> option;
			this->if_cin_fail();
			int line_number{ 1 };		//this var is used to display line numbers on console when user is typing
			switch (option) {			//partial menu cases with their corresponding options as shown in PDF

			case 1:				
				cout << "To end input, enter a single dot and press enter\n";
				cout << line_number<<"-> ";
				while (getline(cin, line) && line != ".")
				{					
					this->append_input_from_keyboard(line);
					line_number++;
					cout << line_number << "-> ";
				}
				break;

			case 2:
				cout << "To end input, enter a single dot and press enter\n";
				cout << line_number << "-> ";
				while (getline(cin, line) && line != ".")
				{						
					this->append_input_from_keyboard(line); //WHEN DB IS EMPTY, NOTE THAT IT WORKS SIMILAR TO APPEND
					line_number++;
					cout << line_number << "-> ";
				}
				break;

			case 3:
				cout << "Enter input filename included with path:\n";
				getline(cin, file_name);
				this->read_from_file_and_append(file_name);
				break;

			case 4:
				cout << "Enter input filename included with path:\n";
				getline(cin, file_name);
				this->read_from_file_and_append(file_name);  //WHEN DB IS EMPTY, NOTE THAT IT WORKS  SIMILAR TO APPEND
				break;

			case 5:
				cout << "goodbye";
				run = false;
				break;

			default:
				cout << " Option does not exist. Please try again\n";
				break;

			}
		}





		else						//FULL_MENU switch cases start with their corresponding options as shown in PDF
		{
			full_menu.display();
			cin >> option;
			this->if_cin_fail();
			int line_number{ 1 }; //this var is used to display line numbers on console when user is typing

			switch (option) {

			case 1:
				cout << "To end input, enter a single dot and press enter\n";
				cout << line_number << "-> ";
				while (getline(cin, line) && line != ".")
				{
					this->append_input_from_keyboard(line);
					line_number++;
					cout << line_number << "-> ";
				}
				break;

			case 2:
				cout << "To end input, enter a single dot and press enter\n";
				cout << line_number << "-> ";
				while (getline(cin, line) && line != ".")
				{
					this->insert_input_from_keyboard(line);
					line_number++;
					cout << line_number << "-> ";
				}
				this->db_store.prev();		//setting cp to last line inserted
				break;

			case 3:
				cout << "Enter input filename included with path:\n";
				getline(cin, file_name);
				this->read_from_file_and_append(file_name);
				break;

			case 4:
				cout << "Enter input filename included with path:\n";
				getline(cin, file_name);
				this->read_from_file_and_insert(file_name);
				break;

			case 5:
				cout << this->db_store.getCurrentIndex()+1<<": ";		//converting to 1-based index
				cout << this->print_current_line()<<endl;
				break;

			case 6:
				this->print_span_of_lines(this->lower_span, this->upper_span);
				break;

			case 7:
				cout << "What's the length of the span\n";
				short int z;
				cin >> z;
				this->if_cin_fail();
				this->set_upper_lower_span(z);
				break;

			case 8:
				this->print_all();				
				break;

			case 9:
				cout << "which line to move to\n";
				size_t n;
				cin >> n;
				this->if_cin_fail();
				this->move_the_current_line(n);
				break;

			case 10:				
				this->delete_the_current_line();
				break;

			case 11:
				cout << "Enter input filename included with path:\n";
				getline(cin, file_name);
				this->write_miniDB_to_file(file_name);
				break;

			case 12:
				cout << "goodbye";
				run = false;
				break;
			
			default:
				cout << " Option does not exist. Please try again\n";
				break;
			}

		}
	}
}
	
