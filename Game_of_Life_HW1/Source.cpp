#include <iostream>
#include "Game.h"
void play(game& game,uint_fast8_t maxstep = 99 )
{
	while (maxstep<0 && game.anyAlive())
	{
		game.Step();
		std::cout <<game;
		--maxstep;
		std::cin.get();
	}
}


int main() 
{
	game g1(15,30,0.25f);
	play(g1);
}