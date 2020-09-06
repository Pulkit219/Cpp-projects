#include "Dog.h"
#include <iterator>

Dog::Dog(string n, string b, string a, string g) : name(n), breed(b), age(a), gender(g)
{ }







ostream& operator<<(ostream& sout, const Dog& dog) {
    sout << dog.name << ", " << dog.breed << ", " << dog.age << ", " << dog.gender;
    return sout;
}

/*
=======================================
TASK 3.1
=======================================
//this function I've templatized it so it will be found in .h file

/*
=======================================
TASK 3.2
=======================================
*/
void load_csvFile_For_Each(DogMapDefault& dog_map, string filename)
{
    ifstream input_file_stream(filename); // Create an input file stream
    if (!input_file_stream.is_open())
    {        // Check if the file cannot be opened
        cout << "Could not open file " + filename << endl;
        throw std::runtime_error("Could not open file " + filename);
    }

   istream_iterator<Dog> input_stream_begin{ input_file_stream };
   istream_iterator<Dog> input_stream_end{};
   for_each(input_stream_begin, input_stream_end, [&dog_map](Dog dog){
       dog_map.emplace(dog.getBreed(), dog);       
       });

    input_file_stream.close(); // Close file
}



/*
=======================================
TASK 3.3
=======================================
*/
void load_csvFile_Transform(DogMapDefault& dog_map, string filename)
{


    ifstream input_file_stream(filename); // Create an input file stream
    if (!input_file_stream.is_open())
    {        // Check if the file cannot be opened
        cout << "Could not open file " + filename << endl;
        throw std::runtime_error("Could not open file " + filename);
    }

    istream_iterator<Dog> input_stream_begin{ input_file_stream };
    istream_iterator<Dog> input_stream_end{};
    //ostream_iterator<Dog> cout_it(cout, " ");
    std::transform(input_stream_begin, input_stream_end, std::inserter(dog_map, dog_map.begin()), [](Dog dog) {
        return make_pair(dog.getBreed(), dog); });
        
}



istream& operator>>(istream& sin, Dog& dog) {
    // your task: validate input.
    // If invalid, throw std::runtime_error("Invalid input line "); 
    bool pass{ false };
    if (std::getline(sin, dog.name, ','))
    {
        if (std::getline(sin, dog.breed, ','))
        {
            if (std::getline(sin, dog.age, ','))
            {
                if (std::getline(sin, dog.gender))
                {
                    pass = true;
                }
            }
        }
    }
    if (pass == false && !sin.eof())
    {
        throw std::runtime_error("Invalid input line");
    }
    dog.name = trim(dog.name);
    dog.breed = trim(dog.breed);
    dog.age = trim(dog.age);
    dog.gender = trim(dog.gender);
    return sin;                                                  
}






//
//istream& operator>>(istream& sin, const DogMapDefault&)
//{
//    return sin;
//}




string trim(const string& str)      //USING AN OPEN SOURCE STRING FIND ALGORITHM TO REMOVE TRAILING AND LEADING SPACES
{
    string str1 = str;
    const string WHITESPACE = " \n\r\t\f\v";
 
        size_t start = str1.find_first_not_of(WHITESPACE);
        string str2= (start == std::string::npos) ? "" : str1.substr(start);
      
        size_t end = str2.find_last_not_of(WHITESPACE);
        string str3= (end == std::string::npos) ? "" : str2.substr(0, end + 1);
    
        return str3;
   
}





//GETTERS=========================
string Dog::getBreed() const
{
    return this->breed;
}

string Dog::get_name() const
{
    return this->name;
}

string Dog::get_age() const
{
    return this->age;
}

string Dog::get_gender() const
{
    return this->gender;
}




//SETTERS=========================
void Dog::set_breed(string& breed)
{
    this->breed = breed;
}

void Dog::set_name(string& name)
{
    this->name = name;
}

void Dog::set_age(string& age)
{
    this->age = age;
}

void Dog::set_gender(string& gender)
{
    this->gender = gender;
}






