#include "SlotMachine.h"



/*
 Keeps prompting the user until a right integer is entered
*/
int SlotMachine::get_user_bet_input()
{
	int input;
	while ((cin >> input).fail() || input < 0 || input > current_tokens|| cin.peek() != '\n') //checking negative /bettingmore than token /line breaks
	{ 
		cin.clear();
		while (cin.get() != '\n') {
			continue;
			cin >> input;
		}
		if (input < 0) {
			cout << "Negative/invalid integer, try again!" << endl; // keeps re-prompting user if the input is invalid (negative)
		}
		else if (input > current_tokens) {
			cout << "You can't bet more than "<<current_tokens<<" , try again!" << endl; // keeps re-prompting user if the input is invalid (15)
		}
		else
		{
			cout << "Please enter valid positive input, try again!" << endl;
		}
	}
	return input; 

}

/*
Looping through an array of reels so that each reel can have a random shape
*/
void SlotMachine::make_shapes()
{
	for (int k = 0; k < 3; ++k)
	{
		make_shape(k);				//For each reel, generate a random shape
	}
}


void SlotMachine::make_shape(int k)
{
	int n = rand() % 4; // Generate a random integer n,  0 <= n <= 3
	int w =(rand() % 25) + 1; // Generate a random width w, 1 <=w <= 25

	//on the basis of what rand num is generated above, reel will be assigned a shape according to if statement below
	switch (n)
	{
	case 0:
		reel[k].reset(new Rhombus(w, "Diamond")); //  reel points to a Rhombus object of width w
		break;
	case 1:
		reel[k].reset(new AcuteTriangle(w, "Wedge")); //  reel points to a AccuteTriangle object of width w
		break;
	case 2:
		reel[k].reset(new RightTriangle(w, "Ladder")); //  reel points to a RightTriangle object of width w
		break;
	default:
		int h = (rand() % 25) + 1; // Generate a random height h, 1 <= h <= 25
		reel[k].reset(new Rectangle(w, h, "Rectangle")); //  reel points to a Rectangle object of width w and height h
		break;
	}
}


/*
Display method to display reels side by side
*/
void SlotMachine::display()
{
	Grid box_0 = reel[0]->draw();
	Grid box_1 = reel[1]->draw();
	Grid box_2 = reel[2]->draw();

	//cout << box_0;
	//cout << box_1;
	//cout << box_2;

	int arr[3] = { box_0.size() ,box_1.size() ,box_2.size() }; // add all 3 box sizes into an array
	int* maxSize = max_element(std::begin(arr), std::end(arr)); // find the max value from the array because drawings will extend according to the biggest shape

	for (int i = 0; i < (reel[0])->get_width() + 3; ++i) // for each row vector in the grid
	{
		if (i == 0) { cout << "+"; }
		else { cout << "-"; }
	}
	for (int i = 0; i < (reel[1])->get_width() + 3; ++i) // for each row vector in the grid
	{
		if (i == 0) { cout << "+"; }
		else { cout << "-"; }
	}
	for (int i = 0; i < (reel[2])->get_width() + 3; ++i) // for each row vector in the grid
	{
		if (i == 0) { cout << "+"; }
		else { cout << "-"; }
	}
	cout << "+" << endl;
	for (int j = 0; j < *maxSize; ++j) // for each row vector in the grid
	{
		cout << "| ";
		if (j < box_0.size())
		{
			for (auto& element : box_0[j]) // for each element (char) in the row vector
			{
				cout << element;
			}
		}
		else
		{
			for (auto& element : box_0[0]) // for each element (char) in the row vector
			{
				cout << " ";
			}
		}
		cout << " | ";
		if (j < box_1.size())
		{
			for (auto& element : box_1[j]) // for each element (char) in the row vector
			{
				cout << element;
			}
		}
		else
		{
			for (auto& element : box_1[0]) // for each element (char) in the row vector
			{
				cout << " ";
			}
		}
		cout << " | ";
		if (j < box_2.size())
		{
			for (auto& element : box_2[j]) // for each element (char) in the row vector
			{
				cout << element;
			}
		}
		else
		{
			for (auto& element : box_2[0]) // for each element (char) in the row vector
			{
				cout << " ";
			}
		}
		cout << " |";
		cout << endl; // line break
	}
	for (int i = 0; i < (reel[0])->get_width() + 3; ++i) // for each row vector in the grid
	{
		if (i == 0) { cout << "+"; }
		else { cout << "-"; }
	}
	for (int i = 0; i < (reel[1])->get_width() + 3; ++i) // for each row vector in the grid
	{
		if (i == 0) { cout << "+"; }
		else { cout << "-"; }
	}
	for (int i = 0; i < (reel[2])->get_width() + 3; ++i) // for each row vector in the grid
	{
		if (i == 0) { cout << "+"; }
		else { cout << "-"; }
	}
	cout << "+" << endl;
}




void SlotMachine::run(int t)
{
	cout << "Welcome to 3-Reel Lucky Slot Machine Game!" << endl;
	cout << "Each reel will randomly display one of four shapes, each in 25 sizes." << endl;
	cout << "To win 3 x bet, get 2 similar shapes AND 2 shapes with equal Scr Areas" << endl;
	cout << "To win 2 x bet, get 3 similar shapes" << endl;
	cout << "To win 1 x bet, get (Middle) Scr Area > (Left + Right) Scr Areas" << endl;
	cout << "To win or lose nothing, get same Left and Right shapes" << endl;
	cout << "Otherwise, you lose your bet." << endl;
	cout << "You start with 10 free slot tokens!" << endl;

	current_tokens=t; //default tokens
	unsigned bet;

	while (true)			//keep looping until user decides to input 0 to quit
	{
		cout << "\nHow much would you like to bet(enter 0 to quit)? ";
		bet = get_user_bet_input(); // get the number from user input and store in bet

		if (bet == 0) // if user explicitly wants to quit
		{
			cout << "Thank you for playing, come back soon!" << endl;
			cout << "Be sure you cash in your remaing " << current_tokens << " tokens at the bar!" << endl;
			cout << "Game Over." << endl;
			break; 
		}
		make_shapes(); //generating random shapes on each of the 3 reels

		
			display(); // Printing three reels side by side.
		
		
		//PUTTING IN IF CONDITIONS ACCORDING TO WHEN A BET SHOULD BE MULTIPLIED AND LOOSING

		if (((reel[0])->get_name() == (reel[1])->get_name() || (reel[1])->get_name() == (reel[2])->get_name()
			|| (reel[2])->get_name() == (reel[0])->get_name()) 
			&& ((reel[0])->get_screen_area() == (reel[1])->get_screen_area() || (reel[1])->get_screen_area() == (reel[2])->get_screen_area()
			|| (reel[2])->get_screen_area() == (reel[0])->get_screen_area()))
		{
			// 3 x bet if any two symbols are similar in shape and any two match in screen areas
			cout << "(" << (reel[0])->get_name() << ", " << (reel[0])->get_width() << ", " << (reel[0])->get_height() << ") ";
			cout << "(" << (reel[1])->get_name() << ", " << (reel[1])->get_width() << ", " << (reel[1])->get_height() << ") ";
			cout << "(" << (reel[2])->get_name() << ", " << (reel[2])->get_width() << ", " << (reel[2])->get_height() << ") " << endl;

			current_tokens = current_tokens + (3 * bet);
			cout << "Jackpot! 2 Similar Shapes AND 2 Equal Screen Areas" << endl;
			cout << "Congratulations! You win 3 times your bet : " << bet * 3 << endl;
			cout << "You now have " << current_tokens << " tokens" << endl;
		}

		else if ((reel[0])->get_name() == (reel[1])->get_name() && (reel[1])->get_name() == (reel[2])->get_name()
			&& (reel[2])->get_name() == (reel[0])->get_name()) // if all three are similar in shape
		{
			//2 x bet if all three symbols are similar in shape
			cout << "(" << (reel[0])->get_name() << ", " << (reel[0])->get_width() << ", " << (reel[0])->get_height() << ") ";
			cout << "(" << (reel[1])->get_name() << ", " << (reel[1])->get_width() << ", " << (reel[1])->get_height() << ") ";
			cout << "(" << (reel[2])->get_name() << ", " << (reel[2])->get_width() << ", " << (reel[2])->get_height() << ") " << endl;
			current_tokens = current_tokens + (2 * bet);
			cout << "Three similar shapes" << endl;
			cout << "Congratulations! You win 2 times your bet : " << bet * 2 << endl;
			cout << "You now have " << current_tokens << " tokens" << endl;
		}

		else if ((reel[1])->get_screen_area() > ((reel[0])->get_screen_area() + (reel[2])->get_screen_area()))
		{
			// 1 x  bet if screen area of middle symbol>sum of screen areas of left and right symbols
			cout << "(" << (reel[0])->get_name() << ", " << (reel[0])->get_width() << ", " << (reel[0])->get_height() << ") ";
			cout << "(" << (reel[1])->get_name() << ", " << (reel[1])->get_width() << ", " << (reel[1])->get_height() << ") ";
			cout << "(" << (reel[2])->get_name() << ", " << (reel[2])->get_width() << ", " << (reel[2])->get_height() << ") " << endl;
			current_tokens = current_tokens + (1 * bet);
			cout << "Middle > Left + Right , in Screen Areas" << endl;
			cout << "Congratulations! You win your bet : " << bet * 1 << endl;
			cout << "You now have " << current_tokens << " tokens" << endl;
		}

		else if ((reel[0])->get_name() != (reel[1])->get_name() && (reel[1])->get_name() != (reel[2])->get_name()
			&& (reel[2])->get_name() == (reel[0])->get_name()) // if the left and right symbols are similar
		{
			//0 x bet if the leftand right symbols are similar
			cout << "(" << (reel[0])->get_name() << ", " << (reel[0])->get_width() << ", " << (reel[0])->get_height() << ") ";
			cout << "(" << (reel[1])->get_name() << ", " << (reel[1])->get_width() << ", " << (reel[1])->get_height() << ") ";
			cout << "(" << (reel[2])->get_name() << ", " << (reel[2])->get_width() << ", " << (reel[2])->get_height() << ") " << endl;

			cout << "Lucky this time !" << endl;
			cout << "You don't win, you don't lose, your are safe ! " << endl;
			cout << "You now have " << current_tokens << " tokens" << endl;
		}
		else
		{ 
			// -1 x bet otherwise, player loses the bet
			cout << "(" << (reel[0])->get_name() << ", " << (reel[0])->get_width() << ", " << (reel[0])->get_height() << ") ";
			cout << "(" << (reel[1])->get_name() << ", " << (reel[1])->get_width() << ", " << (reel[1])->get_height() << ") ";
			cout << "(" << (reel[2])->get_name() << ", " << (reel[2])->get_width() << ", " << (reel[2])->get_height() << ") " << endl;
			current_tokens = current_tokens - bet;
			if (current_tokens <= 0) current_tokens = 0;
			cout << "Oh No!" << endl;
			cout << "You lose your bet " << endl;
			cout << "You now have " << current_tokens << " tokens" << endl;
			
		}
		if (current_tokens < 1)
		{
			cout << "You just ran out of tokens. Better luck next time!" << endl;
			cout << "Game Over." << endl;
			break; 
		}
		
	}

}
	
