#pragma once

#include <array>
#include "Rhombus.h"
#include "Rectangle.h"
#include "AcuteTriangle.h"
#include "RightTriangle.h"
class SlotMachine
{
private:
	int current_tokens;
	std::array<std::unique_ptr<Shape>, 3> reel{}; //three unique pointers stored in array
	void make_shapes(); // it will help reels be ready with random shapes
	void make_shape(int k); // each reel will be assigned a random shape
	void display(); // to display reels side by side
	int get_user_bet_input();  // this func is designed to make sure , user doesn't enter negative or strings or bets more than than the tokens itself
public:
	SlotMachine() = default;
	SlotMachine(const SlotMachine&) = delete; // copy ctor
	SlotMachine(SlotMachine&&) = delete; // move ctor
	SlotMachine& operator=(const SlotMachine&) = delete; // copy assignment
	SlotMachine& operator=(SlotMachine&&) = delete; // move assignment
	virtual ~SlotMachine() = default;
	void run(int t=10);
};

