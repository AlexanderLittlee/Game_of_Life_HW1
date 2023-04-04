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


void ctor2Play(const int& sizeA = 25, const int& sizeB = 90)
{
	game game(sizeA, sizeB);
	play(game);
}


void ctor3Play(const int& sizeA = 25, const float& chance=0.4f)
{
	game game(sizeA, chance);
	play(game);
}


void ctor4Play(const int& sizeA = 25, const int& sizeB = 90, const float& chance = 0.35f)
{
	game game(sizeA, sizeB, chance);
	play(game);
}


void ctor5Play(const int& fullSizeA=25,const int& fullsizeB=90,const int& xstart=4,const int& ystart = 15,const int& sizeA = 20,const int& sizeB=70)
{
	game helper(sizeA,sizeB);
	game game(fullSizeA, fullsizeB, xstart, ystart, helper.getDish());
	play(game);
}



void wellcomeScr() 
{
	std::cout << std::endl << "\t\t\t\t\t\tGreetings!" << std::endl << std::endl << std::endl
		<< "\tThis is the Game of Life, originally created by John Conway at Cambridge University, now" << std::endl
		<< "\timplemented by me (Kiss Sandor) in C++. " << std::endl << std::endl
		<< "\tPress enter to start the first game, which starts by constructing a game the simplest way." << std::endl
		<< "\tTo make a step in the game, you have to press enter again. When the game is over, the next" << std::endl
		<< "\tone, with an increasingly more complicated constructors calling (don't worry, they each " << std::endl
		<< "\thave a pre-definde default value!) will start." << std::endl << std::endl
		<< "\tThere will be 5 games of life, each a bit different from the previous. Stepping from one" << std::endl
		<< "\tgame to the next is also done by pressing enter." << std::endl << std::endl << std::endl
		<< "\tThat is all you need to know, have fun looking at cells living and dying! :)" << std::endl;
	std::cin.get();
	system("CLS");
}



int main() 
{
	wellcomeScr();

	//play with constuctor game(const int& sideA)
	//default
	ctor1Play();
	//example
	//ctor1Play(15);
	std::cin.get();

	//play with constuctor game(const int& sideA, const int& sideB)
	//default
	ctor2Play();
	//example
	//ctor2Play(20,60);
	std::cin.get();

	//play with constuctor game(const int& sideA, const float& Chance)
	//default
	ctor3Play();
	//example
	//ctor3Play(13,0.6f);
	std::cin.get();
	
	//play with constuctor game(const int& sideA, const int& sideB, const float& Chance)
	//default
	ctor4Play();
	//example
	//ctor4Play(14,50,0.7f);
	std::cin.get();
	
	//play with constuctor game(const int& height, const int& width, const int& top, const int& left, const std::vector<std::vector<cell>>&vect)
	//default
	ctor5Play();
	//example
	//ctor5Play(25,70,4,4,19,60);
}