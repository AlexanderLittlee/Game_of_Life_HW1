#include <iostream>
#include "Game.h"

int main() {
	uint_fast8_t maxstep = 100;
	game g1(15,30,0.3f);
	while (maxstep>0 && g1.anyAlive())
	{
		g1.Step();
		std::cout <<g1;
		--maxstep;
		std::cin.get();
	}

}