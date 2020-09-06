#pragma once
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iterator>
#include <numeric>
#include <algorithm> 
#include <functional>
#include <set>
#include <cctype>

using namespace std;



class Dog
{

    string name;  string breed;  string age;  string gender;

public:
    Dog() = default; 
    Dog(string n, string b, string a, string g);

    //Special member functions
    Dog(const Dog&) = default; 
    Dog& operator=(const Dog&) = default;
    Dog(Dog&&) = default; 
    Dog& operator=(Dog&&) = default;
   ~Dog() = default;

   

    friend ostream& operator<<(ostream&, const Dog&);
    friend istream& operator>>(istream&, Dog&);

    // GETTERS
    string getBreed() const;
    string get_name() const;
    string get_age() const;
    string get_gender() const;

    //SETTERS
    void set_breed(string&);
    void set_name(string&);
    void set_age(string&);
    void set_gender(string&);

    
};

using DogMapDefault = multimap<string, Dog>;
using DogMapGreater = multimap<string, Dog, greater<string>>;
//using DogMapCompare = multimap<string, Dog, MyCompare>;


//templatized so that different types of map can be passed
template<typename MultiMapType>
inline void load_csvFile_Normal_Loop(MultiMapType& dog_map, std::string filename)
{
    ifstream input_file_stream(filename); // Create an input file stream
    if (!input_file_stream.is_open())
    {        // Check if the file cannot be opened
        cout << "Could not open file " + filename << endl;
        throw std::runtime_error("Could not open file " + filename);
    }

    string line;
    for (string line; getline(input_file_stream, line); )
    {
        stringstream my_line_stream(line); // turn the line into an input stream
        Dog dog{};
        my_line_stream >> dog;                  // initialize dog using Dog's operator>>
        dog_map.emplace(dog.getBreed(), dog);   // insert dog into dog_map
    }

    input_file_stream.close(); // Close file
}

void load_csvFile_For_Each(DogMapDefault& dog_map, string filename);
void load_csvFile_Transform(DogMapDefault& dog_map, string filename);



//This function is defined in assignment and is used to find the key entered by user and  return the std::pair, theones matches with those keys
template<typename MultiMapType>
inline MultiMapType findBreedRange(MultiMapType& Dogmap, const std::string& key_breed)
{

    auto it = Dogmap.equal_range(key_breed);
    MultiMapType tempMap;
    for (auto i = it.first; i != it.second; ++i)
    {
        tempMap.emplace(i->first, i->second);
    }
    return tempMap;
}



//templatized and overloaded << operator so that one function can take in different type of multimap with comparator
template<typename Comp>
inline ostream& operator<<(ostream& sout, const std::multimap<std::string, Dog, Comp>& dogmap)
{
    for (const auto& dog : dogmap)
    {
        cout << setw(25) << dog.first << " --> " << dog.second << endl;
    }
    return sout;
}



//istream& operator>>(istream&, const DogMapDefault&);
string trim(const string& str);


