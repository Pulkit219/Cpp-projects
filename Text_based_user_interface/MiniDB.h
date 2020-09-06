#pragma once
#include<iostream>
#include<list>
#include <algorithm>
#include <iterator>
#include <fstream>
using std::ofstream;

using std::cout;
using std::endl;
using std::list;
using std::cerr;


template < typename T> 
class MiniDB {

private:
	list<T> db_store;
	typename list<T>::iterator cp;

public:
	const T& getValue() const;
	size_t size() const;
	void insert(const T& item);
	void append(const T& item);
	void prev();
	void next();
	T remove();
	void moveToFirst();
	void moveToLast();
	size_t getCurrentIndex() const ;
	void moveToIndex(size_t index);
    void print();
    void print_span(size_t lower_span, size_t upper_span);
    short int get_max_current_upper_span();
    short int get_max_current_lower_span();
    void write_miniDB_to_file(string);
};



template<typename T>
inline const T& MiniDB<T>::getValue() const //returns current value cp points at
{
    return *cp;
}



template<typename T>
  inline size_t MiniDB<T>::size() const     //returns size of the list db
  {
	return this->db_store.size();
  }



  template<typename T>
  inline void MiniDB<T>::insert(const T& item)  //inserting the item at the place where cp is pointing at
  {
      this->db_store.insert(cp, item);
  }



  template<typename T>
  inline void MiniDB<T>::append(const T& item)
  {
      this->db_store.push_back(item);
      this->moveToLast();       //after appending, moving the cp all the way to the last element inserted
  }



  template<typename T>
  inline void MiniDB<T>::prev()         //to move pointer one step back
  {
      
          if (this->cp != this->db_store.begin()) //checking if it is not pointing to beginning, then only decrement it
          {
              --cp;
          }
          else if(this->cp == this->db_store.begin())
          {              
              return;
          }
          else
          {
              throw std::logic_error(" pointer undefined");
          }
               
   
  }



  template<typename T>
  inline void MiniDB<T>::next()     //to move pointer one step forward
  {
   
          auto  it = this->db_store.end();
          --it;
          if (this->cp != this->db_store.end() && this->cp != it) //checking if it is not pointing to end() undefined or to the last element, then only increment it
          {
              ++this->cp;
          }
          else if(this->cp == it)
          {
              return;              
          }
          else
          {
              throw std::logic_error(" pointer undefined");
          }

  }
  



  template<typename T>
  inline T MiniDB<T>::remove()
  {
      string temp =  *cp;
      cp=this->db_store.erase(cp); //erasing the line cp points at and then pointer moving to next
      if (cp == this->db_store.end()) //if there is nothing exists in next then go back --cp
      {
          this->prev();
      }
      if (cp == this->db_store.end())//if the previous one is also undefined then reset to beginning
      {
          this->moveToFirst();
      }
      return temp;
  }



  template<typename T>
  inline void MiniDB<T>::moveToFirst()      //move the cp to the very beginning of the list
  {
      this->cp = this->db_store.begin();
  }



  template<typename T>
  inline void MiniDB<T>::moveToLast()       //move the cp to the very end of the list
  {
      this->cp = this->db_store.end();
      this->prev();
  }



  template<typename T>
  inline  size_t MiniDB<T>::getCurrentIndex() const
  {
      typename  std::list<T>::const_iterator first = this->db_store.begin();
      typename  std::list<T>::const_iterator second = this->cp;
      return std::distance(first, second); // STL function to provide zero-based index cp is pointing at currently 
  }



  template<typename T>
  inline void MiniDB<T>::moveToIndex(size_t user_index)
  {
      size_t current_user_cp = this->getCurrentIndex() + 1; //simply getting current one-based index for user's ease
      if (current_user_cp > user_index)
      {
          cp = std::prev(cp, current_user_cp- user_index); //moving cp steps backward using std::prev
      }
      else if (current_user_cp < user_index)
      {
          cp = std::next(cp, user_index- current_user_cp);  //advancing cp steps using std::next
      }
      else
      {
          return;               //if in case user types the same line where cp is already pointing then just return
      }
      
  }





  template<typename T>
  inline void MiniDB<T>::print()
  {

      for (auto it = this->db_store.cbegin(); it != this->db_store.cend(); it++)
    {
      //const_iterator auto it2 = this->db_store.begin();
        typename  std::list<T>::const_iterator first = this->db_store.begin();
        cout << std::distance(first, it)+1 << ": ";        //std:distance will keep calculating the distance at every iteration and helps print line number to teh console
        cout << *it << '\n';                        //looping through the entire list to print all the elements
    }
        this->moveToLast();                           //setting the cp to the last line printed
      
  }



  template<typename T>
  inline void MiniDB<T>::print_span(size_t lower_span, size_t upper_span)   //divided it into 2 parts
  {
      //PRINTING FROM FIRST ELEMENT TO CURRENT POINTER I.E UPPER SPAN

      list<T> db_store_copy1;       // we will use it to temp store the upper span elements with line numbers

      size_t ind = std::distance(this->db_store.begin(), this->cp);     //getting the distance so that we can get to know exactly up to how many indexes we've to loop, it doesn't go out of bounds
      auto it1 = this->cp;
      for (size_t i = 0; i <= ind; i++)
      {
          if (i == upper_span + 1)    //as soon as i reaches upper range entered by user, break the loop since we don't want to store entire list
          {
              break;
          }
          string index = std::to_string(std::distance(this->db_store.begin(), it1) + 1); //creating string 1-based indexes to be displayed with lines

          db_store_copy1.push_front(index + ": " + *it1);   //with the help of push_front, we are able to temp store upper_span elements with line numbers 

          if (i == ind)         //it is important to insert if here because if it's decrementing, it will point to undefined and program will crash
          {
              break;            //therefore it must break the for loop before decrementing
          }
          it1--;
      }
      if (db_store_copy1.size() <= upper_span)    //this is to display if upper_span is somewhere near starting of list then it must print BOF
      {
          cout << "**: BOF\n";
      }
      for (auto& elem : db_store_copy1)     //now simply printing all elements stored in copy
      {          
          cout << elem << endl;
      }

//PRINTING FROM CURRENT POINTER PLUS ONE TO LAST ELEMENT I.E LOWER SPAN
      auto it2 = this->cp;
      it2++;                //incrementing it first because we don't want to print the same element again
      int j{ 1 };
      for (; it2 != this->db_store.end(); it2++)
      {
          if (j == lower_span + 1)  //as soon as i reaches lower range entered by user, break the loop since we don't want to print the entire list
          {
              break;
          }
          cout << std::distance(this->db_store.begin(), it2)+1 << ": ";     //printing  the line numbers
          cout << *it2 << endl;                                             //printing the actual element
          j++;          
      }

      //this piece of code below is just to see if dbstore has reached end of file while printing span of lower lines, to print EOF:
      auto it3 = this->db_store.end();
      --it3;        //now pointing to last element
      if (std::distance(this->cp, it3) < lower_span)   //whenever distance is lesser than lower_span, it always means lower span is by the end
      {
          cout << "**: EOF\n";
      }

      --it2;            //decrement and assigning so cp will point to the last line printed
      this->cp = it2;
  }







  template<typename T>
  inline short int MiniDB<T>::get_max_current_upper_span()      // return the max upper span of lines from cp
  {
      return std::distance(this->db_store.begin(), this->cp);
  }

  template<typename T>
  inline short int MiniDB<T>::get_max_current_lower_span()      // return the max lower span of lines from cp
  {
      auto it3 = this->db_store.end();
      --it3;
      return std::distance(this->cp, it3);
  }





  template<typename T>
  inline void MiniDB<T>::write_miniDB_to_file(string file_name)
  {
      ofstream myfile(file_name);
      if (!myfile)
      {
          cerr << "ERROR writing to file. Please check filename/path." << endl;
      }
      
 
    else if (myfile.is_open())
      {
              for (auto it = this->db_store.cbegin(); it != this->db_store.cend(); it++)
              {
                  myfile << *it << '\n';
              }

      }
          myfile.close();
  }





