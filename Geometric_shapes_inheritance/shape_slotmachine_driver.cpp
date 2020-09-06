
#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "RightTriangle.h"
#include "AcuteTriangle.h"
#include "SlotMachine.h"

using std::cout;
using std::endl;

void poly_draw_shape_by_ref(const Shape& shape, char foreground = '*', char background = ' ')
 { 
    Grid shape_box = shape.draw(foreground, background);
    cout << shape_box << endl;
 }

int main()
{
    //Rectangle* rect = new Rectangle{5,7};
    //cout << rect->toString() << endl;
 /*   Rectangle rect1{ 5,7 };
    cout << rect1 << endl;
    Grid rectbox = rect1.draw();
    cout << rectbox;
   


    Rhombus ace{ 16,"Ace","Ace of diamond" };
    cout << ace << endl;
    Grid aceBox = ace.draw('+','.');
    cout << aceBox << endl;
 

    AcuteTriangle at{17};
    Grid atBox = at.draw('^');
    cout << atBox << endl;



    RightTriangle rt{ 10, "Carpenter's square" };
    Grid rtBox = rt.draw('-');
    cout << rtBox << endl;


    rtBox = rt.draw('\\', 'o');
    cout << rtBox << endl;
    cout << rt << endl;

    aceBox = ace.draw('o');
    cout << aceBox << endl;*/


    //Rectangle rect{ 5, 7 };
    //Rhombus ace{ 16, "Ace", "Ace of diamond" };
    //AcuteTriangle at{ 17 };
    //RightTriangle rt{ 10, "Carpenter's square" };
    //poly_draw_shape_by_ref(rect);
    //poly_draw_shape_by_ref(ace, '+', '.');
    //poly_draw_shape_by_ref(at, '^');
    //poly_draw_shape_by_ref(rt, '-');

    SlotMachine slot_machine; // create a slot machine object
    slot_machine.run(); // run our slot machine until the player decides

  

    return 0;
}
