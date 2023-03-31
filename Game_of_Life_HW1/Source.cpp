#include <iostream>
#include "Game.h"
#include <stdlib.h>

void play(game& game,uint_fast8_t maxstep = 99 )
{
	std::cout << game;
	std::cin.get();
	while (maxstep>0 && game.anyAlive())
	{
		system("CLS");
		game.Step();
		std::cout <<game;
		--maxstep;
		std::cin.get();
	}
	system("CLS");
	std::cout << "All cells have died, the Game of Life is OVER!" << std::endl << std::endl;
}

void ctor1Play(const int& sizeA=25) 
{
	game game(sizeA);
	play(game);
}

void ctor2Play(const int& sizeA = 25, const int& sizeB = 45)
{
	game game(sizeA, sizeB);
	play(game);
}

void ctor3Play(const int& sizeA = 25, const float& chance=0.3f)
{
	game game(sizeA, chance);
	play(game);
}


void ctor4Play(const int& sizeA = 25, const int& sizeB = 45, const float& chance = 0.3f)
{
	game game(sizeA, sizeB, chance);
	play(game);
}

void ctor5Play(const int& fullSizeA=25,const int& fullsizeB=40,const int& xstart=2,const int& ystart = 2,const int& sizeA = 20,const int& sizeB=20)
{
	game helper(sizeA,sizeB);
	game game(fullSizeA, fullsizeB, xstart, ystart, helper.getDish());
	play(game);
}

int main() 
{
	//ctor1Play();
	//ctor2Play();
	ctor3Play();
	//ctor4Play();
	//ctor5Play();
}