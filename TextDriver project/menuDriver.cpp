
#include <iostream>
#include "Text.h"
#include "Menu.h"
using std::cout;
using std::endl;



void demoText(); // demonstrates Text objects
void demoMenu(); // demonstrates Menu objects


int main()
{
    demoText();
    demoMenu();

    return 0;
     
}


void demoText()
 { 
    
    Text t1; // default constructor
     Text t2("quick brown fox"); // conversion constructor
     Text t3{ t2 }; // copy constructor
     cout << "t1: " << t1 << endl; // operator<< overload
     cout << "t2: " << t2 << endl;
     cout << "t3: " << t3 << endl;

     t1.append("The "); // append a given C-string to t1's C-string
     cout << "t1: " << t1 << endl;
     t1.append(t2); // append t2's C-string to t1's C-string
     cout << "t1: " << t1 << endl;

     t2 = Text(" jumps over "); // assignment operator overload
     cout << "t2: " << t2 << endl;

     t3.assign("a lazy dog"); // assign a given C-string to t3's C-string
     cout << "t3: " << t3 << endl;

     t1.append(t2); // assign t2's C-string to t1's C-string
     cout << "t1: " << t1 << endl;
     t1.append(t3); // append t3's C-string to t1's C-string
     cout << "t1: " << t1 << endl;
     return;


 }

void demoMenu()
{
   
        Menu menu;
        int choice;
        cout << menu << endl;


        choice = menu.read_option_number();
        cout << "you entered: " << choice << endl;


        menu.push_back("Pepsi");
        cout << menu << endl;



        menu.push_back("Apple juice");
        menu.push_back("Root Beer");
        choice = menu.read_option_number();
        cout << "you entered: " << choice << endl;



        menu.set_top_message("Choose your thirst crusher");
        menu.set_bottom_message("Enter a drink number");
        cout << menu << endl;


        menu.pop_back(); // remove the last option
        menu.insert(2, "Iced tea with lemon"); // this will be option 2
        choice = menu.read_option_number();
        cout << "you entered: " << choice << endl;

        menu.pop_back(); // remove the last option
        menu.remove(1); // remove the first option
        cout << menu << endl;


        menu.pop_back();
        cout << menu << endl;


        menu.clear_bottom_message();
        menu.set_top_message("Who Says You Can't Buy Happiness?\n"
            "Just Consider Our Seriously Delicious Ice Cream Flavors");
        menu.set_bottom_message("Enter the number of your Happiness! ");
        menu.push_back("Bacon ice cream!");
        menu.push_back("Strawberry ice cream");
        menu.push_back("Vanilla ice cream");
        menu.push_back("Chocolate chip cookie dough ice cream");
        choice = menu.read_option_number();
        cout << "you entered: " << choice << endl;



        try 
        {
            Text t = menu.get(20);
        }
     
  
         catch (const std::out_of_range& oor)
       {
           std::cerr << "\nOut of Range error: " << oor.what() << '\n';
       }





    //Text t1("hello");

   
   
};